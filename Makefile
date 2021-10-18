CXX = g++ 
CFLAGS = -Wall -Iinclude  -std=c++11 
LFLAGS = -Wall

DEBUG = 0

SRC = $(wildcard src/*.cpp src/*/*.cpp)
OBJ = $(patsubst %.cpp, build/%.o, $(SRC))


ifeq ($(DEBUG), 1)
	CFLAGS += -g -O0
else
	CFLAGS += -O3
endif

.PHONY: all clean

all: compilador

clean:
	@rm -rf build/*
	@rm -f *.run


compilador: $(OBJ) build/src/libcsv.o
	$(CXX) $(LFLAGS) $(OBJ) build/src/libcsv.o -o $@

build/src/%.o: src/%.cpp
	@echo
	@echo $@
	@echo 
	mkdir -p $(@D)
	$(CXX) -c $(CFLAGS) $(patsubst build/%.o, %.cpp, $(@)) -o $(@)

build/src/libcsv.o: src/libcsv.c
	@echo
	@echo $@
	@echo 
	mkdir -p $(@D)
	gcc -c -Wall -Iinclude $(patsubst build/%.o, %.c, $(@)) -o $(@)

build/src/analisadores/analisador_lexico.o: include/analisador_lexico.h
build/src/analisadores/analisador_sintatico.o: include/analisador_sintatico.hpp
build/src/analisadores/analisador_sintatico.o: include/analisador_lexico.h
build/src/main.o: include/analisador_lexico.h include/analisador_sintatico.hpp
build/src/main.o: include/analisador_escopo.hpp 