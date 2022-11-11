#include "libft.h"
int	ft_isalnum(int c){
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'));
}

