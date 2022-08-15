#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* get_time() {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	return asctime(timeinfo);
}

int main(int argc, char const *argv[argc]) {
	
	// char *s = "This is a new string %s";
	// char *s2 = (char *) malloc(46 * sizeof(char));
	// sprintf(s2, s, "HELLO");
	// printf("%s\n", s2);
	// free(s2);

	char *s = get_time();
	char *page = "{\"data\": \"%s\"}";
	char *response_string = (char *) malloc((strlen(s) + strlen(page)) * sizeof(char));
	sprintf(response_string, page, s);
	printf("Time: %s\n", response_string);
	free(response_string);
	return 0;
}