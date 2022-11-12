#include "libft.h"

void	*ft_bzero(void *s, size_t n){
	
	size_t i;

	i = 0;
	if (!s)
		return(0);
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return(s);
}

int main (void){

	int i = 0;
	int array[] = {12, 553, 96 ,23, 456, 54};
	int array2[] = {12, 553, 96 ,23, 456, 54};
	bzero(array, 12);
	ft_bzero(array2, 12);
	while (i < 6)
	{
		printf("%d\n", array[i]);
		printf("%d\n", array2[i]);
		i++;
	}
	return 0;
}