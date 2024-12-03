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

# Compilador e flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Flags de linkagem
LDFLAGS = -lX11 -lXext -lmlx

# Regra principal
all: $(NAME)

# Compilar o jogo
$(NAME): $(OBJ)
	@echo "Linkando $(NAME)..."
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@echo "Compilando libft..."
	make -C $(LIBFT_DIR)

# Regra para compilar arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Criação do diretório de objetos
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/render
	@mkdir -p $(OBJDIR)/tests
	@mkdir -p $(OBJDIR)/map
	@mkdir -p $(OBJDIR)/handle_input

# Limpeza de objetos
clean:
	@echo "Limpando objetos..."
	rm -rf $(OBJDIR)

# Limpeza completa
fclean: clean
	@echo "Removendo $(NAME)..."
	rm -f $(NAME)

# Reconstruir tudo
re: fclean all

# Testar com Valgrind
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Testar sem flags
test: $(SRC)
	@echo "Compilando para teste sem warnings..."
	$(CC) $(TESTFLAGS) $^ $(LDFLAGS) -o $(NAME)

# Declaração de regras que não correspondem a arquivos
.PHONY: all clean fclean re valgrind
