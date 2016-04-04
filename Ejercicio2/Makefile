main.o: main.cpp include/A.h include/B.h include/C.h
	g++ -Wall -Werror -c main.cpp 
A.o: cpp/A.cpp include/A.h include/B.h include/C.h
	g++ -Wall -Werror -c cpp/A.cpp 
B.o: cpp/B.cpp include/B.h include/A.h include/C.h
	g++ -Wall -Werror -c cpp/B.cpp 
C.o: cpp/C.cpp include/C.h include/A.h include/B.h 
	g++ -Wall -Werror -c cpp/C.cpp
