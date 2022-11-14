#include <unistd.h>
#include <stdio.h>
void ft_sort_int_tab(int *tab, int size);
void putstr(char *str);

int  main()
{
	int Chaine[] = {8,5,3,9,4,1,6,2,7,0};
	for(int i = 0 ; i <= 9; i++)
	{
		printf("%d", Chaine[i]);
	}
 	ft_sort_int_tab(Chaine,10);
		
	for(int i = 0; i < 10; i++) 
	{
        printf("-");
	}
	for(int i = 0; i <= 9; i++) 
	{	
        printf("%d", Chaine[i]);
	}

	return 0;
}
