# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onkeltag <onkeltag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:19:08 by jcheron           #+#    #+#              #
#    Updated: 2025/01/05 16:48:06 by onkeltag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=		so_long
CC					:=		gcc
CFLAGS				:=		-Werror -Wall -Wextra -I libft -g
LDFLAGS				:=		-lX11 -lXext
RM					:=		rm -rf
LIBFT_PATH			:=		libft/
LIBFT				:=		libft/libft.a
MLX_PATH			:=		minilibx-linux/
MLX					:=		minilibx-linux/libmlx.a

SRCS				=		src/so_long.c					\
							src/utils/hooks.c				\
							src/utils/cleanup.c				\
							src/utils/read_map.c			\
							src/errors/exit_error.c			\
							src/map_utils/draw_map.c		\
							src/validations/validate_map.c	\
							src/player_utils/player_position.c

OBJS				:=		$(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o ${NAME}

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX) :
	@$(MAKE) -C $(MLX_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re : fclean all

norminette:
		@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
		&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
		|| $(ECHO) -e '\033[1;32mNorminette OK!'

.PHONY: all clean fclean re norminette
