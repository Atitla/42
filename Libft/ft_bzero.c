#include <stdio.h>
#include <stdlib.h>

void bzero(void *s, size_t n){
	int i;
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (n > i++)
		ptr[i] = '\0';
	
}
int main() {

    int array [] = { -2147483648, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
       
    /* Memory allocation and copy */
    copy = (int *) malloc( length );
    // bzero(array, 5);
        
    /* Display the copied values */
    for( length=0; length<5; length++ ) {
        
        ( "%d ", array[ length ] );
    }
    printf( "\n" );
        
    free( copy );
    
    return 0;
}