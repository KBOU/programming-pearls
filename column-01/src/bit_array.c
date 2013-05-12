#include <stdio.h>

#define NUM 10000000
#define BITS_PER_ELEM 32
int bit_array[NUM / BITS_PER_ELEM + 1] = {0};
void set_bit(int i) {
	bit_array[i/BITS_PER_ELEM] |= (1 << (i % BITS_PER_ELEM));
}

int main(int argc, char *argv[]) {
	int inp1, inp2;
	int i, j;
	scanf("%d %d", &inp1, &inp2);

	set_bit(inp1);
	set_bit(inp2);

	for (i = 0; i < 10; i++) {
		printf("%d", bit_array[i]);
		printf("\n");
	}
	return 0;
}
