/*
* NE PAS PUSH DANS LE REPO
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

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

int main(int argc, char *argv[])
{
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

	return EXIT_SUCCESS;
}
