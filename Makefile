SRC = $(wildcard *.c)

OBJ = $(SRC:%.c=%.o)
NAME = libft.a

all: compile

compile: $(OBJ)
	gcc -lmlx -framework OpenGL -framework AppKit -L. -lft $(OBJ) && ./a.out

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm -f $(OBJ)

.PHONY: all clean compile
