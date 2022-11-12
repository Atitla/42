#include "libft.h"
void *ft_memmove(void *dest, const void *src, size_t n){

	unsigned char *temp;
	size_t i;
	unsigned char *d;
	unsigned const char *s;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = temp[i];
		i++;
	}
	return(d);
}