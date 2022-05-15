#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_occurrances(char *line) {
	char *split = strtok(line, "|");
	split = strtok(NULL, "|");

	char *matcher = strtok((split + 1), " ");
	size_t occurances = 0;
	while(matcher != NULL) {
		size_t len = strlen(matcher);
		len  = (matcher[len - 1] == '\n') ? (len - 1) : len;
		if((len == 2 || len == 3 || len == 4 || len == 7)) {
			printf("Found matching token : %s\n", matcher);
			occurances += 1;
		}

		matcher = strtok(NULL, " ");
	}

	return occurances;
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t count = 0;

	fp = fopen("input_day8.txt", "r");
	while((read = getline(&line, &len, fp)) != -1) {
		count += get_occurrances(line);
	}

	printf("Count : %zu\n", count);

	fclose(fp);
	return 0;
}