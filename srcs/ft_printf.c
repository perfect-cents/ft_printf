#include <ft_printf.h>
#include <libft.h>

int		ft_vdprintf(int fd, char const * format, va_list ap)
{
	t_fmt_spec	fmt;
	int			printed;
	int			status;
	char const	*tail;

	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format += parse_fmt_spec(format, ap, &fmt);
			if ((status = fmt.valid) && (status = handler(fd, ap, &fmt)) < 0)
				return (-1);
			printed += status;
		}
		else
		{
			tail = format;
			while (*format && *format != '%')
				format++;
			printed += write(fd, tail, format - tail);
		}
	}
	va_end(ap);
	return (printed);
}

int		ft_printf(char const * format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_vdprintf(1, format, ap));
}

int		ft_dprintf(int fd, char const * format, ...)
{
	va_list		ap;

	va_start(ap, format);
	return (ft_vdprintf(fd, format, ap));
}
