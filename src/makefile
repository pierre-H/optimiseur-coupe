CPP=g++
GCC=gcc
EXEC=optimiseur
CXXFLAGS= -Wall -DDEBUG
SRC=  List.cpp Paire.cpp MoteurCalculs.cpp Combinaison.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CPP) -o $@ $^


List.o: List.cpp List.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

Paire.o: Paire.cpp Paire.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

	
Combinaison.o: Combinaison.cpp Combinaison.h  Paire.h List.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

MoteurCalculs.o: MoteurCalculs.cpp MoteurCalculs.h List.h Paire.h
	$(CPP) -o $@ -c $< $(CXXFLAGS)

# pour forcer clean/cleanall même s'il existe un fichier de même nom
.PHONY: clean cleanall

clean:
	rm -rf *.o

cleanall: clean
	rm -rf $(EXEC)
