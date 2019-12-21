#-----------------------------------------------------------------------------------
# Makefile
#-----------------------------------------------------------------------------------
# Luis Marcelo Chinea Rangel
# Correo: alu0101118116@ull.es
# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
#-----------------------------------------------------------------------------------

# Compilador
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

INCLUDE_DIR =include
OBJECTS_DIR=build
SRC_DIR =src
LIB_DIR =lib
BIN_DIR =bin

LIBS=-lm

_OBJ = sorted_vector.o main.o
OBJ = $(patsubst %,$(OBJECTS_DIR)/%,$(_OBJ))

BIN_NAME = Divide-and-Conquer

all: Divide-and-Conquer

Divide-and-Conquer: $(OBJ)
	$(CC) -o $(BIN_DIR)/$(BIN_NAME) $^ $(CFLAGS) $(LIBS)

$(OBJECTS_DIR)/sorted_vector.o: $(SRC_DIR)/sorted_vector.cpp  
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJECTS_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/sorted_vector.hpp
	$(CC) -c -o $@ $< $(CFLAGS)		

run:
	./$(BIN_DIR)/$(BIN_NAME) 

.PHONY: clean

clean:
	@rm -f $(OBJECTS_DIR)/*.o *~ $(INCLUDE_DIR)/*~ $(BIN_DIR)/*.exe
	@echo
	@echo "Objects Files and Executables cleaned!"
