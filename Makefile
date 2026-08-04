
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libcrono.a
HEADER = libcrono.h

CFILES = power.c \
		strjoin.c \
		list.c \
		split.c \
		substr.c \
		get_free_split.c \
		splitlen.c \
		get_file_length.c \
		get_file_content.c \
		get_file_name.c \
		get_free_split.c \
		copy_file.c \
		putnbr_on_str.c \
		ltoa.c \
		print_split.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

install_header:
	sudo cp $(HEADER) "/usr/include/$(HEADER)"

uninstall_header:
	sudo rm "/usr/include/$(HEADER)"

install_debian: all install_header
	sudo cp $(NAME) "/usr/lib/x86_64-linux-gnu/$(NAME)"

uninstall_debian: uninstall_header
	sudo rm "/usr/lib/x86_64-linux-gnu/$(NAME)"

test: all
	cc test.c -o test -lcrono -L.

install_test: all install_debian
	cc test.c -o test -lcrono

.PHONY: all clean fclean re
