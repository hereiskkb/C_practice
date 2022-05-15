#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct point {
	long x;
	long y;
	size_t count;
} point_t;

size_t get_x_value(char *point) {
	char *str_x = strtok(point, ",");
	return strtol(str_x, NULL, 10);
}

size_t get_y_value(char *point) {
	char *str_y = strtok(point, ",");
	str_y = strtok(NULL, ",");
	return strtol(str_y, NULL, 10);
}

void update_point_list(point_t ***point_list, size_t **point_list_size, long x, long y) {
	size_t point_exists = 0;
	for(size_t i = 0; i < **point_list_size; i++) {
		if(((**point_list)[i].x == x) && ((**point_list)[i].y == y)) {
			point_exists = 1;
			(**point_list)[i].count++;
			break;
		}
	}

	if(!point_exists) {
		(**point_list_size)++;
		(**point_list) = (point_t *) realloc((**point_list), ((**point_list_size) * sizeof(point_t)));
		(**point_list)[(**point_list_size) - 1].x = x;
		(**point_list)[(**point_list_size) - 1].y = y;
		(**point_list)[(**point_list_size) - 1].count = 1;
	}
}

size_t get_overlap_count(point_t *point_list, size_t point_list_size) {
	size_t overlap_count = 0;
	for(size_t i = 0; i < point_list_size; i++) {
		if((point_list[i].count) > 1) {
			overlap_count++;
		}
	}

	return overlap_count;
}

void analyze_point(char *line, point_t **point_list, size_t *point_list_size) {
	char *point1 = NULL;
	char *point2 = NULL;
	char *point1_copy = NULL;
	char *point2_copy = NULL;
	long x1, y1, x2, y2;

	point1 = strtok(line, " -> ");
	point1_copy = (char *) malloc(15 * sizeof(char));
	strcpy(point1_copy, point1);
	point2 = strtok(NULL, " -> ");
	point2_copy = (char *) malloc(15 * sizeof(char));
	strcpy(point2_copy, point2);
	
	x1 = get_x_value(point1);
	y1 = get_y_value(point1_copy);
	x2 = get_x_value(point2);
	y2 = get_y_value(point2_copy);
	
	if(x1 == x2) {
		if(y1 > y2) {
			while(y1 >= y2) {
				update_point_list(&point_list, &point_list_size, x1, y1--);
			}
		} else {
			while(y2 >= y1) {
				update_point_list(&point_list, &point_list_size, x1, y2--);
			}
		}
	} else if(y1 == y2) {
		if(x1 > x2) {
			while(x1 >= x2) {
				update_point_list(&point_list, &point_list_size, x1--, y1);
			}
		} else {
			while(x2 >= x1) {
				update_point_list(&point_list, &point_list_size, x2--, y1);
			}
		}
	} else if(abs(x1 - x2) == abs(y1 - y2)){
		if((x1 > x2) && (y1 > y2)) {
			while(x1 >= x2) {
				update_point_list(&point_list, &point_list_size, x1--, y1--);	
			}
		} else if((x2 > x1) && (y2 > y1)) {
			while(x2 >= x1) {
				update_point_list(&point_list, &point_list_size, x2--, y2--);		
			}
		} else if((x1 > x2) && (y2 > y1)) {
			while(x1 >= x2) {
				update_point_list(&point_list, &point_list_size, x1--, y1++);		
			}
		} else if((x2 > x1) && (y1 > y2)) {
			while(x2 >= x1) {
				update_point_list(&point_list, &point_list_size, x2--, y2++);		
			}
		}

	}

	free(point1_copy);
	free(point2_copy);
} 

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	point_t *point_list = NULL;
	size_t point_list_size = 0;
	fp = fopen("input_day5.txt", "r");

	while((read = getline(&line, &len, fp)) != -1) {
		analyze_point(line, &point_list, &point_list_size);
	}

	printf("Number of overlaps: %zu\n", get_overlap_count(point_list, point_list_size));
	return EXIT_SUCCESS;
}