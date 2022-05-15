#include <stdio.h>
#include <time.h>
#include <stdlib.h>

size_t fib(size_t n) {
	if(n < 3) {
		return 1;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}

int main(int argc, char const *argv[]) {
	size_t param = strtoul(argv[1], NULL, 10);
	printf("Provided limit: %zu\n", param);
	printf("Recursion starts\n\n");
	clock_t start = clock();
	printf("%zu\n", fib(param));
	clock_t end = clock();

	float diff = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken : %fs\n", diff);
	return 0;
}
