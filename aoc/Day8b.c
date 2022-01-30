#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_numbers(char *line) {
	char *source = strtok(line, "|");
	char *target = strtok(NULL, "|");

	char *number_div[10] = (char **) malloc(10, sizeof(char *));

	

}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t sum = 0;

	fp = fopen("input_day8.txt", "r");
	while((read = getline(&line, &len, fp)) != -1) {
		sum += get_numbers(line);
	}

	printf("Count : %zu\n", count);

	fclose(fp);
	return 0;
}