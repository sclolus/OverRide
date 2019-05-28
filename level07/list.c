#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int	main(void)
{
	int32_t	i = 0;

	while (i <= 256) {
		uint32_t ecx, eax, edx;

		ecx = i;
		edx = 0xaaaaaaab; /* 0b101010101010101 */
		eax = ecx;
		edx = (uint32_t)(((uint64_t)eax * (uint64_t)edx) >> 32);
		edx >>= 1; // edx /= 2
		eax = edx;
		eax += eax;
		eax += edx;
		/* eax *= 3; */
		edx = ecx;
		edx -= eax;
		if (edx != 0) {
			printf("store\n%d\n%d\n", 0xAAAAAAAA, i);
		}
		i++;
	}
	printf("quit\n");
}
