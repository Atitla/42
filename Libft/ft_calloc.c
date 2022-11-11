#include "libft.h"
void * calloc( size_t elementCount, size_t elementSize ){
	int size;
	int i;
	void *tab;

	i = 0;
	size = elementCount * elementSize;
	tab = (void *)malloc(size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size);
	return(tab);
	
}