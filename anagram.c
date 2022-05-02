#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 26

size_t alpha_list[LIMIT] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

size_t beta_list[LIMIT] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

size_t find_index(char c) {
	if(c >= 65 && c <= 90) {
		return (c % 65);
	} else if(c >= 97 && c <= 122) {
		return (c % 97);
	}
}

size_t is_letter(char c) {
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
		return 1;
	} else {
		return 0;
	}
}

char* trim(char* input) {
	input[strlen(input) - 1] = '\0';
	return input;
}

int is_anagram(char *key, char *input) {
	if(strlen(key) == strlen(input)) {
		for(size_t i = 0; i < strlen(key); i++) {
			char alpha = key[i];
			char beta = input[i];
			if(is_letter(alpha)) {
				alpha_list[find_index(alpha)]++;
			}
			if(is_letter(beta)) {
				beta_list[find_index(beta)]++;
			}
		}
		
		for(size_t i = 0; i < LIMIT; i++) {
			if(alpha_list[i] != beta_list[i]) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int main(int argc, char const *argv[argc]) {
	
	char *key = (char *) malloc(sizeof(char) * strlen(argv[1]));
	strcpy(key, argv[1]);
	char *input = NULL;
	size_t len = 0;
	int read;

	printf("Enter string to check: ");
	while ((read = getline(&input, &len, stdin)) != -1) {
        if(is_anagram(key, trim(input))) {
			printf("Is an anagram\n");
		} else {
			printf("Is not an anagram\n");
		}

		for(size_t i = 0; i < 26; i++) {
			alpha_list[i] = 0;
			beta_list[i] = 0;
		}
		
		printf("Enter string to check: ");
    }
	return 0;
}