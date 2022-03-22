#include <stdio.h>
#include <string.h>

int is_anagram(char *key, char *input) {
	if(strlen(key) == strlen(input)) {
		
		
	}

	return 0;
}

int main(int argc, char const *argv[argc]) {
	
	char *key = argv[1];
	char *input = NULL;
	while(1) {
		printf("Enter string to check: ");
		scanf("%s", input);
		if(is_anagram(key, input)) {
			printf("Is an anagram\n");
		} else {
			printf("Is not an anagram\n");
		}
	}
	return 0;
}