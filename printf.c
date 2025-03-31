#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 *_printf - formats and prints data
 *
 *return: (index) length of string
 *
 */
int _printf(const char *format, ...)
	{
	va_list list;
	int index = 0;
	unsigned int i;
	char *s; 

	if (!format)
	{
		return (-1);
	}

	va_start(list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (!format[index + 1])
			{
				return (-1);
			}	
			switch(format[index])
                	{
                        	case 'c' : i = va_arg(list, int);
				_putchar (i);
				break;	   
                        	case 's' : s = va_arg(list, char *);
				while (*s) 
				{
					_putchar(*s);
					s++;
				}	   	   
				break;
				case 'd' : printnum(va_arg(list,int));	   
				break;
				case 'i' : printnum(va_arg(list,int));	   
				break;
				case '%' : i = va_arg(list, int);
				_putchar('%');
		 		break;    		
                        }
			index++;
		}
		_putchar(format[index]);
		index++;
	}
	va_end(list);
	return (index);
}
