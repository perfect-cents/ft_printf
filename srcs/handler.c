#include <ft_printf.h>
#include <libft.h>

int		parse_fmt_spec(char const * format, va_list ap, t_fmt_spec * const fmt)
{
	int	prog;

	prog = 1;
	prog += parse_flags(format + prog, fmt);
	prog += parse_min_field_width(format + prog, ap, fmt);
	prog += parse_precision(format + prog, ap, fmt);
	prog += parse_length_modifier(format + prog, fmt);
	if (!format[prog] || !parse_conversion_spec(format + prog, fmt))
		return (1);
	return (prog + 1);
}

intmax_t	signed_arg(va_list ap, t_fmt_spec const * const fmt)
{
	if (fmt->lm == lm_hh || fmt->cnv == 'c')
		return ((char)va_arg(ap, intmax_t));
	else if (fmt->lm == lm_h)
		return ((short)va_arg(ap, intmax_t));
	else if (fmt->lm == lm_none)
		return ((int)va_arg(ap, intmax_t));
	else if (fmt->lm == lm_l)
		return ((long)va_arg(ap, intmax_t));
	else if (fmt->lm == lm_ll)
		return ((long long)va_arg(ap, intmax_t));
	else if (fmt->lm == lm_j)
		return (va_arg(ap, intmax_t));
	else if (fmt->lm == lm_z)
		return ((ssize_t)va_arg(ap, intmax_t));
	else
		return (0);
}

uintmax_t	unsigned_arg(va_list ap, t_fmt_spec const * const fmt)
{
	if (fmt->cnv == 'p')
		return (va_arg(ap, uintptr_t));
	else if (fmt->lm == lm_hh)
		return ((unsigned char)va_arg(ap, uintmax_t));
	else if (fmt->lm == lm_h)
		return ((unsigned short)va_arg(ap, uintmax_t));
	else if (fmt->lm == lm_none)
		return ((unsigned int)va_arg(ap, uintmax_t));
	else if (fmt->lm == lm_l)
		return ((unsigned long)va_arg(ap, uintmax_t));
	else if (fmt->lm == lm_ll)
		return ((unsigned long long)va_arg(ap, uintmax_t));
	else if (fmt->lm == lm_j)
		return (va_arg(ap, uintmax_t));
	else if (fmt->lm == lm_z)
		return ((size_t)va_arg(ap, uintmax_t));
	else
		return (0);
}

int		handler(int fd, va_list ap, t_fmt_spec *fmt)
{
	intmax_t	d;
	uintmax_t	u;

	if (fmt->cnv == '%')
		return (write_char(fd, '%', fmt));
	else if (fmt->cnv == 'c' && fmt->lm == lm_l)
		return (write_char(fd, va_arg(ap, wint_t), fmt));
	else if (fmt->cnv == 'c')
		return (write_char(fd, (char)va_arg(ap, int), fmt));
	else if (fmt->cnv == 's' && fmt->lm == lm_l)
		return (write_wstr_fake(fd, va_arg(ap, wchar_t *), fmt));
	else if (fmt->cnv == 's')
		return (write_str(fd, va_arg(ap, char *), fmt));
	else if (ft_strchr("uboOxXp", fmt->cnv))
	{
		u = unsigned_arg(ap, fmt);
		return (write_nbr(fd, u, get_unsigned_prefix(u, fmt), fmt));
	}
	else if (fmt->cnv == 'd')
	{
		d = signed_arg(ap, fmt);
		return (write_nbr(fd, ft_abs_uim_t(d), get_signed_prefix(d, fmt), fmt));
	}
	else
		return (-1);
}
