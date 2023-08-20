#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *p = format;

    while (*p != '\0') {
        if (*p == '%') {
            p++;  // Move past the '%'

            // Handle the conversion specifier
            switch (*p) {
                case 'c':
                    // Fetch the next argument and print it as a character
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    // Fetch the next argument and print it as a string
                    count += printf("%s", va_arg(args, const char *));
                    break;
                case '%':
                    // Print a literal '%'
                    putchar('%');
                    count++;
                    break;
                default:
                    // Invalid conversion specifier, skip it
                    break;
            }
        } else {
            putchar(*p);
            count++;
        }

        p++;
    }

    va_end(args);
    return count;
}
