#include "main.h"

int printnum(int n)
{
        int num;
	int count = 0;

	if (n < 0)
	{
	       	_putchar('-');
		num = -n;
		count++;
        }
	else
	{
		num = n;
        }
        if (num / 10)
	{
		count += printnum(num / 10);
	}
	_putchar (num % 10 + '0');
	count++;
	return (count);
}
