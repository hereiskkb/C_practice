#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[argc]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t increaseCount = 0;
	size_t firstVal = -1;
	size_t secVal = -1;
	size_t thirdVal = -1;

	size_t prevSum = -1;
	size_t curSum = -1;

	fp = fopen("input.txt", "r");
	
	if(fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while((read = getline(&line, &len, fp)) != -1) {
		thirdVal = strtoul(line, NULL, 10);
		if(secVal == -1) {
			secVal = thirdVal;
		} else if(firstVal == -1) {
			firstVal = secVal;
			secVal = thirdVal;
		} else {
			curSum = firstVal + secVal + thirdVal;
			firstVal = secVal;
			secVal = thirdVal;
			if(prevSum == -1) {
				printf("%zu (N/A - no previous measurement)\n", curSum);
			} else if(curSum > prevSum) {
				printf("%zu (increased)\n", curSum);
				increaseCount++;
			}  else if(curSum < prevSum) {
				printf("%zu (decreased)\n", curSum);
			} else {
				printf("%zu (no change)\n", curSum);
			}
			prevSum = curSum;
		}
	}

	printf("Increased count: %zu\n", increaseCount);

	fclose(fp);

	if(line) {
		free(line);
	}
	return 0;
}