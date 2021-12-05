#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[argc]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	char *dir, *unit;
	size_t horizontal = 0;
	int depth = 0;
	size_t mag;
	int aim = 0;

	fp = fopen("input_day2.txt", "r");
	
	if(fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while((read = getline(&line, &len, fp)) != -1) {
		dir = strtok(line, " ");
		unit = strtok(NULL, " ");
		mag = strtoul(unit, NULL, 10);
		if(strcmp(dir, "forward") == 0) {
			horizontal += mag;
			depth += (aim * mag);
		} else if(strcmp(dir, "up") == 0) {
			aim -= mag;
		} else {
			aim += mag;
		}
	}

	printf("%zu\n", horizontal);
	printf("%d\n", depth);
	printf("%ld\n", (horizontal * depth));

	fclose(fp);

	if(line) {
		free(line);
	}
	return 0;
}