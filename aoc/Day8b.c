#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitizeTarget(char *target) {
	target[strlen(target) - 1] = '\0';
	for(size_t i = 0; i < strlen(target); i++) {
		target[i] = target[i + 1];
	}
}

void createKeyAndTarget(char *line) {
	char *key = strtok(line, "|");
	char *target = strtok(NULL, "");

	printf("Key : %s\n", key);
	sanitizeTarget(target);	
	printf("Target : %s\n", target);
	//TODO : write logic of getting the letters
}

int main(int argc, char const *argv[]) {
	
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	size_t read;

	fp = fopen("input_day8.txt", "r");
	while((read = getline(&line, &len, fp)) != -1) {
		createKeyAndTarget(line);
	}


	fclose(fp);
	return 0;
}