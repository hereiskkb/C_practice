#include <stdio.h>

int main(int argc, char const *argv[]) {
	int a[10][10];
	size_t height = (sizeof a) / (sizeof a[0]);
	size_t breadth = (sizeof a[0]) / (sizeof a[0][0]);
	printf("height: %lu\n", height);
	printf("breadth: %lu\n", breadth);
	return 0;
}