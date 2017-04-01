CC=gcc
CFLAGS+=-Wall -Wextra -Werror
CFLAGS+=-I $(INC)
CFLAGS+=-I $(LIBDIR)/$(INC)
OBJS = $(addsuffix .o,ft_printf handler parse write_char_str write_nbr)
SRCDIR = srcs
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
INC = includes
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar -rc $(NAME) $(OBJS)

%.o: $(SRCDIR)/%.c
	$(CC) $< -c -o $@ $(CFLAGS)

$(LIB):
	$(MAKE) -C $(LIBDIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBDIR) fclean
	find $(PWD) -type d -exec dot_clean -nm {} \;

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
