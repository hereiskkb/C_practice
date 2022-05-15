#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[argc]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t increaseCount = 0;
	size_t prevValue = -1;
	size_t curValue = -1;

	fp = fopen("input.txt", "r");
	
	if(fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while((read = getline(&line, &len, fp)) != -1) {
		curValue = strtoul(line, NULL, 10);
		if(prevValue == -1) {
			printf("%zu (N/A - no previous measurement)\n", curValue);
		} else if(curValue > prevValue) {
			printf("%zu (increased)\n", curValue);
			increaseCount++;
		} else {
			printf("%zu (decreased)\n", curValue);
		}

		prevValue = curValue;
	}

	printf("Increased count: %zu\n", increaseCount);

	fclose(fp);

	if(line) {
		free(line);
	}
	return 0;
}