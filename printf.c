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
	va_list args;
	int index = 0;
	char *s; 
	int count = 0;

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			if (!format[index + 1])
			{
				return (-1);
			}	
			switch(format[index + 1])
                	{
                        	case 'c' :
				_putchar (va_arg(args, int));
				count++;
				break;		
                        	case 's' : s = va_arg(args, char *);
				if (!s)
				{
					s = "(null)";
				}
				while (*s) 
				{
					_putchar(*s);
					s++;
					count++;
				}	   	   
				break;
				case 'd' : 
				count += printnum(va_arg(args,int));
				break;
				case 'i' : 
				count += printnum(va_arg(args,int));	   
				break;
				case '%' : va_arg(args, int);
				_putchar('%');
				count++;
			   	break;			
                        }
			index += 2;
			continue;
		}
		count += _putchar(format[index]);
		index++;
	}
	va_end(args);
	return (count);
}
