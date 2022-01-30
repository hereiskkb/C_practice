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

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	size_t *number_list = NULL;
	size_t number_list_size = 0;

	fp = fopen("input_day7.txt", "r");

	if((read = getline(&line, &len, fp)) != -1) {
		get_numbers(line, &number_list, &number_list_size);
	}

	size_t record = UINT_MAX;

	for(size_t i = 0; i < 1000; i++) {
		size_t sum = 0;
		for(size_t j = 0; j < number_list_size; j++) {
			size_t progression_limit = abs(i - number_list[j]);
			size_t limit_sum = (progression_limit * (progression_limit + 1)) / 2;  
			sum += limit_sum;
		}

		if(sum < record) {
			record = sum;
		}
	}

	printf("Record : %zu\n", record);
	

	fclose(fp);
	free(number_list);
	return EXIT_SUCCESS;
}