#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *p = format;

    while (*p != '\0') {
        if (*p == '%') {
            p++;
            if (*p == 'c') {
                // Print a character
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*p == 's') {
                // Print a string
                const char *s = va_arg(args, const char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            }
            else if (*p == '%') {
                // Print a percent sign
                putchar('%');
                count++;
            }
        }
        else {
            // Print regular characters
            putchar(*p);
            count++;
        }

        p++;
    }

    va_end(args);

    return count;
}

