/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:39 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/15 21:57:40 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *d;
	unsigned const char *s;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int main() {

    int array [] = { 523523553, 85, 20, 63, 21 };
	int array2 [] = { 523523553, 85, 20, 63, 21 };
    int * copy = NULL;
	int * copy2 = NULL;
    int length = sizeof( int ) * 5;
       
    /* Memory allocation and copy */
    copy = (int *) malloc( length );
	copy2 = (int *) malloc( length );
    memcpy( copy, array, length );
	ft_memcpy( copy2, array2, length );
        
    /* Display the copied values */
    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
		printf( "%d ", copy2[ length ] );
    }
    printf( "\n" );
        
    free( copy );
    
    return EXIT_SUCCESS;
}