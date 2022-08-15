#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash_key(const void* key) {
    uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

int main(int argc, char const *argv[argc]) {
	// printf("%lu\n", hash_key(argv[1]));

    fprintf(stderr, "%s\n", "system out of memory\n");
	return 0;
}