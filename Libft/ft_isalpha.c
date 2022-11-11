#include <libft.h>
int	ft_isalnum(int c){
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
