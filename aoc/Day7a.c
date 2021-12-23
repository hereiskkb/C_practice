#include <stdio.h>
#include <stdlib.h>

/*
	Non hash table code
*/

void get_numbers(char *line, size_t **number_list, size_t *number_list_size) {
	
	char *number_string = strtok(line, ",");
	while(number_string) {
		(*number_list_size)++;
		(*number_list) = (size_t *) realloc((*number_list), (((*number_list_size) + 1) * sizeof(size_t)));
		(*number_list)[(*number_list_size) - 1]  = strtoul(number_string, NULL, 10);
	}
}

int search_index(size_t *mode_list, size_t mode_list_size, size_t element) {
	
	for(size_t i = 0; i < mode_list_size; i++) {
		if(mode_list[i] == element) {
			return i;
		}
	}

	return -1;
}

void get_mode(size_t *number_list, size_t number_list, size_t **mode_list, size_t *mode_list_size) {
	
	int found_index;
	size_t *freq_list = NULL;
	size_t freq_list_size = 0;
	for(size_t i = 0; i < number_list_size; i++) {
		found_index = search_index(freq_list, freq_list_size, number_list[i]);
		if(found_index != -1) {
			freq_list[found_index]++;
		} else {
			freq_list_size++;
			freq_list = (size_t *) realloc(freq_list, (freq_list_size + 1) * sizeof(size_t));
			freq_list[freq_list_size - 1] = number_list[i];
		}
	}

	size_t temp = freq_list[0];
	for(size_t i = 0; i < freq_list_size; i++) {
		
	}
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