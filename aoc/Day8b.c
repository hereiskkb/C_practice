#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t is_three(char *digit, char *seven) {
	return (strchr(digit, seven[0]) && strchr(digit, seven[1]) && strchr(digit, seven[2]));
}

size_t is_six(char *digit, char *one) {
	
}

void squeeze(char **bucket, size_t index, size_t length) {
	for(size_t i = index; i < length - 1; i++) {
		bucket[i] = bucket[i + 1];
	}
	bucket[length - 1] = NULL;
}

void create_digit_map(char *key, char *all_digits[10]) {
	printf("Key recieved: %s\n", key);
	char *cursor = strtok(key, " ");
	char *digit_bucket[6];
	for(size_t i = 0, j = 0; i < 10; i++) {
		if(cursor != NULL) {
			size_t len = strlen(cursor);
			if(len == 2) {
				all_digits[1] = cursor;
			} else if(len == 3) {
				all_digits[7] = cursor;
			} else if(len == 4) {
				all_digits[4] = cursor;
			} else if(len == 7) {
				all_digits[8] = cursor;
			} else {
				digit_bucket[j++] = cursor;	
			}
			cursor = strtok(NULL, " ");
		}
	}

	// for finding 3
	for(size_t i = 0; i < 6; i++) {
		if(digit_bucket[i] != NULL && is_three(digit_bucket[i], all_digits[7])) {
			all_digits[3] = (char *) malloc(sizeof(char) * strlen(digit_bucket[i]));
			strcpy(all_digits[3], digit_bucket[i]);
			squeeze(digit_bucket, i, 6);
			break;
		}
	}

	// for finding 6
	for(size_t i = 0; i < 5; i++) {
		if(digit_bucket[i] != NULL && is_six(digit_bucket[i], all_digits[1])) {
			all_digits[6] = (char *) malloc(sizeof(char) * strlen(digit_bucket[i]));
			squeeze(digit_bucket, i, 5);
			break;
		}
	}

	for(size_t i = 0; i < 4; i++) {
		if()
	}
}

void compute_target(char *all_digits, char *target, size_t *target_num) {
	
}

void sanitize_target(char *target) {
	target[strlen(target) - 1] = '\0';
	for(size_t i = 0; i < strlen(target); i++) {
		target[i] = target[i + 1];
	}
}

void create_key_and_target(char **key, char **target, char *line) {
	*key = strtok(line, "|");
	*target = strtok(NULL, "");

	printf("Key : %s\n", *key);
	sanitize_target(*target);	
	printf("Target : %s\n", *target);	
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;
	char *key = NULL;
	char *target = NULL;
	char *all_digits[10] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	size_t target_num = 0;
	size_t sum = 0;

	fp = fopen("input_day8.txt", "r");
	while((read = getline(&line, &len, fp)) != -1) {
		create_key_and_target(&key, &target, line);
		create_digit_map(key, &all_digits);
		// compute_target(all_digits, target, &target_num);
		// sum += target_num;
		// key = NULL;
		// target = NULL;
		// target_num = 0;
		// for(size_t i = 0; i < 10; i++) {
		// 	all_digits[i] = NULL;
		// }
	}


	fclose(fp);
	return 0;
}