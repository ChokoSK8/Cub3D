#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
FLAGS= -Wall -Wextra -Werror
FCTS= srcs/*.c

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)
		
test:	all
		gcc $(NOM) $(FLAGS) -framework OpenGL -framework AppKit check* dis* get* main.c init* utils* move_hero* game.h

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
