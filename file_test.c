#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[argc + 1]) {
	FILE* logfile = fopen(argv[1], "w+x");
	if(!logfile) {
		perror("fopen failed!");
		return EXIT_FAILURE;
	}

	fputs("Fopen works file\n", logfile);
	fclose(logfile);
	return 0;
}