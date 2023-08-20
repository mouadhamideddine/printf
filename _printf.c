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
 * _print_number - Prints a number to stdout
 * @n: The number to print
 * @base: The base for conversion (e.g., 10 for decimal, 2 for binary)
 *
 * Return: The number of digits printed
 */
int _print_number(unsigned int n, int base)
{
	const char *digits = "0123456789ABCDEF";
	int len = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	if (base == 2)
	{
		len += _print_number(n / 2, base);
		_putchar((n % 2) + '0');
		len++;
	}
	else if (base == 10)
	{
		if (n / 10)
			len += _print_number(n / 10, base);

		_putchar((n % 10) + '0');
		len++;
	}
	else if (base == 16)
	{
		if (n / 16)
			len += _print_number(n / 16, base);

		_putchar(digits[n % 16]);
		len++;
	}

	return (len);
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
				case 'd':
				case 'i':
					len += _print_number(va_arg(args, int), 10);
					break;
				case 'b':
					len += _print_number(va_arg(args, unsigned int), 2);
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
