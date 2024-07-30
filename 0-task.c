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
	return 0;
}
