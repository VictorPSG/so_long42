# Nome do executável
NAME = so_long

# Diretórios
SRCDIR = src
OBJDIR = obj
LIBFT_DIR = libft

# Arquivos
SRC = $(wildcard $(SRCDIR)/*.c)              # Todos os .c em src
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC)) # Transforma src/*.c em obj/*.o
LIBFT = $(LIBFT_DIR)/libft.a                 # Caminho para a libft

# Compilador e flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -Ilibft

# Flags de linkagem
#LDFLAGS = -L$(LIBFT_DIR) -lft -lX11 -lXext -lmlx
LDFLAGS = -L -lft -lX11 -lXext -lmlx

# Regra principal
#all: $(LIBFT) $(NAME)
all: $(NAME)

# Compilar o jogo
$(NAME): $(OBJ)
	@echo "Linkando $(NAME)..."
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Compilar a libft
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

# Limpeza de objetos
clean:
	@echo "Limpando objetos..."
	rm -rf $(OBJDIR)
#	make clean -C $(LIBFT_DIR)

# Limpeza completa
fclean: clean
	@echo "Removendo $(NAME)..."
	rm -f $(NAME)
#	make fclean -C $(LIBFT_DIR)

# Reconstruir tudo
re: fclean all

# Testar com Valgrind
#valgrind: $(NAME)
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Testar sem flags
test: $(SRC)
	@echo "Compilando para teste sem warnings..."
	$(CC) $(TESTFLAGS) $^ $(LDFLAGS) -o $(NAME)

# Declaração de regras que não correspondem a arquivos
.PHONY: all clean fclean re valgrind
