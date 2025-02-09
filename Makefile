##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC 	?=	gcc

SRC	=	src/ht_delete.c						\
		src/search.c						\
		src/dump.c							\
		src/insert.c						\
		src/delete_hashtable.c				\
		src/hash_table.c					\
		src/convert_base.c					\
		src/hash_function.c					\
		lib/my/mini_printf.c				\
		lib/my/my_compute_power_rec.c		\
		lib/my/my_compute_square_root.c		\
		lib/my/my_find_prime_sup.c			\
		lib/my/my_getnbr.c					\
		lib/my/my_is_prime.c				\
		lib/my/my_putchar.c					\
		lib/my/my_put_nbr.c					\
		lib/my/my_putstr.c					\
		lib/my/my_revstr.c					\
		lib/my/my_showmem.c					\
		lib/my/my_showstr.c					\
		lib/my/my_sort_int_array.c			\
		lib/my/my_strcapitalize.c			\
		lib/my/my_strcat.c					\
		lib/my/my_strcmp.c					\
		lib/my/my_strcpy.c					\
		lib/my/my_strdup.c					\
		lib/my/my_str_isalpha.c				\
		lib/my/my_str_islower.c				\
		lib/my/my_str_islower.c				\
		lib/my/my_str_isnum.c				\
		lib/my/my_str_isprintable.c			\
		lib/my/my_str_isupper.c				\
		lib/my/my_strlen.c					\
		lib/my/my_strlowcase.c				\
		lib/my/my_strncat.c					\
		lib/my/my_strncmp.c					\
		lib/my/my_strcpy.c					\
		lib/my/my_strstr.c					\
		lib/my/my_strupcase.c				\
		lib/my/my_swap.c					\
		lib/my/my_str_to_word_array.c		\
		lib/my/my_sqrt.c

CFLAGS += -Wall -Wextra -g3

OBJ     =   $(SRC:.c=.o)

NAME    =	libhashtable.a

all:	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)

clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) coding-style*
	$(RM) *~
	$(RM) *#
	$(RM) *.o
	$(RM) src/*~
	$(RM) src/#*
	$(RM) include/*#
	$(RM) include/*~
	$(RM) ./test
fclean: clean
	make fclean -C lib/my/
	$(RM) $(NAME)
	$(RM) ./lib/my/libmy.a
	$(RM) libmy.a

re:	fclean all

test:	re
	$(CC) -o test -g3 $(CFLAGS) tests/main.c -L . -lhashtable

.PHONY: all clean fclean re test
