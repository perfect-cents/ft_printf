CC := gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I$(INC)
NAME = libft.a
CONV = atoi itoa im_ttoa itoa_base uim_ttoa
ISTO = isalnum isalpha isascii isdigit isprint isspace \
tolower toupper
MATH = abs abs_uim_t
MEM = bzero memalloc memccpy memchr memcmp memcpy memdel memdup memfree memjoin \
memmove memset
OUT = putchar putchar_fd putendl putendl_fd putlst putnbr putnbr_fd putstr \
putstr_fd putlst
STR = strcat strchr strclr strcmp strcpy strdel strdup \
strequ striter striteri strjoin strlcat strlcpy strlen strmap strmapi strncat \
strncmp strncpy strndup strnequ strnew strnstr strntilcpy strrchr strsplit \
strstr strsub strtrim
STR2 = append_n_char cut_n_char prepend_str append_str \
prepend_n_char
LIST = lstadd lstdel lstdelone lstdup lstdupone lstiter \
lstlen lstmap lstnew lstpop lstpush lstshift
OTHER = get_next_line
OBJ = $(addsuffix .o,$(addprefix ft_,$(CONV) $(ISTO) $(MATH) $(MEM) $(OUT) \
$(STR) $(STR2) $(LIST)) $(OTHER))
SRCDIR = srcs
INC = includes

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: $(SRCDIR)/%.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean | all

.PHONY: clean fclean re
