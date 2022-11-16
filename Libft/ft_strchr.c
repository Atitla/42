#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char * ft_strchr( const char * string, int searchedChar ){
	int i;
	char *ptr;

	ptr = (char *)string;
	i = 0;
	while (ptr)
	{
		if(*ptr == searchedChar)
			return(ptr);
		i++;
		ptr++;
	}
    return(NULL);
}
