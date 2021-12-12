#include <stdio.h>
#include <stdlib.h>

void assign_to_array(int *array) {
	array = (int *) malloc(10 * sizeof(int));
	for(int i = 0; i < 10; i++) {
		array[i] = i;
	}
}


int main(int argc, char const *argv[]) {

	int *array = NULL;
	assign_to_array(array);

	for(int i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}

	return 0;
}