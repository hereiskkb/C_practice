#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[argc]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t zeroCounter[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t oneCounter[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	fp = fopen("input_day3.txt", "r");
	
	if(fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while((read = getline(&line, &len, fp)) != -1) {
		for(size_t i = 0; i < 12; i++) {
			if(line[i] == '0') {
				zeroCounter[i]++;
			} else {
				oneCounter[i]++;
			}
		}
	}


	for(size_t i = 0; i < 12; i++) {
		if(oneCounter[i] > zeroCounter[i]) {
			printf("1");
		} else {
			printf("0");
		}
	}


	fclose(fp);

	if(line) {
		free(line);
	}
	return 0;
}