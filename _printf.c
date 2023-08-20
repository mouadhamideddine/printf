#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c)
{
    return (write(1, &c, 1));
}

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
                    {
                        int num = va_arg(args, int);
                        if (num < 0) {
                            _putchar('-');
                            len++;
                            num = -num;
                        }
                        len += print_number(num);
                    }
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

    return len;
}

int print_number(int num)
{
    int len = 0;
    if (num / 10)
        len += print_number(num / 10);
    _putchar('0' + num % 10);
    len++;
    return len;
}
