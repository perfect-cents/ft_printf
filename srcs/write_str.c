#include <ft_printf.h>
#include <libft.h>

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
