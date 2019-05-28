#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	clear_stdin()
{
	int32_t	c;

	c = 0;
label_getchar:
	c = getchar();
	if (c == 0xa)
		return ;
	else if (c != 0xff)
		goto label_getchar;
	return ;
}

uint32_t get_unum()
{
	uint32_t	val;

	val = 0;
	fflush(stdout);
	scanf("%u", &val);
	clear_stdin();
	return val;
}

int32_t	store_number(int arg_8h)
{
	uint32_t	uval_1;
	uint32_t	uval_2;

	uval_1 = 0;
	uval_2 = 0;

	printf(" Number: ");
	uval_1 = get_unum();

	printf(" Index: ");
	uval_2 = get_unum();

	uint32_t ecx, eax, edx;

	ecx = uval_2;
	edx = 0xaaaaaaab; /* 0b101010101010101 */
	eax = ecx;
	edx = (uint32_t)(((uint64_t)eax * (uint64_t)edx) >> 32);
	edx >>= 1; // edx /= 2
	eax = edx;
	/* eax += eax; */
	/* eax += edx; */
	eax *= 3;
	edx = ecx;
	edx -= eax;
	if (edx != 0) {
		if ((uval_1 >> 0x18) != 0xb7) {
			*(uint32_t*)(uval_2 * 4 + arg_8h) = uval_1;
			return 0;
		}
	}
	puts(" *** ERROR! ***\n");
	puts("   This index is reserved for wil!\n");
	puts(" *** ERROR! ***\n");
	return 0;
}

int32_t	read_number(int arg_8h)
{
	uint32_t	unsigned_val;

	printf(" Index: ");
	unsigned_val = get_unum();
	uint32_t	eax;
	uint32_t	value;

	eax = unsigned_val;
	eax *= 4;
	eax += arg_8h;
	value = *(uint32_t*)eax;

	printf(" Number at data[%u] is %u\n", unsigned_val, value);
	return 0;
}

int main(int argc, char **argv, char **env)
{
	char		**stack_argv; // now
	char		**stack_env; // for now
	uint32_t	local_14h;
	int			buffer[0x64];
	ssize_t		read_ret;
	char		*local_var_0;
	int			local_var_4;
	int			local_var_3;
	int			local_var_2;
	int			local_var_1;

	*(uint32_t*)stack_argv = argv;
	*(uint32_t*)stack_env = env; // maybe swapped
	read_ret = 0;
	local_var_0 = 0;
	local_var_1 = 0;
	local_var_2 = 0;
	local_var_3 = 0;
	local_var_4 = 0;
	for (uint32_t ecx = 0; ecx < 0x64; ecx++) {
		buffer[ecx] = 0;
	}

	while (stack_argv[0]) {
		uint32_t len = 0;

		for (; stack_argv[0][len]; len++)
			;

		memset(stack_argv[0], 0, len);
		stack_argv++;
	}

	while (stack_env[0]) {
		uint32_t len = 0;

		for (; stack_env[0][len]; len++)
			;

		memset(stack_env[0], 0, len);
		stack_env++;
	}

	puts("----------------------------------------------------
  Welcome to wil\'s crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------");
somelabel:
	printf("Input command: ");
	fgets(&local_var_0, 0x14, stdin);

	uint32_t len = 0;

	for (; local_var_0[len]; len++)
		;
	local_var_0[len] = 0; // ???

	len = 0;
	for (; len < 5 && "store"[len] == local_var_0[len]; len++)
		;
	if (len != 5)
	{
		uint32_t	len = 0;

		for (; len < 4 && "read"[len] == local_var_0[len]; len++)
			;
		if (len != 4) {
			uint32_t	len = 0;

			for (; len < 4 && "quit"[len] == local_var_0[len]; len++)
				;

			if (len == 4)
				return (0); //omitted canary checks
			else
				goto three_ways;
		} else {
			read_ret = read_number(buffer);
			goto three_ways;
		}
	} else {
		read_ret = store_number(buffer);
		goto three_ways;
	}
three_ways:

	if (read_ret == 0)
		printf(" Completed %s command successfully\n", &local_var_0); //&?
	else
		printf(" Failed to do %s command\n", &local_var_0);

	local_var_0 = 0;
	local_var_1 = 0;
	local_var_2 = 0;
	local_var_3 = 0;
	local_var_4 = 0;
	goto somelabel;
}
