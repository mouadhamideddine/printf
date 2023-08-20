#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, return 1. On error, return -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					len++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						str++;
						len++;
					}
					break;
				case '%':
					_putchar('%');
					len++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					len += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}

	va_end(args);

	return (len);
}
