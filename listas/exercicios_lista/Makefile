CC = gcc
CFLAGS = -Wall -Wextra -g

# Nome do executável final
EXEC = programa

# Arquivos objeto necessários
OBJS = main.o lista.o

# Regra padrão (a primeira do arquivo é a que roda com "make")
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra genérica: como gerar um .o a partir de um .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos gerados
clean:
	rm -f $(EXEC) $(OBJS)

# Roda o programa depois de compilar
run: $(EXEC)
	./$(EXEC)