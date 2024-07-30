#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;
    char ch;
    int num;
    char buffer[50];
    int j;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    ch = va_arg(args, int);
                    write(1, &ch, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    if (num < 0)
                    {
                        write(1, "-", 1);
                        count++;
                        num = -num;
                    }
                    j = 0;
                    if (num == 0)
                    {
                        buffer[j++] = '0';
                    }
                    else
                    {
                        while (num != 0)
                        {
                            buffer[j++] = (num % 10) + '0';
                            num /= 10;
                        }
                    }
                    while (j > 0)
                    {
                        write(1, &buffer[--j], 1);
                        count++;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, &format[i], 1);
                    count++;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}

int main(void)
{
    _printf("Hello, %s! This is a custom %c function. And here is a percent sign: %%\n", "world", 'C');
    _printf("Here is an integer: %d and another: %i\n", 42, -42);
    return 0;
}
