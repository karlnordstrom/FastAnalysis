## Makefile for ROOT stuff
## Suppressing output since the library links are massive

FLAGS=-g -Wall -O3

## You need to give the path to your boost headers here.
## See README.md for more instructions
MY_INCS=-I$(shell pwd)/include
MY_LIBS=

## This NEEDS to be set somewhere your linker searches (aka LD_LIBRARY_PATH)
## See README.md for more instructions
MY_LD_LIBRARY_PATH=/home/karl/local/lib/

THIS_LIB=-L$(shell pwd)/lib -lFastAnalysis

ROOT_INCS=$(shell root-config --cflags)
ROOT_LIBS=$(shell root-config --libs)

all: library

library: Utils.o FourMomentum.o Selectors.o LheReader.o
	@echo "Linking library..."
	@g++ -shared -Wl,-soname -o ./lib/libFastAnalysis.so $< -lc $(MY_INCS) $(MY_LIBS) $(ROOT_INCS) $(ROOT_LIBS)
	@cp -f ./lib/libFastAnalysis.so $(MY_LD_LIBRARY_PATH)
	@rm Utils.o
	@rm FourMomentum.o
	@rm Selectors.o
	@rm LheReader.o

FourMomentum.o: ./src/FourMomentum.cc ./include/FourMomentum.hh
	@echo "Building FourMomentum..."
	@g++ $(FLAGS) -c -fPIC ./src/FourMomentum.cc -o FourMomentum.o $(MY_INCS) $(MY_LIBS) $(ROOT_INCS) $(ROOT_LIBS)

Utils.o: ./src/Utils.cc ./include/Utils.hh
	@echo "Building Utils..."
	@g++ $(FLAGS) -c -fPIC ./src/Utils.cc -o Utils.o $(MY_INCS) $(MY_LIBS) $(ROOT_INCS) $(ROOT_LIBS)

Selectors.o: ./src/Selectors.cc ./include/Selectors.hh
	@echo "Building Selectors..."
	@g++ $(FLAGS) -c -fPIC ./src/Selectors.cc -o Selectors.o $(MY_INCS) $(MY_LIBS) $(ROOT_INCS) $(ROOT_LIBS)

LheReader.o: ./src/LheReader.cc ./include/LheReader.hh
	@echo "Building LheReader..."
	@g++ $(FLAGS) -c -fPIC ./src/LheReader.cc -o LheReader.o $(MY_INCS) $(MY_LIBS) $(ROOT_INCS) $(ROOT_LIBS)

clean:
	@rm ./lib/libFastAnalysis.so || :
	@echo "Removed binaries and library."
