#include <ft_printf.h>
#include <libft.h>

int		parse_flags(char const * format, t_fmt_spec * const fmt)
{
	int	prog;

	fmt->f.h = 0;
	fmt->f.j = 0;
	fmt->f.p = 0;
	fmt->f.s = 0;
	fmt->f.z = 0;
	prog = 0;
	while (1)
	{
		if (*format == '#')
			fmt->f.h = 1;
		else if (*format == '-')
			fmt->f.j = 1;
		else if (*format == '+')
			fmt->f.p = 1;
		else if (*format == ' ')
			fmt->f.s = 1;
		else if (*format == '0')
			fmt->f.z = 1;
		else
			return (prog);
		format++;
		prog++;
	}
}

int		parse_min_field_width(char const * format, va_list ap, t_fmt_spec * const fmt)
{
	int	prog;

	prog = 0;
	if (*format == '*')
	{
		fmt->mfw = va_arg(ap, int);
		return (1);
	}
	fmt->mfw = 0;
	while (ft_isdigit(*format))
	{
		fmt->mfw *= 10;
		fmt->mfw += *format - '0';
		format++;
		prog++;
	}
	return (prog);
}

int		parse_precision(char const * format, va_list ap, t_fmt_spec * const fmt)
{
	int	prog;

	fmt->prc = -1;
	if (*format != '.')
		return (0);
	format++;
	fmt->prc = 0;
	if (*format == '*')
	{
		fmt->prc = va_arg(ap, int);
		return (2);
	}
	prog = 1;
	while (ft_isdigit(*format))
	{
		fmt->prc *= 10;
		fmt->prc += *format - '0';
		format++;
		prog++;
	}
	return (prog);
}

int		parse_length_modifier(char const * format, t_fmt_spec * const fmt)
{
	if (ft_strnequ(format, "hh", 2))
		fmt->lm = lm_hh;
	else if (ft_strnequ(format, "ll", 2))
		fmt->lm = lm_ll;
	else if (*format == 'h')
		fmt->lm = lm_h;
	else if (*format == 'l')
		fmt->lm = lm_l;
	else if (*format == 'j')
		fmt->lm = lm_j;
	else if (*format == 'z')
		fmt->lm = lm_z;
	else
	{
		fmt->lm = lm_none;
		return (0);
	}
	return ((fmt->lm == lm_hh || fmt->lm == lm_ll) + 1);
}

int		parse_conversion_spec(char const * format, t_fmt_spec * const fmt)
{
	if (ft_strchr("SC", *format))
	{
		fmt->cnv = ft_tolower(*format);
		fmt->lm = lm_l;
	}
	else if (ft_strchr("DUO", *format))
	{
		fmt->cnv = ft_tolower(*format);
		fmt->lm = lm_l;
	}
	else if (ft_strchr("spdiouxX%cb", *format))
	{
		fmt->cnv = *format == 'i' ? 'd' : *format;
		fmt->lm = fmt->cnv == 'p' ? lm_ll : fmt->lm;
		fmt->f.h += fmt->cnv == 'p';
	}
	else
		return (0);
	return (1);
}

