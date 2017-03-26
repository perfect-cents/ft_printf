/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpezeshk <bpezeshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:12:12 by bpezeshk          #+#    #+#             */
/*   Updated: 2017/02/09 16:41:09 by bpezeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
/*
** CONV FUNCTIONS
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, char *base_str);
char				*ft_im_ttoa_base(intmax_t n, char *base_str);
char				*ft_uim_ttoa_base(uintmax_t n, char *base_str);
/*
** ISTO FUNCTIONS
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
** MATH FUNCTIONS
*/
unsigned int		ft_abs(int nbr);
uintmax_t			ft_abs_uim_t(intmax_t nbr);
/*
** MEM FUNCTIONS
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memjoin(void *dst, size_t dlen, const void *src, \
size_t slen);
void				ft_memdel(void **ap);
void				*ft_memfree(void *ap);
/*
** OUT FUNCTIONS
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putlst(t_list *lst);
/*
** STR FUNCTIONS
*/
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strndup(const char *s1, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strntilcpy(char *dst, const char *src, size_t len);
/*
** STR2 FUNCTIONS
*/
int					ft_append_n_char(char **s, char c, size_t n);
int					ft_append_str(char **s1, char *s2);
int					ft_prepend_n_char(char **s, char c, size_t n);
int					ft_prepend_str(char **s1, char *s2);
int					ft_cut_n_char(char **s, size_t f, size_t b);
/*
** LIST FUNCTIONS
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstpush(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstshift(t_list **alst);
t_list				*ft_lstpop(t_list **alst);
t_list				*ft_lstdupone(t_list *lst);
t_list				*ft_lstdup(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** OTHER FUNCTIONS
*/
int					get_next_line(const int fd, char **line);
#endif
