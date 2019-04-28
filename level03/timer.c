#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(void) {
	while (1) {
	time_t value = time(NULL);
	srand(value);
	int ret = rand();
	if ((unsigned int)ret % 256 == 18)
	{
		printf("Now\n");
	}	
	printf("%x\n", (unsigned int)ret);
}
}
