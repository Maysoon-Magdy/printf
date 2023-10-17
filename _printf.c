#include "main.h"
/**
 * define_printf_format - Afunction to defint the format string
 * @format: the format string
 * @args_List: the list of arguments
 *
 * Return: number of char
 */
int define_printf_format(const char *format, va_list args_List)
{
	int char_len, s_len;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_len++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_len++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_List, int);

				write(1, &c, 1);
				char_len++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args_List, char*);

				s_len = strlen(s);
				write(1, s, s_len);
				char_len += s_len;
			}
		}
		format++;
	}
	return (char_len);
}


/**
 * clear - A function that cleaning printf.
 *@args_List: the argument list instialized
 */
void clear(va_list args_List)
{
	va_end(args_List);
}


/**
 * _printf - a funtion that prints the given values
 * @format: string to be printed
 *
 * Return: the length of printed string
 */
int _printf(const char *format, ...)
{
	va_list args_List;
	int char_ret = 0;

	if (format == NULL)
		return (-1);

	va_start(args_List, format);
	char_ret = define_printf_format(format, args_List);
	clear(args_List);
	return (char_ret);
}

