#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	char a[5] = "hello";
	char b[5] = {'h', 'e', 'l', 'l', 'o'};


	if(memchr(a, '\0', sizeof(a)) != NULL && memchr(b, '\0', sizeof(b)) != NULL) {
		if(strlen(a) > strlen(b)) {
			printf("Condition 1\n");
			printf("strcmp(%s, %s) : %d\n", a, b, memcmp(a, b, strlen(b)));
		} else {
			printf("Condition 2\n");
			printf("strcmp(%s, %s) : %d\n", a, b, memcmp(a, b, strlen(a)));
		}
	} else if(memchr(a, '\0', sizeof(a)) == NULL && memchr(b, '\0', sizeof(b)) != NULL) {
		if(sizeof(a) > strlen(b)) {
			printf("Condition 3\n");
			printf("strcmp(%s, %s) : %d\n", a, b, memcmp(a, b, strlen(b)));
		} else {
			printf("Condition 4\n");
			printf("strcmp(%s, %s) : %d\n", a, b, memcmp(a, b, sizeof(a)));
		}
	} else if(memchr(a, '\0', sizeof(a)) != NULL && memchr(b, '\0', sizeof(b)) == NULL) {
		if(strlen(a) < sizeof(b)) {
			printf("Condition 5\n");
			printf("strcmp(%s, %s) : %d\n", a, b, memcmp(a, b, strlen(a)));
		} else {
			printf("Condition 6\n");
			printf("strcmp(%s, %s) : %d\n", a, b, memcmp(a, b, sizeof(b)));
		}
	} else {
		printf("Condition 7\n");
		return 0;
	}
}