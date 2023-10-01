#include "factors.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
 * main - entry point
 *
 * @argc: number of arguments
 * @argv: pointer to an array of strings passed as arguments
 *
 * Return: 0 on success 1 on failure
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line;
	size_t n;
	long long int number, *factors;
	int bytes_read;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = NULL;
	n = 0;
	while ((bytes_read = getline(&line, &n, file)) > 0)
	{

		number = strtoull(line, NULL, 10);
		factors = get_factors(number);
		printf("%lld=%lld*%lld\n", number, factors[0], factors[1]);
	}

	return (0);
}
