#include <ft_printf.h>
#include <libft.h>

int			write_char_fake(int fd, wint_t c, t_fmt_spec *fmt)
{
	int		l;
	int		n;
	char	*s;

	l = 1 + (c > 0x7F) + (c > 0x7FF) + (c > 0xFFFF);
	n = fmt->mfw > l ? fmt->mfw : l;
	if (!(s = malloc(sizeof(*s) * n)))
		return (-1);
	if (fmt->f.j)
	{
		*s = c < 0 ? '?' : c;
		ft_memset(s + 1, ' ', n - l);
	}
	else
	{
		ft_memset(s, fmt->f.z ? '0' : ' ', n - l);
		*(s + n - l) = c < 0 ? '?' : c;
	}
	write(fd, s, n - l + 1);
	free(s);
	return (n);
}


int			wstrlen_fake(wchar_t *ws, t_fmt_spec * const fmt)
{
	int		l;
	int		fake_l;
	int		n;

	l = 0;
	fake_l = 0;
	while (*ws && *ws != 0xC080)
	{
		n = 1 + (*ws > 0x7F) + (*ws > 0x7FF) + (*ws > 0xFFFF);
		if (fmt->prc >= 0 && l + n > fmt->prc)
			break ;
		l += n;
		fake_l++;
		ws++;
	}
	return (fake_l);
}

void		wscpy_fake(char *s, wchar_t * ws, int l)
{
	while (l-- > 0)
		*(s++) = *(ws++);
}

int			write_wstr_fake(int fd, wchar_t *ws, t_fmt_spec *fmt)
{
	char	*s;
	int		l;
	int		fake_l;
	int		n;

	if (!ws)
		ws = L"(null)";
	l = wstrlen(ws, fmt);
	n = fmt->mfw > l ? fmt->mfw : l;
	if (!(s = malloc(sizeof(*s) * n)))
		return (-1);
	fake_l = wstrlen_fake(ws, fmt);
	if (fmt->f.j)
	{
		wscpy_fake(s, ws, fake_l);
		ft_memset(s + fake_l, ' ', n - l);
	}
	else
	{
		ft_memset(s, fmt->f.z ? '0' : ' ', n - l);
		wscpy_fake(s + n - l, ws, fake_l);
	}
	write(fd, s, n - l + fake_l);
	free(s);
	return (n);
}
