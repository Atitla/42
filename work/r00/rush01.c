#include <stdio.h>
void top(int x);
void left(int x);
void middle(int x, int y);
void bottom(int x);

void rush(int x, int y)
{
    if ((x <= 0 && y <= 0) || (x <= 0 || y <= 0))
        return;
    else if (x == 1 && y == 1)
	{
     	putchar('/');
	}
    else if (x == 1 && y != 1)
	{
        left(y);
		return;
	}
    else if (y == 1 && x != 1)
	{
		top(x);
		return;
	}
    else
	{
        top(x);
        middle(x, y);
        bottom(x);
	}
}


void	top(int x)
{
	putchar('/');
	int i = 0;
	while (i < (x - 2))
	{
		putchar('*');
		i++;
	}
	putchar('\\');
	putchar('\n');
}

void	middle(int x, int y)
{
	int j = 0;
	while (j < (y - 2))
	{
		putchar('*');
		int i = 0;
		while (i < (x - 2))
		{
			putchar(' ');
		/*	putchar(' ');*/
				
			i++;
		}
		putchar('*');
		putchar('\n');
		j++;
	}
}

void	bottom(int x)
{
	putchar('\\');
	int i = 0;
	while (i < (x - 2))
	{
		putchar('*');
		i++;
	}
	putchar('/');
	putchar('\n');
}

void	left(int x)
{
	putchar('/');
	putchar('\n');
	int i = 0;
	while (i < (x - 2))
	{
		putchar('*');
		putchar('\n');
		i++;
	}
	putchar('\\');
	putchar('\n');
}
