#include "gcd.h"

/* Standard C Function: Greatest Common Divisor */
size_t gcd(size_t a, size_t b)
{
	size_t c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}