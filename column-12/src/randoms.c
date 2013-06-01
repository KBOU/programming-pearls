#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long long bigrand() {
	return (rand() << 16) + rand();
}

int randint(int l, int u) {
	return rand() %(u-l) + l;
}
int main(int argc, char *argv[]) {
	srand(time(NULL));

	return 0;
}
