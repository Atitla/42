#include "libft.h"

void *ft_memset(void *b, int c, size_t len){
	size_t i;

	i = 0;
	//if (!s)
	//	return(0);
	while (i < len)
	{
		*(unsigned char *)(b + i) = c;
		i++;
	}
	return(b);
}
int main (void){

	int i = 0;
	int array[] = {12, 553, 96 ,23};
	int array2[] = {12, 553, 96 ,23};
	ft_memset(array, 4, 8);
	memset(array2, 4, 8);
	while (i < 4)
	{
		printf("%d\n", array[i]);
		printf("%d\n", array2[i]);
		i++;
	}
	return 0;
}