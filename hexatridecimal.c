#include <stdio.h>
#include <ctype.h>
#include <assert.h>

static_assert('z' - 'a' == 25, "alphanumeric charecters not contiguous");

unsigned hexatridecimal(int a) {
	if(isdigit(a)) {
		return a - '0';
	} else {
		a = toupper(a);
		return (isupper(a)) ? 10 + (a - 'A') : -1;
	}
}

int main(int argc, char const *argv[]) {
	
	printf("Printing base36 values of alphabets\n");
	for(char a = 'A'; a <= 'Z'; a++) {
		printf("%c : %u\n", a, hexatridecimal(a));
	}

	for(char a = 'a'; a <= 'z'; a++) {
		printf("%c : %u\n", a, hexatridecimal(a));
	}

	for(char a = '0'; a <= '9'; a++) {
		printf("%c : %u\n", a, hexatridecimal(a));
	}

	return 0;
}