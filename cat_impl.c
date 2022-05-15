#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

enum { buf_max = 32 };

int main(int argc, char const *argv[argc + 1]) {

	int ret = EXIT_FAILURE;
	char buffer[buf_max] = { 0 };
	if(argc == 1) {
		while(fgets(buffer, buf_max, stdin)) {
			fputs(buffer, stdout);
		}
		ret = EXIT_SUCCESS;

	} else {
		for(int i = 1; i < argc; ++i) {
			FILE* instream = fopen(argv[i], "r");
			if(instream) {
				size_t line_number = 1;
				size_t flag = 0;
				while(fgets(buffer, buf_max, instream)) {
					if(!flag) {
						printf("%zu ", line_number++);
					}
					if(!strchr(buffer, '\n')) {
						flag = 1;
					} else {
						flag = 0;
					}
					fputs(buffer, stdout);
				}
				fclose(instream);
				ret = EXIT_SUCCESS;
			} else {
				fprintf(stderr, "Could not open %s: ", argv[1]);
				perror(0);
				errno = 0;
			}
		}
	}
	
	return ret;
}