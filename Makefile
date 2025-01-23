all: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	chcp 65001 > nul
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras

compile: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++11 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras

conta_palavras.o : conta_palavras.cpp conta_palavras.hpp
	g++ -std=c++11 -Wall -c conta_palavras.cpp
	
testa_conta_palavras: 	testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp conta_palavras.o
	g++ -std=c++11 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	
test: testa_conta_palavras
	./testa_conta_palavras
	
cpplint: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	python3 cpplint.py testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp

gcov: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c conta_palavras.cpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras
	gcov *.cpp	
	 
debug: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++11 -Wall -g -c conta_palavras.cpp
	g++ -std=c++11 -Wall  -g conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	gdb testa_conta_palavras
	
cppcheck: testa_conta_palavras.cpp   conta_palavras.cpp conta_palavras.hpp
	cppcheck  --enable=warning .

valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_conta_palavras

clean:
	del -rf *.o *.exe *.gc* testa_conta_palavras 

javadoc:
	python3 script_doxygen.py

main:
	chcp 65001 > nul
	g++ conta_palavras.cpp main.cpp -o conta_palavras
	./conta_palavras