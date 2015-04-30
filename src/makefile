CPP=g++
GCC=gcc
EXEC=optimiseur
CXXFLAGS= -Wall
SRC=  List.cpp Paire.cpp ListPaires.cpp DoubleListPaires.cpp conversions.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CPP) -o $@ $^


List.o: List.cpp List.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

Paire.o: Paire.cpp Paire.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

ListPaires.o: ListPaires.cpp ListPaires.h Paire.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

DoubleListPaires.o: DoubleListPaires.cpp DoubleListPaires.h List.h Paire.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

conversions.o: conversions.cpp conversions.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

# pour forcer clean/cleanall même s'il existe un fichier de même nom
.PHONY: clean cleanall

clean:
	rm -rf *.o

cleanall: clean
	rm -rf $(EXEC)
