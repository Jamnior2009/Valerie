all: main.exe

main.exe: main.o 
	g++ main.o -o main.exe

main.o:
	g++ -c main.cpp -o main.o

run:
	./main.exe

clean:
	rm -f *.o *.exe

.PHONY: all run clean