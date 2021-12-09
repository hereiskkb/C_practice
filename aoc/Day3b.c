#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 13

void free_all_pointers(size_t input_array_size, char *input_container[]) {
	for(size_t i = 0; i < input_array_size; i++) {
		free(input_container[i]);
	}

	free(input_container);
}

char *get_O2_generator_rating(size_t input_array_size, size_t index, char *input_container[input_array_size]) {

	if(input_array_size == 1) {
		return input_container[0];
	}

	char **array_of_one = NULL;
	char **array_of_zero = NULL;

	size_t one_count = 0;
	size_t zero_count = 0;
	char * return_val = (char *) malloc(STRLEN * sizeof(char));
	if(return_val == NULL) {
		printf("return_val malloc issue!!\n");
		exit(EXIT_FAILURE);
	}

	for(size_t i = 0; i < input_array_size; i++) {
		if(input_container[i][index] == '1') {
			one_count++;
			array_of_one = (char **) realloc(array_of_one, (one_count * sizeof(char *)));
			if(array_of_one == NULL) {
				printf("array_of_one realloc issue!!\n");
				exit(EXIT_FAILURE);
			}
			array_of_one[one_count - 1] = (char *) malloc( STRLEN * sizeof(char));
			if(array_of_one[one_count - 1] == NULL) {
				printf("array_of_one[%zu] malloc issue!!\n", (one_count - 1));
				exit(EXIT_FAILURE);
			}
			strcpy(array_of_one[one_count - 1], input_container[i]);
		} else {
			zero_count++;
			array_of_zero = (char **) realloc(array_of_zero, (zero_count * sizeof(char *)));
			if(array_of_zero == NULL) {
				printf("array_of_zero realloc issue!!\n");
				exit(EXIT_FAILURE);
			}
			array_of_zero[zero_count - 1] = (char *) malloc(STRLEN * sizeof(char));
			if(array_of_zero[zero_count - 1] == NULL) {
				printf("array_of_zero[%zu] malloc issue!!\n", (zero_count - 1));
				exit(EXIT_FAILURE);
			}
			strcpy(array_of_zero[zero_count - 1], input_container[i]);
		}
	}

	if((one_count > zero_count) || (one_count == zero_count)) {
		free_all_pointers(zero_count, array_of_zero);
		strcpy(return_val, get_O2_generator_rating(one_count, (index + 1), array_of_one));
		free_all_pointers(one_count, array_of_one);
		return return_val;
	} else {
		free_all_pointers(one_count, array_of_one);
		strcpy(return_val, get_O2_generator_rating(zero_count, (index + 1), array_of_zero));
		free_all_pointers(zero_count, array_of_zero);
		return return_val;
	}
}

char *get_CO2_scrubber_rating(size_t input_array_size, size_t index, char *input_container[input_array_size]) {

	if(input_array_size == 1) {
		return input_container[0];
	}

	char **array_of_one = NULL;
	char **array_of_zero = NULL;

	size_t one_count = 0;
	size_t zero_count = 0;
	char * return_val = (char *) malloc(13 * sizeof(char));
	if(return_val == NULL) {
		printf("return_val malloc issue!!\n");
		exit(EXIT_FAILURE);
	}

	for(size_t i = 0; i < input_array_size; i++) {
		if(input_container[i][index] == '1') {
			one_count++;
			array_of_one = (char **) realloc(array_of_one, (one_count * sizeof(char *)));
			if(array_of_one == NULL) {
				printf("array_of_one realloc issue!!\n");
				exit(EXIT_FAILURE);
			}
			array_of_one[one_count - 1] = (char *) malloc(STRLEN * sizeof(char));
			if(array_of_one[one_count - 1] == NULL) {
				printf("array_of_one[%zu] malloc issue!!\n", (one_count - 1));
				exit(EXIT_FAILURE);
			}
			strcpy(array_of_one[one_count - 1], input_container[i]);
		} else {
			zero_count++;
			array_of_zero = (char **) realloc(array_of_zero, (zero_count * sizeof(char *)));
			if(array_of_zero == NULL) {
				printf("array_of_zero realloc issue!!\n");
				exit(EXIT_FAILURE);
			}
			array_of_zero[zero_count - 1] = (char *) malloc(STRLEN * sizeof(char));
			if(array_of_zero[zero_count - 1] == NULL) {
				printf("array_of_zero[%zu] malloc issue!!\n", (zero_count - 1));
				exit(EXIT_FAILURE);
			}
			strcpy(array_of_zero[zero_count - 1], input_container[i]);
		}
	}

	if((one_count > zero_count) || (one_count == zero_count)) {
		free_all_pointers(one_count, array_of_one);
		strcpy(return_val, get_CO2_scrubber_rating(zero_count, (index + 1), array_of_zero));
		free_all_pointers(zero_count, array_of_zero);
		return return_val;
	} else {
		free_all_pointers(zero_count, array_of_zero);
		strcpy(return_val, get_CO2_scrubber_rating(one_count, (index + 1), array_of_one));
		free_all_pointers(one_count, array_of_one);
		return return_val;

	}
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	char *o2_generator_rating;
	char *co2_generator_rating;

	size_t input_len = 0;

	char **input_container = (char **)malloc(sizeof(char *));
	
	if(input_container == NULL) {
		printf("input_container malloc issue!!\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen("input_day3.txt", "r");
	
	if(fp == NULL) {
		printf("fp initialization issue!!\n");
		exit(EXIT_FAILURE);
	}

	input_container[input_len] = NULL;
	while((read = getline(&input_container[input_len], &len, fp)) != -1) {
		input_len++;
		input_container = (char **) realloc(input_container, ((input_len + 1) * sizeof(char*)));
		if(input_container == NULL) {
			printf("input_container realloc issue!!\n");
			exit(EXIT_FAILURE);
		}
		input_container[input_len] = NULL;
	}

	printf("O2 generator rating : %s", get_O2_generator_rating(input_len, 0, input_container));
	printf("CO2 scrubber rating : %s", get_CO2_scrubber_rating(input_len, 0, input_container));

	free_all_pointers(input_len, input_container);

	return 0;
}