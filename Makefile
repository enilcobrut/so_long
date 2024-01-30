# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 07:55:48 by cjunker           #+#    #+#              #
#    Updated: 2022/08/28 20:55:37 by cjunker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	=	main.c \
			src/ft_printf.c \
			src/ft_utils.c \
			src/parse_error.c \
			src/start.c \
			gnl/get_next_line.c \
			src/fill_map.c \
			src/start2.c \
			src/move.c \
			src/ft_itoa.c \
			src/animate.c \
			src/print_img.c \
			src/ft_norme.c \
			src/game.c \

BONUS	=   bonus/main_bonus.c \
			bonus/ft_printf_bonus.c \
			bonus/ft_utils_bonus.c \
			bonus/parse_error_bonus.c \
			bonus/start_bonus.c \
			bonus/get_next_line_bonus.c \
			bonus/fill_map_bonus.c \
			bonus/start2_bonus.c \
			bonus/move_bonus.c \
			bonus/ft_itoa_bonus.c \
			bonus/animate_bonus.c \
			bonus/print_img_bonus.c \
			bonus/ft_norme_bonus.c \
			bonus/game_bonus.c \
			bonus/patrol.c \
			bonus/fire_ball.c \
			bonus/ft_normebonus2.c \

OBJS 	=	${SRC:.c=.o}

BONUS_OBJS = $(BONUS:.c=.o)

REMAKE = @make --no-print-directory

NAME	=	so_long

CC		=	gcc

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit -lz

CFLAGS 	=	-Wall -Wextra -Werror

RM	 	=	rm -f

ifdef SO_LONG_BONUS
	ALL_OBJS = $(BONUS_OBJS)
else
	ALL_OBJS = $(OBJS)
endif

all: ${NAME}

${NAME}:	${ALL_OBJS}
			$(CC) $(ALL_OBJS) $(FLAGSMLX) $(CFLAGS) -o $(NAME)

%.o:		%.c
			${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}_sanitize:	${OBJS}
			$(CC) $(SRC) -g -fsanitize=address $(FLAGSMLX) $(CFLAGS) -o $(NAME)_sanitize

${NAME}_debug:	${BONUS_OBJS}
			$(CC) $(BONUS) -g $(FLAGSMLX) $(CFLAGS) -o $(NAME)_debug

sanitize: ${NAME}_sanitize
debug: ${NAME}_debug

clean:
			${RM} ${OBJS} ${NAME}_sanitize ${NAME}_debug $(BONUS_OBJS)

fclean:		clean
			${RM} ${NAME}
                                                                   
re:			fclean $(NAME)

bonus:
	$(REMAKE) SO_LONG_BONUS=1 all

.PHONY:		all clean fclean re bonus
