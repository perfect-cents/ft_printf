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

