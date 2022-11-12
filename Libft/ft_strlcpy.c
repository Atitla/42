#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int unsigned	i;

	i = 0;
	if (size == 0 || size == 1)
		return (ft_strlen(src));
	else
	{
		while (src[i])
		{	
			dest[i] = src[i];
			i++;
			if (i == size - 1)
			{
				dest[i] = '\0';
				return (ft_strlen(src));
			}
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

int main(){

//    char str1[40] = "bonjous";
//    char str2[40];
//    unsigned int i = strlcpy(str2, str1, 50);
//    printf("---strlcpy---\n%s\nret:%d\n",str2,i);

    char str3[40] = "bonjous";
    char str4[40];
    unsigned int j = ft_strlcpy(str4, str3, 50);
    printf("---ft_strlcpy---\n%s\nret:%d\n",str4,j);
}