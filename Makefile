# ajoutez vos programmes ci-dessous
PROGS_SRC=test-context.cpp cracker-tool.cpp rainbow-tool.cpp parameters-tool.cpp

SRC=Rainbow.cpp Context.cpp Cracker.cpp
OBJ=${SRC:.cpp=.o}
HEADERS=Rainbow.h Context.h Cracker.h
PROGS=${PROGS_SRC:.cpp=}
CPPFLAGS=-O3 -g -Wall

all: ${PROGS}

test-context: test-context.cpp ${OBJ} ${HEADERS}
	g++ ${CPPFLAGS} $< ${OBJ} -o $@ -lssl -lcrypto

cracker-tool: cracker-tool.cpp ${OBJ} ${HEADERS}
	g++ ${CPPFLAGS} $< ${OBJ} -o $@ -lssl -lcrypto

rainbow-tool: rainbow-tool.cpp ${OBJ} ${HEADERS}
	g++ ${CPPFLAGS} $< ${OBJ} -o $@ -lssl -lcrypto

parameters-tool: parameters-tool.cpp ${OBJ} ${HEADERS}
	g++ ${CPPFLAGS} $< ${OBJ} -o $@ -lssl -lcrypto

%.o: %.cpp %.h
	g++ ${CPPFLAGS} -c $<

clean:
	rm -f ${PROGS} ${OBJ}
