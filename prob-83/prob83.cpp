#include <cstdio>
#include <queue>

using namespace std;

struct cord {
	int x;
	int y;
};

void dijkstra( int array[][ 80 ] ) {
	long long int dist[ 80 ][ 80 ];
	int i, j;

	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			dist[ i ][ j ] = 1000000000;
		}
	}

	queue< cord > q;
	q.push( ( cord ) { 0, 0 } );

	dist[ 0 ][ 0 ] = array[ 0 ][ 0 ];

	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		if ( p.x + 1 < 80 && dist[ p.x ][ p.y ] + array[ p.x + 1 ][ p.y ] < dist[ p.x + 1 ][ p.y ] ) {
			dist[ p.x + 1 ][ p.y ] = dist[ p.x ][ p.y ] + array[ p.x + 1 ][ p.y ];
			q.push( ( cord ) { p.x + 1, p.y } );
		}
		if ( p.x - 1 >= 0 && dist[ p.x ][ p.y ] + array[ p.x - 1 ][ p.y ] < dist[ p.x - 1 ][ p.y ] ) {
			dist[ p.x - 1 ][ p.y ] = dist[ p.x ][ p.y ] + array[ p.x - 1 ][ p.y ];
			q.push( ( cord ) { p.x - 1, p.y } );
		}
		if ( p.y + 1 < 80 && dist[ p.x ][ p.y ] + array[ p.x ][ p.y + 1 ] < dist[ p.x ][ p.y + 1 ] ) {
			dist[ p.x ][ p.y + 1 ] = dist[ p.x ][ p.y ] + array[ p.x ][ p.y + 1 ];
			q.push( ( cord ) { p.x, p.y + 1 } );
		}
		if ( p.y - 1 >= 0 && dist[ p.x ][ p.y ] + array[ p.x ][ p.y - 1 ] < dist[ p.x ][ p.y - 1 ] ) {
			dist[ p.x ][ p.y - 1 ] = dist[ p.x ][ p.y ] + array[ p.x ][ p.y - 1 ];
			q.push( ( cord ) { p.x, p.y - 1 } );
		}
	}

	printf( "%lld\n", dist[ 79 ][ 79 ] );

}

int main() {
	freopen( "prob83.in", "r", stdin );
	int array[ 80 ][ 80 ];
	int i, j;

	for ( i = 0; i < 80; ++i ) {
		for ( j = 0; j < 80; ++j ) {
			scanf( "%d", array[ i ] + j );
		}
	}

	dijkstra( array );

	return 0;
}