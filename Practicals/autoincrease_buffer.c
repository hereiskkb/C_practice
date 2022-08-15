/*
	Goal: To read input from a file until new line or end-of-file is encountered. 
	The buffer shall adapt to increasing line lengths such that the entire text can be read without any loss. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("input.csv", "r");
	if(fp == NULL) {
		printf("!! Failed to read file !!\n");
		exit(EXIT_FAILURE);
	}

	while((read = getline(&line, &len, fp)) != -1) {
		printf("Line: %s", line);
	}
	return 0;
}