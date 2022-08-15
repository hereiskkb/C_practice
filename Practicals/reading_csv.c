#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <mongoc/mongoc.h>

#define TOKEN_COUNT 3

typedef struct driver_profile {
	char *name;
	char *team;
	char *car_number;
} driver_profile;

void reassign_all_pointers(char **token_list, size_t max_size) {
	for(size_t i = 0; i < TOKEN_COUNT; i++) {
		token_list[i] = (char *) realloc(token_list[i], max_size * sizeof(char));
	}
}

void initalize_driver_profile_from_tokens(char **token_list, driver_profile ***drivers, size_t *line_count) {
	(**drivers)[(*line_count) - 1].name = (char *) malloc(strlen(token_list[0]) * sizeof(char));
	(**drivers)[(*line_count) - 1].team = (char *) malloc(strlen(token_list[1]) * sizeof(char));
	(**drivers)[(*line_count) - 1].car_number = (char *) malloc(strlen(token_list[2]) * sizeof(char));

	strcpy((**drivers)[(*line_count) - 1].name, token_list[0]);
	strcpy((**drivers)[(*line_count) - 1].team, token_list[1]);
	strcpy((**drivers)[(*line_count) - 1].car_number, token_list[2]);
}

void get_all_driver_profiles(const char *file_name, driver_profile **drivers, size_t *line_count) {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	*line_count = 0;

	// vars related to reading tokens
	char delimiter = ',';
	size_t max_size = 10;
	char **token_list= (char **) malloc(TOKEN_COUNT * sizeof(char *));
	size_t index = 0;
	size_t token_index = 0;
	size_t token_count = 0;

	fp = fopen("input.csv", "r");
	if(fp == NULL) {
		printf("[!] Error opening file\n");
		exit(EXIT_FAILURE);
	}	

	for(size_t i = 0; i < TOKEN_COUNT; i++) {
		token_list[i] = (char *) malloc(max_size * sizeof(char));
	}


	while((read = getline(&line, &len, fp)) != -1) {
		(*line_count)++;
		*drivers = (driver_profile *) realloc(*drivers, (*line_count) * sizeof(driver_profile));
		index = 0;
		token_count = 0;
		token_index = 0;

		for(size_t i = 0; i < TOKEN_COUNT; i++) {
			strcpy(token_list[i], "");
		}

		while(line[index] != '\0') {
			if(line[index] == delimiter) {
				*(token_list[token_count] + (token_index)) = '\0';
				token_count++;
				if(token_count > (TOKEN_COUNT - 1)) {
					token_count--;
					break;
				}
				token_index = 0;
			} else {
				*(token_list[token_count] + (token_index++)) = line[index];
				if(token_index > max_size) {
					max_size = max_size * 2;
					if(max_size > SIZE_MAX) {
						printf("[!] Ran out of memory!");
						exit(EXIT_FAILURE);
					}
					reassign_all_pointers(token_list, max_size);
				}
			}
			index++;
		}

		if(*(token_list[token_count] + (token_index - 1)) == '\n') {
			*(token_list[token_count] + (token_index - 1)) = '\0';
		} else {
			*(token_list[token_count] + (token_index)) = '\0';
		}
		initalize_driver_profile_from_tokens(token_list, &drivers, line_count);
	}


	for(size_t i = 0; i < TOKEN_COUNT; i++) {
		free(token_list[i]);
	}

	free(token_list);
	fclose(fp);
}

void print_all_driver_details(driver_profile *drivers, size_t line_count) {
	for(size_t i = 0; i < line_count; i++) {
		printf("Name: %s\n", drivers[i].name);
		printf("Team: %s\n", drivers[i].team);
		printf("Car Number: %s\n", drivers[i].car_number);
	}
}

void free_all_driver_structs(driver_profile *drivers, size_t line_count) {
	for(size_t i = 0; i < line_count; i++) {
		free(drivers[i].name);
		free(drivers[i].team);
		free(drivers[i].car_number);
	}
	free(drivers);
}

int main(int argc, char const *argv[argc]) {

	driver_profile *drivers = (driver_profile *) malloc(sizeof(driver_profile));
	size_t line_count = 0;
	if(argc == 3 && strcmp(argv[1], "-f") == 0) {
		get_all_driver_profiles(argv[2], &drivers, &line_count);
		print_all_driver_details(drivers, line_count);
		free_all_driver_structs(drivers, line_count);

	} else {
		printf("[!] command format incorrect!\n>> Correct usaage: ./reading_csv.o -f file_name_here\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}