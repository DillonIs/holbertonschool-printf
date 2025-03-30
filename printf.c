#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
	{
	va_list list;
	int index = 0;
	unsigned int i;
	char *s;
	int n;


	if (!format)
	{
		return (-1);
	}

	va_start(list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (!format[index + 1])
			{
				return (-1);
			}
		index = index + 1;	
		switch(format[index])
                	 {
                        	case 'c' : i = va_arg(list, int);
                                   _putchar (i);
                                   break;
                        	case 's' : s = va_arg(list, char *);
                                   puts(s);
                                   break;
                        	case '%' : i = va_arg(list, int);
                                   _putchar('%');
                                   break;
				case 'd' : n = printnum(va_arg(list,int));
				_putchar(n);
				break;
				case 'i' : n = printnum(va_arg(list,int));
				_putchar(n);
				break;
                        }
		index++;
		}
		_putchar(format[index]); /* taken this out of if loop */
		index++;
	}
	va_end(list);
	return (index); /* returning index instead of zero because theres a question that asks for length of string */
}
