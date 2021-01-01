CXX = g++
CXXFLAGS = -Wall -g

output:main.o DataBase.o 
	$(CXX) $(CXXFLAGS) -o output DataBase.o main.o

main.o: main.cpp  json.hpp  DataBase.h
	 $(CXX) $(CXXFLAGS) -c main.cpp

DataBase.o:DataBase.cpp  json.hpp  DataBase.h
	$(CXX) $(CXXFLAGS) -c DataBAse.cpp


clean:
	rm *.o output

