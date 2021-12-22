#include <stdio.h>
#include <stdlib.h>

void get_numbers(char *line, size_t **number_list, size_t *number_list_size) {
	char *number_string = strtok(line, ",");
	while(number_string) {
		(*number_list_size)++;
		(*number_list) = (size_t *) realloc((*number_list), (((*number_list_size) + 1) * sizeof(size_t)));
		(*number_list)[(*number_list_size) - 1]  = strtoul(number_string, NULL, 10);
		printf("Input : %zu\n", (*number_list)[(*number_list_size) - 1]);
	}
}

void get_mode(size_t *number_list, size_t number_list, size_t **mode_list, size_t *mode_list_size) {
		
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t *mode_list = NULL;
	size_t mode_list_size = 0;
	size_t *number_list = NULL;
	size_t number_list_size = 0;

	fp = fopen("input_day7.txt", "r");

	if((read = getline(&line, &len, fp)) != -1) {
		get_numbers(line, &number_list_size);
		get_mode(number_list, number_list_size, &mode_list, &mode_list_size);
		find_least_cost(number_list, number_list_size, mode_list, mode_list_size);
	}

	fclose(fp);
	return EXIT_SUCCESS;
}