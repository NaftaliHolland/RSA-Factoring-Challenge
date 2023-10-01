#include <stdio.h>
#include "factors.h"
#include <stdlib.h>
#include <stdint.h>
/**
 * get_factors - gets the factors of a number
 *
 * @number: the number to get the factors
 *
 * Return: an array containing the two factors of number
 *
 */

long long int *get_factors(long long int number)
{
	long long int i, j, *factors;

	factors = malloc(sizeof(int) * 2);
	if (factors == NULL)
	{
		fprintf(stderr, "Failed to malloc\n");
		exit(EXIT_FAILURE);
	}

	for (i = 9; i >= 1; i--)
	{
		for (j = number / 2; j >= 2; j /= 2)
		{
			if ((i * j) == number)
			{
				factors[0] = j;
				factors[1] = i;

				return (factors);
			}
		}
	}
}
