CPU.out : decoder.o instruction.o labels.o main.o reader.o registers.o word.o data.o memory.o
	g++ -ansi -Wall -g -o CPU.out decoder.o instruction.o labels.o main.o reader.o registers.o word.o data.o memory.o

decoder.o : decoder.cpp decoder.h instruction.h registers.h labels.h memory.h
	g++ -ansi -Wall -g -c decoder.cpp

instruction.o : instruction.cpp instruction.h 
	g++ -ansi -Wall -g -c instruction.cpp

labels.o : labels.cpp labels.h 
	g++ -ansi -Wall -g -c labels.cpp

main.o : main.cpp registers.h decoder.h reader.h instruction.h labels.h data.h memory.h
	g++ -ansi -Wall -g -c main.cpp

reader.o : reader.cpp reader.h registers.h 
	g++ -ansi -Wall -g -c reader.cpp

registers.o : registers.cpp registers.h 
	g++ -ansi -Wall -g -c registers.cpp

word.o : word.cpp word.h
	g++ -ansi -Wall -g -c word.cpp

data.o : data.cpp data.h word.h
	g++ -ansi -Wall -g -c data.cpp

memory.o : memory.cpp memory.h word.h data.h
	g++ -ansi -Wall -g -c memory.cpp

clean : 
	rm -f CPU.out decoder.o  instruction.o  labels.o  main.o  reader.o  registers.o word.o data.o memory.o
