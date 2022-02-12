#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createKeyAndTarget(char *line) {
	char *key = strtok(line, "|");
	char *target = strtok(NULL, "");

	printf("Key : %s\n", key);
	target[strlen(target) - 1] = '\0';
	printf("Target : %s\n", target);

	char *keyParts = strtok(key, " ");
	while(keyParts) {
		printf("%s : %zu\n", keyParts, strlen(keyParts));
		keyParts = strtok(NULL, " ");
	}

	char *targetParts = strtok(target, " ");
	while(targetParts) {
		printf("%s : %zu\n", targetParts, strlen(targetParts));
		targetParts = strtok(NULL, " ");
	}

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