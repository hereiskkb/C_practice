#include <stdio.h>
#include <stdlib.h>

#define BRANCH_START 8

size_t branch_size_finder(int days_left, size_t start, size_t period) {
	days_left = days_left - (start + 1);
	if(days_left < 0) {
		return 1;
	} else {
		size_t branch_count = 1;
		while(days_left > 0) {
			branch_count = branch_count + branch_size_finder(days_left, BRANCH_START, period);
			days_left = days_left - period;
		}
		return branch_count;
	}
}


int main(int argc, char const *argv[]) {
	
	if(argc == 1) {
		printf("Enter some value you fucking moron!\n");
		return EXIT_FAILURE;
	}
	int value = strtol(argv[1], NULL, 10);
	int days = strtol(argv[2], NULL, 10);

	printf("Find number of branches for %d : %zu\n", value, branch_size_finder(days, value, 7));

	return 0;
}