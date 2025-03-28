#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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
	int len = 0;

	if (!format)
	{
		exit(98);
		return (-1);
	}

	va_start(list, format);
	while (format[index] != '\0')
	{
		if (!format[index + 1] == '%')
		{
			exit(98);
			return (-1);
		}
		while (format[index] != '%')
		{
			_putchar(*format);
			index++;
		}
		index++;

