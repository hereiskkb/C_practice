#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t get_hascode(const void* key) {
    uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

int main(int argc, char const *argv[argc]) {
	
	if(argc == 2) {
		printf("Generated hash: %lx\n", get_hascode(argv[1]));
	} else {
		printf("Format:\nhashcode.o <input>\n");
	}
	return 0;
}