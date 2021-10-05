#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	
	char a[4] = {'a','b','c','d'};
	char b[4] = {'a','b','c','d'};
	printf("%d\n", strcmp(a, b));
	return 0;
}