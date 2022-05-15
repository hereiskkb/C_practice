#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]) {
	
	struct timespec const t1 = {
		.tv_sec = 121300,
		.tv_nsec = 12039, 
	};

	struct timespec const t2 = {
		.tv_sec = 121250,
		.tv_nsec = 12035,
	};

	printf("Diff in t1 and t2 :\ntv_sec : %ld, tv_nsec : %ld\n", (t1.tv_sec - t2.tv_sec), (t1.tv_nsec - t2.tv_nsec));
	return 0;
}