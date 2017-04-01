#include <ft_printf.h>
#include <libft.h>

void	get_base_l_init(t_nbr_l *len, t_fmt_spec *fmt, uintmax_t nbr)
{
	if ('o' == fmt->cnv)
		len->b = 8;
	else if (ft_strchr("xXp", fmt->cnv))
		len->b = 16;
	else if (fmt->cnv == 'b')
		len->b = 2;
	else
		len->b = 10;

	len->l = !!nbr;
	while (nbr /= len->b)
		len->l++;
}

void		refine_len(t_nbr_l *len, char **pfx, t_fmt_spec *fmt)
{
	len->p = ft_strlen(*pfx);

	if (fmt->prc < 0)
	{
		if (len->l < 1)
			len->l = 1;
		if (!fmt->f.j && fmt->f.z && len->l < (len->n = fmt->mfw - len->p))
			len->l = len->n;
	}
	else if (fmt->prc > len->l)
	{
		len->l = fmt->prc;
		if (ft_strequ(*pfx, "0"))
		{
			*pfx = "";
			len->p = 0;
		}
	}
	len->sc = len->l + len->p < fmt->mfw ? fmt->mfw - (len->l + len->p) : 0;
	len->n = len->l + len->p + len->sc;
}

void		nbrcpy(char **s, t_nbr_l *len, uintmax_t nbr, t_fmt_spec *fmt)
{
	char		*bs;

	bs = fmt->cnv == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (--len->l >= 0)
	{
		(*s)[len->l] = bs[nbr % len->b];
		nbr /= len->b;
	}
}

int			write_nbr(int fd, uintmax_t nbr, char * /*const*/ pfx, t_fmt_spec *fmt)
{
	t_nbr_l		len;
	char		*s;

	get_base_l_init(&len, fmt, nbr);
	refine_len(&len, &pfx, fmt);
	if (!(s = malloc(sizeof(*s) * len.n)))
		return (-1);
	if (fmt->f.j)
	{
		ft_memcpy(s, pfx, len.p);
		ft_memset(s + len.l + len.p, ' ', len.sc);
		s += len.p;
		nbrcpy(&s, &len, nbr, fmt);
		s -= len.p;
	}
	else
	{
		ft_memcpy(s + len.sc, pfx, len.p);
		ft_memset(s, ' ', len.sc);
		s += len.p + len.sc;
		nbrcpy(&s, &len, nbr, fmt);
		s -= len.p + len.sc;
	}
	write(fd, s, len.n);
	free(s);
	return (len.n);
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
