/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:19:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/22 18:22:31 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *capture_output(int (*func)(const char *, ...), const char *format, ...) {
    FILE *tmp = tmpfile();
    if (!tmp) {
        perror("tmpfile");
        return NULL;
    }

    int stdout_fd = dup(fileno(stdout));
    if (stdout_fd == -1) {
        perror("dup");
        fclose(tmp);
        return NULL;
    }

    if (dup2(fileno(tmp), fileno(stdout)) == -1) {
        perror("dup2");
        fclose(tmp);
        close(stdout_fd);
        return NULL;
    }

    va_list args;
    va_start(args, format);
    func(format, args);
    va_end(args);

    fflush(stdout);
    if (dup2(stdout_fd, fileno(stdout)) == -1) {
        perror("dup2 restore");
        fclose(tmp);
        close(stdout_fd);
        return NULL;
    }
    close(stdout_fd);

    fseek(tmp, 0, SEEK_END);
    long size = ftell(tmp);
    rewind(tmp);

    char *output = malloc(size + 1);
    if (!output) {
        perror("malloc");
        fclose(tmp);
        return NULL;
    }

    fread(output, 1, size, tmp);
    output[size] = '\0';

    fclose(tmp);
    return output;
}

void test_printf(const char *description, const char *format, ...) {
    va_list args1, args2;
    va_start(args1, format);
    va_start(args2, format);

    char *output_std = capture_output(printf, format, args1);
    char *output_ft = capture_output(ft_printf, format, args2);

    va_end(args1);
    va_end(args2);

    if (!output_std || !output_ft) {
        printf("[ERROR] Could not capture output for %s\n", description);
        free(output_std);
        free(output_ft);
        return;
    }

    if (strcmp(output_std, output_ft) != 0) {
        printf("[FAIL] %s\n", description);
        printf("  Expected: \"%s\"\n", output_std);
        printf("  Got     : \"%s\"\n", output_ft);
    } else {
        printf("[PASS] %s\n", description);
    }
	fflush(stdout);
    free(output_std);
    free(output_ft);
}

int main() {
    test_printf("Basic string", "Hello, %s!", "world");
    test_printf("Integer formatting", "Number: %d", 42);
    test_printf("Hexadecimal", "Hex: %#x", 255);

    test_printf("Empty string", "%s", "");
    test_printf("Zero integer", "%d", 0);
    test_printf("Large integer", "%d", 9223372036854775807LL);
    test_printf("Null pointer", "%p", NULL);

    return 0;
}

