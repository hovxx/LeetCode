/*
 * problem ID: 2750(original)
 */

#include <stdio.h>

int 
main( int argc, char **argv )
{
    int nSample, nFeet;

    scanf( "%d", &nSample );
    for( int i=0; i<nSample; i++ ) {
        scanf( "%d", &nFeet );
        if( nFeet%2 )
            printf( "%d %d\n", 0, 0 );
        else if( nFeet%4 ) 
            printf( "%d %d\n", nFeet/4+1, nFeet/2 );
        else
            printf( "%d %d\n", nFeet/4, nFeet/2 );
    }

    return 0;
}
