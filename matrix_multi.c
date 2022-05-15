#include <stdio.h>
#include <stdlib.h>

void initalize_matrix(int* matrix[], size_t m, size_t n) {
	for(size_t i = 0; i < m; i++) {
		for(size_t j = 0; j < n; j++) {
			printf("[%lu, %lu] :", i, j);
			scanf("%d", &matrix[i][j]);	
		}
	}
}

int get_height(int* matrix[]) {
	return (sizeof matrix) / (sizeof matrix[0]);
}

int get_breadth(int row[]) {
	return (sizeof row) / (sizeof row[0]);
}

void matrix_product(int* mat_A[], int* mat_B[], int* mat_C[]) {
	size_t height_A = get_height(mat_A);
	size_t breadth_A = get_breadth(mat_A[0]);

	size_t height_B = get_height(mat_B);
	size_t breadth_B = get_breadth(mat_B[0]);

	size_t height_C = height_A;
	size_t breadth_C = breadth_B;

	for(size_t i = 0; i < height_C; i++) {
		for(size_t j = 0; j < breadth_C; j++) {
			int sum = 0;
			for(size_t k = 0; k < height_B; k++) {
				sum += (mat_A[i][k] * mat_B[k][j]);
			}
			mat_C[i][j] = sum;
		}
	}
}

void print_result(int* matrix[], size_t m, size_t n) {
	for(size_t i = 0; i < m; i++) {
		printf("|\t");
		for(size_t j = 0; j < n; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("|\n");
	}
}

int main(int argc, char const *argv[]) {

	size_t m;
	size_t n;
	size_t o;
	size_t p;

	printf("Enter dimensions for matrix one: ");
	scanf("%lu", &m);
	scanf("%lu", &n);

	printf("Enter dimensions for matrix two: ");
	scanf("%lu", &o);
	scanf("%lu", &p);

	if(n != o) {
		printf("Dimensions of matrices do not allow for multiplication.\n");
		return EXIT_FAILURE;
	}
	
	int mat_A[m][n];
	int mat_B[o][p];

	printf("Initilize matrix 1:\n");
	initalize_matrix(mat_A, m, n);

	printf("Initilize matrix 2:\n");
	initalize_matrix(mat_B, o, p);

	int mat_C[m][p];

	matrix_product(mat_A, mat_B, mat_C);
	print_result(mat_C, m, p);

	return EXIT_SUCCESS;
}