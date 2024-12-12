# Nome do executável
NAME = so_long

# Diretórios
SRCDIR = src
OBJDIR = obj
LIBFT_DIR = libft

# Arquivos
SRC = $(shell find $(SRCDIR) -type f -name "*.c")
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a
GNL_SRC = $(LIBFT_DIR)/get_next_line.c
GNL_OBJ = $(GNL_SRC:$(LIBFT_DIR)/%.c=$(OBJDIR)/libft/%.o)
CC = clang
CFLAGS = -g3 -Wall -Wextra -Werror -I$(LIBFT_DIR)
LDFLAGS = -lX11 -lXext -lmlx

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT)
	@echo "Linkando $(NAME)..."
	$(CC) $(OBJ) $(GNL_OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@echo "Compilando libft..."
	make -C $(LIBFT_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D) # Garante que o diretório existe
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/libft/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(@D) # Garante que o diretório existe
	@echo "Compilando $< (get_next_line)..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Limpando objetos..."
	rm -rf $(OBJDIR)

fclean: clean
	@echo "Removendo $(NAME)..."
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

test: $(SRC)
	@echo "Compilando para teste sem warnings..."
	$(CC) $^ $(LDFLAGS) -o $(NAME)

.PHONY: all clean fclean re valgrind
