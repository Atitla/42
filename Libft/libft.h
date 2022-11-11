#ifndef LIBFT_H
#	define LIBFT_H

#include<stdlib.h>
#include<unistd.h>
void * calloc( size_t elementCount, size_t elementSize );
void *ft_memcpy(void *dest, const void *src, size_t n);
int ft_isprint (int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isalnum(int c);
int	ft_isalnum(int c);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_itoa(int n);
#endif