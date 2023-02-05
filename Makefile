all: a1

a1: Room.o Date.o Reservation.o Student.o Library.o
	g++ -o a1 a1-global.cc Room.o Date.o Reservation.o Student.o Library.o

Room.o: Room.h Room.cc
	g++ -c -g Room.cc

Date.o: Date.h Date.cc
	g++ -c -g Date.cc

Reservation.o: Reservation.h Reservation.cc Room.h Student.h Date.h
	g++ -c -g Reservation.cc

Student.o: Student.h Student.cc
	g++ -c -g Student.cc

Library.o: Library.h Library.cc
	g++ -c -g Library.cc

clean:
	rm -f *.o
	rm -f main
