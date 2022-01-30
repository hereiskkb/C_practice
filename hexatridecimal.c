#include <stdio.h>
#include <ctype.h>
#include <assert.h>

static_assert('z' - 'a' == 25, "alphanumeric charecters not contiguous");

unsigned long Strtoul(char const s[static 1], unsigned base) {
	if(base > 36u) {
		errono = EINVAL;
		return ULONG_MAX;
	}

	size_t i = strspn(s, " \f\n\r\t\v");
	bool switchsign = false;
	switch(s[i]) {
		case '-':
			switchsign = true;
		case '+':
			++i;
	}

	if(!base || base == 16) {
		size_t adj = find_prefix(s, i, "0x");
		if(!base) {
			base = (unsigned []) {10, 8, 16} [adj];
		}
		i += adj;
	}

	unsigned long ret = strtoul_inner(s, i, base);
	return (switchsign) ? -ret : ret;
}

unsigned long strtoul_inner(char const s[static 1], size_t i, unsigned base) {
	unsigned long ret = 0;
	while(s[i]) {
		unsigned c = hexatridecimal(s[i]);
		if(c >= base) {
			break;
		}
		if(ULONG_MAX/base < ret) {
			ret = ULONG_MAX;
			errno = ERANGE;
			break;
		}

		ret *= base;
		ret += c;
		++i;
	}

	return ret;
}

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