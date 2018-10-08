# ajoutez vos programmes ci-dessous
PROGS_SRC=testContexte.cpp

SRC=freqs.cpp utils.cpp
OBJ=${SRC:.cpp=.o}
HEADERS=freqs.h utils.h
PROGS=${PROGS_SRC:.cpp=}
CPPFLAGS=-O3 -g -Wall

all: ${PROGS}

%.o: %.cpp %.h
	g++ ${CPPFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
