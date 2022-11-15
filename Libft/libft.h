#ifndef LIBFT_H
#	define LIBFT_H

#include<stdlib.h>
#include<unistd.h>
int ft_atoi (char* str);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strdup(char *src);
void	*ft_bzero(void *s, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *b, int c, size_t len);
char	*ft_strcpy(char *dest, char *src);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int	ft_strlen(char *str);
void * ft_calloc( size_t elementCount, size_t elementSize );
void *ft_memcpy(void *dest, const void *src, size_t n);
int ft_isprint (int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isalnum(int c);
int	ft_isalnum(int c);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_itoa(int n);
#endif