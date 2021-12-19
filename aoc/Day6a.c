#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	fp = fopen("input_day6.txt", "r");

	if((read = getline(&line, &len, fp)) != -1) {
		printf("%s\n", line);
	}

	return EXIT_SUCCESS;
}