#include <ft_printf.h>
#include <libft.h>

int			write_nbr(int fd, uintmax_t nbr, char * /*const*/ pfx, t_fmt_spec *fmt)
{
	int			l;
	int			p;
	int			sc;
	int			b;
	uintmax_t	t;
	int			n;
	char		*bs;
	char		*s;

	if ('o' == fmt->cnv)
		b = 8;
	else if (ft_strchr("xXp", fmt->cnv))
		b = 16;
	else if (fmt->cnv == 'b')
		b = 2;
	else
		b = 10;

	t = nbr;
	l = !!t;
	while (t /= b)
		l++;

	p = ft_strlen(pfx);

	if (fmt->prc < 0)
	{
		if (l < 1)
			l = 1;
		if (fmt->f.z && l < (n = fmt->mfw - p))
			l = n;
	}
	else if (fmt->prc > l)
	{
		l = fmt->prc;
		if (ft_strequ(pfx, "0"))
		{
			pfx = "";
			p = 0;
		}
	}

	sc = l + p < fmt->mfw ? fmt->mfw - (l + p) : 0;

	n = l + p + sc;

	if (!(s = malloc(sizeof(*s) * n)))
		return (-1);

	bs = fmt->cnv == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";

	if (fmt->f.j)
	{
		ft_memcpy(s, pfx, p);
		ft_memset(s + l + p, ' ', sc);
		s += p;
		while (--l >= 0)
		{
			s[l] = bs[nbr % b];
			nbr /= b;
		}
		s -= p;
	}
	else
	{
		ft_memcpy(s + sc, pfx, p);
		ft_memset(s, ' ', sc);
		s += p + sc;
		while (--l >= 0)
		{
			s[l] = bs[nbr % b];
			nbr /= b;
		}
		s -= p + sc;
	}

	write(fd, s, n);
	free(s);
	return n;
}

char		*get_signed_prefix(intmax_t nbr, t_fmt_spec *fmt)
{
	if (nbr < 0)
		return ("-");
	else if (fmt->f.p)
		return ("+");
	else if (fmt->f.s)
		return (" ");
	else
		return ("");
}

char		*get_unsigned_prefix(uintmax_t nbr, t_fmt_spec *fmt)
{
	if (ft_strchr("oxXp", fmt->cnv))
	{
		if (fmt->cnv == 'p')
			return ("0x");
		if (fmt->f.h && nbr)
		{
			if (fmt->cnv == 'x')
				return ("0x");
			else if (fmt->cnv == 'X')
				return ("0X");
		}
		if (fmt->cnv == 'o' && fmt->f.h && ((!nbr && !fmt->prc) || nbr))
			return ("0");
	}
	return ("");
}
