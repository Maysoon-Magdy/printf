#include "main.h"
/**
 * _printf - a funtion that prints the given values
 * @format: string to be printed
 *
 * Return: the length of printed string
 */
int _printf(const char *format, ...)
{
	va_list args_List;
	int char_len , s_len= 0;

	if (format == NULL)
		return (-1);

	va_start(args_List, format);

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

					char c= va_arg(args_List, int);
					write(1, &c, 1);
					char_len++;
				}
				else if (*format == 's')
				{

					char *s= va_arg(args_List, char*);
					s_len = strlen(s);
					write(1, s, s_len);
					char_len += s_len;
				}

		}
		format++;
	}

	va_end(args_List);
	return (char_len);
}

