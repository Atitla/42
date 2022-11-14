
char *ft_strstr(char *str, char *to_find);

#include <string.h>
#include <stdio.h>
int main()
{
    char to_find[10] = "ahh";
    char str[80] = "ahahahahahahahahhahahah";
    printf("strstr:   %s\n",strstr(str,to_find));
    printf("ft_strstr:%s\n",ft_strstr(str,to_find));
}
