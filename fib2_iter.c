#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fib2iter(size_t n, size_t buf[2]) {
	size_t res = 0;
	for(size_t i = n; i > 2; i--) {
		res = buf[1] + buf[0];
		buf[1] = buf[0];
		buf[0] = res;
	}
}

size_t fib2(size_t n) {
	size_t res[2] = {1, 1};
	fib2iter(n, res);
	return res[0];
}

int main(int argc, char const *argv[]) {
	
	size_t param = strtoul(argv[1], NULL, 10);
	printf("Provided limit: %zu\n", param);
	printf("Recursion starts\n\n");
	clock_t start = clock();
	printf("%zu\n", fib2(param));
	clock_t end = clock();

	float diff = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken : %fs\n", diff);


	return 0;
}