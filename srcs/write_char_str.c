#include <ft_printf.h>
#include <libft.h>

static int	wctombish(uint32_t wc, char **a)
{
	char	b[5];

	ft_bzero(b, 5);
	if (wc <= 0x7F)
		b[0] = wc;
	else if (wc <= 0x7FF)
	{
		b[0] = 0xC0 | (wc >> 6);
		b[1] = 0x80 | (wc % 64);
	}
	else if (wc <= 0xFFFF)
	{
		b[0] = 0xE0 | (wc >> 12);
		b[1] = 0x80 | ((wc % 4096) >> 6);
		b[2] = 0x80 | (wc % 64);
	}
	else if (wc <= 0x10FFFF)
	{
		b[0] = 0xF0 | (wc >> 18);
		b[1] = 0x80 | ((wc % 262144) >> 12);
		b[2] = 0x80 | ((wc % 4096) >> 6);
		b[3] = 0x80 | (wc % 64);
	}
	ft_strcpy(*a, b);
	return (1 + (wc > 0x7F) + (wc > 0x7FF) + (wc > 0xFFFF));
}

int			write_char(int fd, wint_t c, t_fmt_spec *fmt)
{
	int		l;
	int		n;
	char	*s;

	c = c < 0 ? '?' : c;
	l = 1 + (c > 0x7F) + (c > 0x7FF) + (c > 0xFFFF);
	n = fmt->mfw > l ? fmt->mfw : l;
	if (!(s = malloc(sizeof(*s) * n)))
		return (-1);
	if (fmt->f.j)
	{
		wctombish(c, &s);
		ft_memset(s + l, ' ', n - l);
	}
	else
	{
		ft_memset(s, fmt->f.z ? '0' : ' ', n - l);
		l = n - l > 0 ? n - l : 0;
		s += l;
		wctombish(c, &s);
		s -= l;
	}
	write(fd, s, n);
	free(s);
	return (n);
}

int			write_str(int fd, char *s, t_fmt_spec *fmt)
{
	char	*s2;
	int		l;
	int		n;

	if (!s)
		s = "(null)";
	l = ft_strlen(s);
	l = fmt->prc >= 0 && l > fmt->prc ? fmt->prc : l;
	n = fmt->mfw > l ? fmt->mfw : l;
	if (!(s2 = malloc(sizeof(*s2) * n)))
		return (-1);
	if (fmt->f.j)
	{
		ft_memcpy(s2, s, l);
		ft_memset(s2 + l, ' ', n - l);
	}
	else
	{
		ft_memset(s2, fmt->f.z ? '0' : ' ', n - l);
		ft_memcpy(s2 + n - l, s, l);
	}
	write(fd, s2, n);
	free(s2);
	return (n);
}

int			wstrlen(wchar_t *ws, t_fmt_spec * const fmt)
{
	int		l;
	int		n;

	l = 0;
	while (*ws && *ws != 0xC080)
	{
		n = 1 + (*ws > 0x7F) + (*ws > 0x7FF) + (*ws > 0xFFFF);
		if (fmt->prc >= 0 && l + n > fmt->prc)
			break ;
		l += n;
		ws++;
	}
	return (l);
}

void		wscpy(char *s, wchar_t * ws, int l)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (l > 0)
	{
		s += n;
		n = wctombish(*ws, &s);
		l -= n;
		ws++;
	}
}

int			write_wstr(int fd, wchar_t *ws, t_fmt_spec *fmt)
{
	char	*s;
	int		l;
	int		n;

	if (!ws)
		ws = L"(null)";
	l = wstrlen(ws, fmt);
	n = fmt->mfw > l ? fmt->mfw : l;
	if (!(s = malloc(sizeof(*s) * n)))
		return (-1);
	if (fmt->f.j)
	{
		wscpy(s, ws, l);
		ft_memset(s + l, ' ', n - l);
	}
	else
	{
		ft_memset(s, fmt->f.z ? '0' : ' ', n - l);
		wscpy(s + n - l, ws, l);
	}
	write(fd, s, n);
	free(s);
	return (n);
}

int			write_wchar_fake(int fd, wint_t c, t_fmt_spec *fmt)
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
		*s = c;// < 0 ? '?' : c;
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
