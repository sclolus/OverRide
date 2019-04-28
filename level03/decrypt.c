#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv) {
	uint32_t base_input = 18;


	while (base_input) {
		if (0x1337d00d - base_input < 0x15) {
			printf("%x\n", base_input);
		}
		/* base_input = base_input << 2 + 0x80489f0; */
		/* char *key = strdup("Q}|u`sfg~sf{}|a3"); */

		/* uint32_t i = 0; */
		/* uint32_t len = strlen(key); */
		/* while (i < len) { */
		/* 	uint8_t byte = key[i] ^ base_input; */
		/* 	key[i] = byte; */
		/* 	i++; */
		/* } */
		/* if (strcmp(key, "Congratulations!") == 0) { */
		/* 	printf("%x\n", base_input); */
		/* 	/\* return (0); *\/ */
		/* } else { */
		/* 	/\* printf("%s\n", key); *\/ */
		/* } */
		/* free(key); */
		/* base_input ++; */
		base_input += 256;
	}
	return (0);
}
