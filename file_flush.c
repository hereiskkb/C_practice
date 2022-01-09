#include <stdio.h>

void delay(double secs) {
	double const magic = 4E8;
	unsigned long long const nano = secs * magic;
	for(unsigned long volatile count = 0; count < nano; ++count) {
	}
}

int main(int argc, char *argv[argc + 1]) {
	fputs("waiting 10 seconds for you to stop me", stdout);
	if(argc < 3) {
		fflush(stdout);
	}

	for(unsigned i = 0; i < 10; ++i) {
		fputc('.', stdout);
		if(argc < 2) {
			fflush(stdout);
		}

		delay(1.0);
	}

	fputs("\n", stdout);
	fputs("Done here!\n", stdout);
}