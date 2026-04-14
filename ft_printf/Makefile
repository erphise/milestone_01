# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/07 22:47:21 by berhugue          #+#    #+#              #
#    Updated: 2026/04/07 22:47:21 by berhugue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de programa
NAME = libftprintf.a

# Archivos fuente para ft_printf
SRC = ft_printf.c ft_print_char.c ft_print_str.c ft_print_ptr.c ft_print_int.c ft_print_unsigned.c ft_print_lower_hex.c ft_print_upper_hex.c

# Archivos objeto generados a partir de los archivos listados en SRC
OBJ = $(SRC:.c=.o)

# Directorio y archivo de la biblioteca libft
LIBFT_DIR = ft_libft
LIBFT = $(LIBFT_DIR)/libft.a

# Incluye los headers necesarios para la compilación.
INCLUDE = ft_printf.h

# Compilador y opciones de compilación
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Comandos para crear la biblioteca y eliminar archivos
AR = ar rcs
RM = rm -f

# Regla principal: compilar todo
all: $(NAME)

# Compilar libft en su directorio con su propio Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Crear la biblioteca libftprintf.a uniendo libft.a con los objetos generados de las fuentes
$(NAME): $(OBJ)
	@make -C ft_libft
	@cp ft_libft/libft.a .
	@mv libft.a $(NAME)
	@ar -r $(NAME) $(OBJ)

# Regla para compilar archivos .c en .o
%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Regla para limpiar archivos objeto
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Regla para limpiar todo, incluyendo la biblioteca generada
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Regla para recompilar todo desde cero
re: fclean all

.PHONY: all clean fclean re
