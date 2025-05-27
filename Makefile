##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## the Makefile
##

CC ?= gcc

CFLAGS += -Wall -Wextra

NAME = wolf3d

SRC = 	src/main.c										\
		src/map/search.c								\
		src/map/open_map.c								\
		src/map/get_infos.c								\
		src/player/player.c								\
		src/player/rotations.c 							\
		src/player/movements.c							\
		src/memory/destroy.c							\
		src/memory/free.c								\
		src/init/init_map.c								\
		src/init/init_game.c							\
		src/init/init_weapon.c							\
		src/init/init_player.c							\
		src/init/init_textures.c						\
		src/algorithm/map.c								\
		src/algorithm/calculs.c							\
		src/algorithm/raycasting.c						\
		src/algorithm/handle_rays.c						\
		src/map/str_to_word_array.c						\
		src/enemies/move_enemy.c						\
		src/enemies/types/ghoul.c						\
		src/enemies/kill_enemies.c						\
		src/enemies/create_enemy.c						\
		src/display/background.c						\
		src/display/flashlight.c						\
		src/display/handle_weapon.c						\
		src/display/handle_enemies.c					\
		src/display/display_enemies.c					\
		src/display/calculs_enemy_pos.c					\
		src/display/animation/animate_enemy.c			\
		src/display/animation/animate_ghoul.c			\
		src/display/animation/animate_weapon.c			\
		src/display/animation/animate_explosion.c		\
		src/display/animation/weapons/init_shootgun.c	\
		src/events/handle_events.c						\
		src/events/shoot.c								\
		src/save/open_save.c							\

CPPFLAGS = -I./include/

LDLIBS	=	-lm -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
