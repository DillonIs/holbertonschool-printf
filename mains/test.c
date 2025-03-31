#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int j = 0;
	int char_count = 0;

	va_start(list, format);
	while (format[i] != '\0')
	{
        // Watch out for any percentage symbols we may come across...
        if (format[i] == '%')
        {
            // we got a hit... what do we do next?
            // Let's try skipping the %d, %c, etc...

            if ((format[i+1] == 'd') || (format[i+1] == 'i') || (format[i+1] == 'c') || (format[i+1] == 'u'))
            {
                i = i + 2;
            }

            // This guy is special... only skip one char
            if (format[i+1] == '%')
            {
                i = i + 1;
            }
        }

        // Why is this located here?
        // Because if it's at the top it would print out the % before we had a chance to do anything to it.
        printf("%c", format[i]);

		i = i + 1;
	}
	va_end(list);

    return (char_count);
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

	return (0);
}
