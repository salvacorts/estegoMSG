# Directorios

BIN= bin
SRC = src
INC = include
OBJ = obj
LIB= lib

# Configuracion del compilador

CXX = g++
AR= ar
LDFLAGS= -L
LDLIBS= -lesteganografia
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)

all: $(BIN)/ocultar $(BIN)/revelar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Generación de ejecutables ******************
$(BIN)/ocultar: $(LIB)/libesteganografia.a $(OBJ)/ocultar.o
	$(CXX) $(LDFLAGS)$(LIB) -o $(BIN)/ocultar $(OBJ)/ocultar.o $(LDLIBS)

$(BIN)/revelar: $(LIB)/libesteganografia.a $(OBJ)/revelar.o
	$(CXX) $(LDFLAGS)$(LIB) -o $(BIN)/revelar $(OBJ)/revelar.o $(LDLIBS)

# ************ Generación de librerías ******************
$(LIB)/libesteganografia.a: $(OBJ)/imagenES.o $(OBJ)/codificar.o
	$(AR) rvs $(LIB)/libesteganografia.a $(OBJ)/imagenES.o $(OBJ)/codificar.o

# ************ Compilación de módulos ******************
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o	

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INC)/codificar.h 
	$(CXX) -c $(CXXFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp
	$(CXX) -c $(CXXFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o

$(OBJ)/revelar.o: $(SRC)/revelar.cpp
	$(CXX) -c $(CXXFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o

# ************ Limpieza ******************
clean:
	-rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	-rm $(BIN)/ocultar $(BIN)/revelar doc/html/*
