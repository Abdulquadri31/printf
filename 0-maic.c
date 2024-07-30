#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
	_printf("Hello, %s! This is a custom %c function. And here is a percent sign: %%\n", "world", 'C');
	return 0;
}
