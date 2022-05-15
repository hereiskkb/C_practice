#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

/*
	Non hash table code
*/

typedef struct num_freq {
	size_t number;
	size_t frequency;
} NUM_FREQ;

void get_numbers(char *line, size_t **number_list, size_t *number_list_size) {
	
	printf("get_numbers\n");
	char *number_string = strtok(line, ",");
	while(number_string) {
		(*number_list_size)++;
		(*number_list) = (size_t *) realloc((*number_list), (((*number_list_size) + 1) * sizeof(size_t)));
		(*number_list)[(*number_list_size) - 1]  = strtoul(number_string, NULL, 10);
		number_string = strtok(NULL, ",");
	}
}

int search_index(NUM_FREQ *freq_list, size_t freq_list_size, size_t element) {
	
	printf("search_index for element : %zu\n", element);
	for(size_t i = 0; i < freq_list_size; i++) {
		if(freq_list[i].number == element) {
			return i;
		}
	}

	return -1;
}

void get_mode(size_t *number_list, size_t number_list_size, size_t **mode_list, size_t *mode_list_size) {
	
	printf("get_mode\n");
	int found_index;
	NUM_FREQ *freq_list = NULL;
	size_t freq_list_size = 0;
	for(size_t i = 0; i < number_list_size; i++) {
		found_index = search_index(freq_list, freq_list_size, number_list[i]);
		if(found_index != -1) {
			freq_list[found_index].frequency++;
		} else {
			freq_list_size++;
			freq_list = (NUM_FREQ *) realloc(freq_list, (freq_list_size + 1) * sizeof(NUM_FREQ));
			freq_list[freq_list_size - 1].number = number_list[i];
			freq_list[freq_list_size - 1].frequency = 1;
		}
	}

	printf("\nFrequency chart :\n");
	for(size_t i = 0; i < freq_list_size; i++) {
		printf("%zu >>\t%zu\n", freq_list[i].number, freq_list[i].frequency);
	}

	(*mode_list_size)++;
	(*mode_list) = (size_t *) realloc((*mode_list), (((*mode_list_size) + 1) * sizeof(size_t)));
	(*mode_list)[(*mode_list_size) - 1] = freq_list[0].number;
	size_t temp = freq_list[0].frequency;
	for(size_t i = 1; i < freq_list_size; i++) {
		if(freq_list[i].frequency > temp) {
			free(*mode_list);
			(*mode_list) = NULL;
			(*mode_list_size) = 1;
			(*mode_list) = (size_t *) realloc((*mode_list), (((*mode_list_size) + 1) * sizeof(size_t)));
			(*mode_list)[(*mode_list_size) - 1] = freq_list[i].number;
			temp = freq_list[i].frequency;
		} else if(freq_list[i].frequency == temp) {
			(*mode_list_size)++;
			(*mode_list) = (size_t *) realloc((*mode_list), (((*mode_list_size) + 1) * sizeof(size_t)));
			(*mode_list)[(*mode_list_size) - 1] = freq_list[i].number;
		} else {}
	}

	free(freq_list);
}

void find_least_cost(size_t *number_list, size_t number_list_size, size_t *mode_list, size_t mode_list_size) {

	printf("find_least_cost\n");
	size_t cost = UINT_MAX;

	for(size_t i = 0; i < mode_list_size; i++) {
		size_t temp_cost = 0;
		for(size_t j = 0; j < number_list_size; j++) {
			temp_cost += abs(number_list[j] - mode_list[i]);
		}

		if(temp_cost < cost) {
			cost = temp_cost;
		}
	}

	printf("Min cost : %zu\n", cost);
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
		get_numbers(line, &number_list, &number_list_size);
		get_mode(number_list, number_list_size, &mode_list, &mode_list_size);
		find_least_cost(number_list, number_list_size, mode_list, mode_list_size);
	}

	fclose(fp);
	free(number_list);
	free(mode_list);
	return EXIT_SUCCESS;
}