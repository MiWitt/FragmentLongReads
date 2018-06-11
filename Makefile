TCLAPINCLUDEPATH = ./tclap/include


CXX      = g++   # for Linux RedHat 6.1, g++ version 2.95.2
CXXFLAGS = -O2 -Wall -I${TCLAPINCLUDEPATH}


default: fragmentLongReads

clean:
	@echo "Cleaning up."
	@rm -f main.o fragmentLongReads

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c -o main.o main.cpp
	
fragmentLongReads: main.o
	${CXX} -o fragmentLongReads main.o
	


