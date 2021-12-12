#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct board {
	int board_array[5][5];
} board_t;

size_t get_unmarked_sum(board_t board) {
	size_t sum = 0;

	for(size_t i = 0; i < 5; i++) {
		for(size_t j = 0; j < 5; j++) {
			if((board.board_array[i][j]) != -1) {
				sum += board.board_array[i][j];
			}
		}
	}
	return sum;
}

size_t board_complete(board_t board, size_t row, size_t col) {
	size_t row_complete = 1;
	size_t col_complete = 1;

	for(size_t i = 0; i < 5; i++) {
		if(board.board_array[row][i] != -1) {
			row_complete = 0;
			break;
		}

	}

	if(!row_complete) {
		for(size_t i = 0; i < 5; i++) {
			if(board.board_array[i][col] != -1) {
				col_complete = 0;
				break;
			}
		}
	}

	return (row_complete || col_complete) ? 1 : 0;
}

void print_board(board_t board) {
	for(size_t i = 0; i < 5; i++) {
		for(size_t j = 0; j < 5; j++) {
			printf("%d\t", board.board_array[i][j]);
		}
		printf("\n");
	}
}

size_t solve_board(size_t *call_out_array, size_t size_of_callout, board_t *boards, size_t board_counter) {
	size_t current_call;
	board_t current_board;
	size_t unmarked_sum = 0;

	for(size_t i = 0; i < size_of_callout; i++) {
		current_call = call_out_array[i];
		printf("Current call: %zu\n", current_call);	
		for(size_t j = 0; j < board_counter; j++) {
			for(size_t k = 0; k < 5; k++) {
				for(size_t l = 0; l < 5; l++) {
					if((boards[j].board_array[k][l]) == current_call) {
						boards[j].board_array[k][l] = -1;
						printf("Current board : %zu\n", j);
						print_board(boards[j]);
						if(board_complete(boards[j], k, l)) {
							current_board = boards[j];
							goto compute_result;
						}
					}
				}
			}
		}
	}

compute_result:
	unmarked_sum = get_unmarked_sum(current_board);
	printf("Current call: %zu\n", current_call);
	printf("Unmarked sum: %zu\n", unmarked_sum);
	return unmarked_sum * current_call;

}

void assign_row_to_board(board_t *current_board, char *line, size_t row_counter) {
	size_t entry = 0;
	size_t column = 0;

	char *token = strtok(line, " ");

	while(token) {
		entry = strtoul(token, NULL, 10);
		current_board -> board_array[row_counter][column++] = entry;
		token = strtok(NULL, " ");
	}
}

void callout_array_intializer(char *call_out_string, size_t **call_out_array, size_t *size_of_callout) {
	char *entry = strtok(call_out_string, ",");
	*size_of_callout = 0;
	while(entry) {
		(*size_of_callout)++;
		(*call_out_array) = (size_t *) realloc((*call_out_array), ((*size_of_callout + 1) * sizeof(size_t)));
		if(*call_out_array == NULL) {
			printf("Error in realloc. Exiting.\n");
			exit(EXIT_SUCCESS);
		}
		(*call_out_array)[(*size_of_callout) - 1] = strtoul(entry, NULL, 10);
		entry = strtok(NULL, ",");
	}
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	board_t *boards = NULL;

	size_t board_counter = 0;
	size_t row_counter = 0;

	char *call_out_string = NULL;
	size_t *call_out_array = NULL;
	size_t size_of_callout = 0;
	size_t result;

	fp = fopen("input_day4.txt", "r");

	if((read = getline(&call_out_string, &len, fp)) == -1) {
		printf("No callout array\n");
		exit(EXIT_SUCCESS);
	}

	while((read = getline(&line, &len, fp)) != -1) {
		if(row_counter == 0) {
			row_counter++;
			board_counter++;
			boards = (board_t *) realloc(boards, ((board_counter+1) * sizeof(board_t)));
		} else {
			assign_row_to_board(&boards[board_counter - 1], line, (row_counter - 1));
			row_counter = (row_counter % 5 == 0) ? 0 : (row_counter + 1);
		}
	}

	callout_array_intializer(call_out_string, &call_out_array, &size_of_callout);


	// print_board(boards[0]);
	result = solve_board(call_out_array, size_of_callout, boards, board_counter);

	printf("Result: %zu\n", result);

	return 0;
}