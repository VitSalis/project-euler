#include <stdio.h>

int main() {
	int prev, curr, next, count;

	prev = 0;
	curr = 1;
	next = 0;
	count = 0;

	while ( curr < 4000000 ) {
		next = curr + prev;

		if ( next % 2 == 0.0 ) {
			count += next;
		}

		prev = curr;
		curr = next;
	}
	
	printf( "%d\n", count );
	return 0;
}
