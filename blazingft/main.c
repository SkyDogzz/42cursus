#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include "include/libft.h"

int	main(void)
{
	clock_t t; 
	double	time_taken;

    t = clock(); 
	for(int i = 0; i < 1000000000; i++)
		ft_isdigit(255);
    t = clock() - t; 
    time_taken = ((double)t)/(CLOCKS_PER_SEC / 1000);
	printf("isdigit took %.3f\n", time_taken);
	t = clock(); 
	for(long i = 0; i < 10000000000000000; i++)
		isdigit('9');
    t = clock() - t; 
    time_taken = ((double)t);
	printf("isdigit took %.3f\n", time_taken);
}
