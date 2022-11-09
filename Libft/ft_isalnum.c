#include <ctype.h>
#include <stdio.h>
int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'));
}
int main (int ac, char** av){

	(void) ac;
	printf("%d\n", isalnum(av[1][0]));
	printf("%d\n", ft_isalnum(av[1][0]));
}
