#if (-1 & 3) == 1
# error "encoding is sign and magnitude"
#elif (-1 & 3) == 2
# error "encoding is one's complement"
#elif (-1 & 3) == 3
# error "encoding is two's complement"
#else
# error "bad encoding"
#endif