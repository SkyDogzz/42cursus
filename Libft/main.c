/*
* NE PAS PUSH DANS LE REPO
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <bsd/string.h>

#include "libft.h"

#define BUFFER_SIZE 1024

void verif_test_ascii(int start, int end, int(*f)(int c), int(*ft_f)(int c), bool display)
{
	int flag = 0;
	for(int i = start; i <= end; i++)
	{
		if(display)
			printf("%c %d %d %s\n", (char) i, 1 && f(i), ft_f(i), (1 && f(i)) == ft_f(i) ? "true" : "false");
		else if ((1 && f(i)) != ft_f(i)) 
			flag++;
	}
	if(!display){
		if(!flag)
			printf("Tests between %c/%d and %c/%d: True\n", start, start, end, end);
		else 
			printf("Tests between %c/%d and %c/%d: False\n", start, start, end, end);
	}
}

void verif_test_ascii_to(int start, int end, int (*f)(int c), int(*ft_f)(int c), bool display)
{
	int flag = 0;
	for (int i = start; i < end; i++)
	{
		if(display)
			printf("%c %d %d %s\n", i, f(i), ft_f(i), f(i) == ft_f(i) ? "true" : "false");	
		else if (f(i) != ft_f(i)) 
			flag++;
	}
	if(!display){
		if(!flag)
			printf("Tests between %c/%d and %c/%d: True\n", start, start, end, end);
		else 
			printf("Tests between %c/%d and %c/%d: False\n", start, start, end, end);
	}
}

void	verif_test_str_match(char *s, size_t (*f)(const char *s),size_t (*f_ft)(const char *s))
{
	int f1, f2;
	f1 = f(s);
	f2 = f_ft(s);
	if (f1 == f2)
		printf("Both return %d: True\n", f1);
	else {
		printf("Original return %d\n", f1);
		printf("Copy return %d\n", f2);
		printf("False\n");
	}
}

void	verif_test_str_match_c(char *s, char c, char *(*f)(const char *s, int c), char *(*f_ft)(const char *s, int c))
{
	char *p1, *p2;
	p1 = f(s, c);
	p2 = f_ft(s, c);
	if (p1 == p2)
		printf("Both return %s: True\n", p1);
	else {
		printf("Original return %s\n", p1);
		printf("Copy return %s\n", p2);
		printf("False\n");
	}
}

void verif_test_2str_size_match(char *s1, char *s2, size_t n, int (*f)(const char *s1, const char *s2, size_t n), int (*ft_f)(const char *s1, const char *s2, size_t n))
{
	int f1, f2;
	f1 = f(s1, s2, n);
	f2 = ft_f(s1, s2, n);
	if (f1 == f2)
		printf("Both return %d: True\n", f1);
	else {
		printf("Original return %d\n", f1);
		printf("Copy return %d\n", f2);
		printf("False\n");
	}

}

void verif_test_2str_size_match_s(char *s1, char *s2, size_t n, size_t (*f)(char *s1, const char *s2, size_t n), size_t (*ft_f)(char *s1, const char *s2, size_t n))
{
	int f1, f2;
	char *scpy;

	scpy = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	strcpy(scpy, s1);
	f1 = f(s1, s2, n);
	f2 = ft_f(scpy, s2, n);
	if (f1 == f2)
		printf("Both return %d: True\n", f1);
	else {
		printf("Original return %d\n", f1);
		printf("Copy return %d\n", f2);
		printf("False\n");
	}

}

void verif_test_strnstr(char *big, char *little, size_t n, char *(*f)(const char *big, const char *little, size_t n), char *(*ft_f)(const char *big, const char *little, size_t n)){
	char *f1, *f2;
	
	f1 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	f2 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	f1 = f(big, little, n);
	f2 = ft_f(big, little, n);
	if ((f1 && f2 && strcmp(f1, f2) == 0) || (!f1 && !f2))
		printf("Both return %s: True\n", f1);
	else {
		printf("Original return %s\n", f1);
		printf("Copy return %s\n", f2);
		printf("False\n");
	}
}

void	verif_test_atoi(char *s, int (*f)(const char *), int (*ft_f)(const char *))
{
	int f1, f2;
	f1 = f(s);
	f2 = ft_f(s);
	if (f1 == f2)
		printf("Both return %d: True\n", f1);
	else {
		printf("Original return %d\n", f1);
		printf("Copy return %d\n", f2);
		printf("False\n");
	}
}

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	/*
	* Test char related functions
	*/
	printf("FT_ISALPHA\n");
	verif_test_ascii('a' - 1, 'z' + 1, &isalpha, &ft_isalpha, false);
	verif_test_ascii('A' - 1, 'Z' + 1, &isalpha, &ft_isalpha, false);

	printf("FT_ISDIGIT\n");
	verif_test_ascii('0' - 2, '9' + 2, &isdigit, &ft_isdigit, false);

	printf("FT_ISALNUM\n");
	verif_test_ascii('0' - 2, '9' + 2, &isdigit, &ft_isdigit, false);
	verif_test_ascii('a' - 1, 'z' + 1, &isalpha, &ft_isalpha, false);
	verif_test_ascii('A' - 1, 'Z' + 1, &isalpha, &ft_isalpha, false);

	printf("FT_ISASCII\n");
	verif_test_ascii(0, 127, &isascii, &ft_isascii, false);
	verif_test_ascii(-128 , 256, &isascii, &ft_isascii, false);

	printf("FT_ISPRINT\n");
	verif_test_ascii(0 , 127, &isprint, &ft_isprint, false);
	verif_test_ascii(-128 , 256, &isprint, &ft_isprint, false);

	printf("FT_TOLOWER\n");
	verif_test_ascii_to(0 , 127, &tolower, &ft_tolower, false);

	printf("FT_TOUPPER\n");
	verif_test_ascii_to(0 , 127, &toupper, &ft_toupper, false);

	/*
	* Test char related functions
	*/
	printf("\n\n");
	int n;
	char match;
	char *test, *test2;

	test = (char *)malloc(sizeof(char)*BUFFER_SIZE);
	test2 = (char *)malloc(sizeof(char)*BUFFER_SIZE);

	printf("FT_STRLEN\n");
	strcpy(test, "Hello world!");
	verif_test_str_match(test, &strlen, &ft_strlen);
	strcpy(test, "LIBFT tests gonna make me crazy");
	verif_test_str_match(test, &strlen, &ft_strlen);
	strcpy(test, "test with \0 here");
	verif_test_str_match(test, &strlen, &ft_strlen);

	printf("FT_STRCHR\n");
	strcpy(test, "Hello world!");
	match = 'l';
	verif_test_str_match_c(test, match, &strchr, &ft_strchr);
	strcpy(test, "LIBFT tests gonna make me crazy");
	match = 'e';
	verif_test_str_match_c(test, match, &strchr, &ft_strchr);

	printf("FT_STRRCHR\n");
	strcpy(test, "Hello world!");
	match = 'l';
	verif_test_str_match_c(test, match, &strrchr, &ft_strrchr);
	strcpy(test, "LIBFT tests gonna make me crazy");
	match = 'e';
	verif_test_str_match_c(test, match, &strrchr, &ft_strrchr);

	printf("FT_STRNCMP\n");
	strcpy(test, "Hello world");
	strcpy(test2, test);
	n = strlen(test);
	verif_test_2str_size_match(test, test2, n, &strncmp, &ft_strncmp);
	verif_test_2str_size_match(test, test2, n + 10, &strncmp, &ft_strncmp);
	strcpy(test, "Hello worl");
	n = strlen(test2);
	verif_test_2str_size_match(test, test2, n, &strncmp, &ft_strncmp);
	verif_test_2str_size_match(test2, test, n, &strncmp, &ft_strncmp);

	printf("FT_STRLCPY\n");
	strcpy(test, "");
	strcpy(test2, "Hello");
	verif_test_2str_size_match_s(test, test2, n, &strlcpy, &ft_strlcpy);
	test = realloc(test, sizeof(char)*3);
	verif_test_2str_size_match_s(test, test2, n, &strlcpy, &ft_strlcpy);

	printf("FT_STRLCAT\n");
	strcpy(test, "");
	strcpy(test2, "World");
	test = realloc(test, sizeof(char)*BUFFER_SIZE);
	verif_test_2str_size_match_s(test, test2, n, &strlcat, &ft_strlcat);
	strcpy(test, "");
	test = realloc(test, sizeof(char)*3);
	verif_test_2str_size_match_s(test, test2, n, &strlcat, &ft_strlcat);

	printf("FT_STRNSTR\n");
	char big[] = "Here is a big one";
	char little[] = "one";
	verif_test_strnstr(big, little, strlen(big) + 10, &strnstr, &ft_strnstr);
	verif_test_strnstr(big, little, strlen(big) + 1, &strnstr, &ft_strnstr);
	verif_test_strnstr(big, little, strlen(big), &strnstr, &ft_strnstr);
	verif_test_strnstr(big, little, strlen(big) - 1, &strnstr, &ft_strnstr);

	printf("FT_ATOI\n");
	verif_test_atoi("-2147483648", &atoi, &ft_atoi);
	verif_test_atoi("2147483647", &atoi, &ft_atoi);
	verif_test_atoi("-2147483649", &atoi, &ft_atoi);
	verif_test_atoi("-42", &atoi, &ft_atoi);
	verif_test_atoi("0", &atoi, &ft_atoi);
	verif_test_atoi("42", &atoi, &ft_atoi);

	return EXIT_SUCCESS;
}
