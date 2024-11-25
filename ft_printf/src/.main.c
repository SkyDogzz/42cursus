/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:19:37 by tstephan          #+#    #+#             */
/*   Updated: 2024/11/24 20:19:15 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define TEST_BUFFER_SIZE 1024

// Fonction pour rediriger stdout vers un pipe
int redirect_stdout(int *saved_stdout_fd) {
    int pipe_fd[2];
    if (pipe(pipe_fd) != 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    *saved_stdout_fd = dup(STDOUT_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]);
    return pipe_fd[0]; // Retourne l'extrémité de lecture du pipe
}

// Fonction pour restaurer stdout
void restore_stdout(int saved_stdout_fd) {
    fflush(stdout);
    dup2(saved_stdout_fd, STDOUT_FILENO);
    close(saved_stdout_fd);
}

// Fonction pour lire depuis un descripteur de fichier
ssize_t read_from_fd(int fd, char *buffer, size_t size) {
    ssize_t n = read(fd, buffer, size - 1);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    close(fd);
    return n;
}

void TEST_PRINTF(const char *format, ...)                                           
    {                                                                   
        char buffer_printf[TEST_BUFFER_SIZE];                              
        char buffer_ft_printf[TEST_BUFFER_SIZE];                           
        int ret_printf, ret_ft_printf;                                     
                                                                           
        /* Capturer la sortie de printf */           
		va
        ret_printf = snprintf(buffer_printf, sizeof(buffer_printf), format, ...); 
                                                                           
        /* Rediriger stdout pour ft_printf */                              
        int saved_stdout_fd;                                               
        int pipe_fd = redirect_stdout(&saved_stdout_fd);                   
                                                                           
        /* Appeler ft_printf */                                            
        ret_ft_printf = ft_printf(format, __VA_ARGS__);                  
                                                                           
        /* Restaurer stdout */                                             
        restore_stdout(saved_stdout_fd);                                   
                                                                          
        /* Lire la sortie de ft_printf */                                  
        read_from_fd(pipe_fd, buffer_ft_printf, sizeof(buffer_ft_printf)); 
                                                                           
        /* Comparer les résultats */                                       
        if (ret_printf != ret_ft_printf || strcmp(buffer_printf, buffer_ft_printf) != 0) { 
            printf("Test échoué pour le format: \"%s\"\n", format);        
            printf("printf     renvoie %d et imprime: %s\n", ret_printf, buffer_printf); 
            printf("ft_printf  renvoie %d et imprime: %s\n", ret_ft_printf, buffer_ft_printf); 
        } else {                                                           
            printf("Test réussi pour le format: \"%s\"", format);        } 
    }

int main(void)
{
    // Tests avec les spécificateurs de base
    TEST_PRINTF("Nombre entier: %d\n", 42);
    TEST_PRINTF("Caractère: %c\n", 'A');
    TEST_PRINTF("Chaine: %s\n", "Bonjour");
    TEST_PRINTF("Pointeur: %p\n", main);
    TEST_PRINTF("Pourcentage: %%\n"); // Correction appliquée ici
    TEST_PRINTF("Nombre négatif: %d\n", -123);
    TEST_PRINTF("Hexadécimal minuscule: %x\n", 255);
    TEST_PRINTF("Hexadécimal majuscule: %X\n", 255);
    TEST_PRINTF("Unsigned: %u\n", 3000000000U);
    TEST_PRINTF("Mixte: %d, %s, %c, %p\n", 7, "test", 'Z', &errno);

    return 0;
}

