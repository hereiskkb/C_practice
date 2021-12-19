#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS 80
#define PERIOD 7
#define BRANCH_START 8

size_t branch_size_finder(int days_left, size_t start) {
	days_left = days_left - (start + 1);
	if(days_left < 0) {
		return 1;
	} else {
		size_t branch_count = 1;
		while(days_left > 0) {
			branch_count = branch_count + branch_size_finder(days_left, BRANCH_START);
			days_left = days_left - PERIOD;
		}
		return branch_count;
	}
}



size_t find_lanternfish_count(char *line) {
	size_t existance_indexes[10] = {0};

	char *input = strtok(line, ",");
	while(input != NULL) {
		printf("input : %s\n", input);
		existance_indexes[strtoul(input, NULL, 10)]++;
		input = strtok(NULL, ",");
	}

	size_t result = 0;

	for(size_t i = 0; i < 10; i++) {
		if(existance_indexes[i]) {
			printf("Computing result for index : %zu\n", i);
			size_t index_result =  (existance_indexes[i] * branch_size_finder(DAYS, i));
			printf("Number of lanternfish for index %zu : %zu\n", i, index_result);
			result = result + index_result;
		}
	}

	return result;
}


int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	fp = fopen("input_day6.txt", "r");

	if((read = getline(&line, &len, fp)) != -1) {
		printf("%s\n", line);

		printf("Number of lanternfish after 80 days: %zu\n", find_lanternfish_count(line));
	}

	return EXIT_SUCCESS;
}