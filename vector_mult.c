#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define VECTOR_SIZE 3

void initalize_vectors(int vector[VECTOR_SIZE]) {
	for(size_t i = 0; i < VECTOR_SIZE; i++) {
		printf("%lu :", i);
		scanf("%d", &vector[i]);
	}
}

void vector_crossProduct(int vec_A[VECTOR_SIZE], int vec_B[VECTOR_SIZE], int vec_C[VECTOR_SIZE]) {
	vec_C[0] = (vec_A[1] * vec_B[2]) - (vec_A[2] * vec_B[1]);
	vec_C[1] = (vec_A[0] * vec_B[2]) - (vec_A[2] * vec_B[0]);
	vec_C[2] = (vec_A[0] * vec_B[1]) - (vec_A[1] * vec_B[0]);
}

char* sign(int a) {
	return (a < 0) ? "-" : "+";
}

int main(int argc, char const *argv[]) {
	
	int vec_A[VECTOR_SIZE];
	int vec_B[VECTOR_SIZE];
	int vec_C[VECTOR_SIZE];

	printf("Initialize A:\n");
	initalize_vectors(vec_A);

	printf("Initialize B:\n");
	initalize_vectors(vec_B);

	vector_crossProduct(vec_A, vec_B, vec_C);
	printf("Cross product:\nC : %s%di %s %dj %s %dk\n", 
		sign(vec_C[0]), abs(vec_C[0]), sign(vec_C[1]), abs(vec_C[1]), sign(vec_C[2]), abs(vec_C[2]));

	return 0;
}