
TRGDIR=./
OBJ=./obj
FLAGS=  -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/kolko_krzyzyk
	${TRGDIR}/kolko_krzyzyk

${TRGDIR}/kolko_krzyzyk: ${OBJ} ${OBJ}/main.o ${OBJ}/Plansza.o
	g++ -o ${TRGDIR}/kolko_krzyzyk ${OBJ}/main.o ${OBJ}/Plansza.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Plansza.h
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Plansza.o: src/Plansza.cpp inc/Plansza.h
	g++ -c ${FLAGS} -o ${OBJ}/Plansza.o src/Plansza.cpp

clear:
	rm -f ${TRGDIR}/kolko_krzyzyk ${OBJ}/*