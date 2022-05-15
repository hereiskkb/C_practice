#include <stdio.h>
#include <assert.h>

size_t gcd(size_t a, size_t b) {
	assert(a);
	assert(b);
	if(a < b) {
		return gcd2(a, b);
	} else {
		return gcd2(b, a);
	}
}

size_t gcd2(size_t a, size_t b) {
	assert(a <= b);
	if(!a)
		return b;
	size_t rem = b % a;
	return gcd2(rem, a);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}