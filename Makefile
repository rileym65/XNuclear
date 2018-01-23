PROJECT=nuclear
MAIN=main
INCLUDE=~/include/
MAINDEP= $(MAIN).cpp support.h
OBJECTS = $(MAIN).o support.o widgets.o
CC = c++ 
FLAGS = -c
LIBDIR = -L. -L/usr/X11/lib
LIBS = -lX11
DEFS = -DUNIX -DX -DWIDGETS

.SUFFIXES: .cpp

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) $(LIBDIR) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) -c $<


clean:
	rm *.o
	rm nuclear

