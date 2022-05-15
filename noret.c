#include <stdio.h>
#include <stdnoreturn.h>

noreturn void printer1() {
	printf("Called printer1\n");
}

int main(int argc, char const *argv[]) {
	
	printer1();
	printf("called main\n");
	return 0;
}