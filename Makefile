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

# Arquivos do get_next_line
GNL_SRC = $(LIBFT_DIR)/get_next_line.c
GNL_OBJ = $(GNL_SRC:$(LIBFT_DIR)/%.c=$(OBJDIR)/libft/%.o)

# Compilador e flags
CC = clang
CFLAGS = -g3 -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Flags de linkagem
LDFLAGS = -lX11 -lXext -lmlx

# Regra principal
all: $(NAME)

# Compilar o jogo, incluindo os objetos do get_next_line
$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT)
	@echo "Linkando $(NAME)..."
	$(CC) $(OBJ) $(GNL_OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compilação da libft
$(LIBFT):
	@echo "Compilando libft..."
	make -C $(LIBFT_DIR)

# Regra para compilar arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D) # Garante que o diretório existe
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regras específicas para compilar os arquivos do get_next_line
$(OBJDIR)/libft/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(@D) # Garante que o diretório existe
	@echo "Compilando $< (get_next_line)..."
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de objetos
clean:
	@echo "Limpando objetos..."
	rm -rf $(OBJDIR)

# Limpeza completa
fclean: clean
	@echo "Removendo $(NAME)..."
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Reconstruir tudo
re: fclean all

# Testar com Valgrind
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Testar sem flags
test: $(SRC)
	@echo "Compilando para teste sem warnings..."
	$(CC) $^ $(LDFLAGS) -o $(NAME)

# Declaração de regras que não correspondem a arquivos
.PHONY: all clean fclean re valgrind
