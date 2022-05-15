#if __STDC_LIB_EXT1__
# error "This code needs bouds checking interface of Annex K"
#endif

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	printf("C11 compatible\n");
	return 0;
}