# ajoutez vos programmes ci-dessous
PROGS_SRC=testeContexte.cpp

SRC=ArcEnCiel.cpp Contexte.cpp Cracker.cpp
OBJ=${SRC:.cpp=.o}
HEADERS=ArcEnCiel.h Contexte.h Cracker.h
PROGS=${PROGS_SRC:.cpp=}
CPPFLAGS=-O3 -g -Wall

all: ${PROGS}

testeContexte: testeContexte.cpp ${OBJ} ${HEADERS}
	g++ ${CPPFLAGS} $< ${OBJ} -o $@ -lssl -lcrypto

%.o: %.cpp %.h
	g++ ${CPPFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
