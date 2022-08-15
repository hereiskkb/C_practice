#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(int argc, char const *argv[argc]) {
	
// 	char *str = (char *) malloc(10 * sizeof(char));
// 	printf("%s\n", str);
// 	strcpy(str, "");
// 	*(str + 0) = 'a'; 
// 	*(str + 1) = 'a'; 
// 	printf("%s\n", str);
// 	return 0;
// }

void func_to_modify2(char ***test_str) {
	**test_str = (char *) malloc(10 * sizeof(char));
	strcpy(**test_str, "new");
}

void func_to_modify1(char **test_str) {
	func_to_modify2(&test_str);
}

int main(int argc, char const *argv[argc]) {
	
	char *test_str = NULL;
	func_to_modify1(&test_str);
	printf("%s\n", test_str);
	return 0;
}