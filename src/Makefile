DIRECTORIES =-I ../include/ -I ../include/model_client/ 


CXXFLAGS = -std=c++11 $(DIRECTORIES) -std=gnu++1z
 
OBJ =  main.o buttons.o drive.o door.o 
CXX = g++

main: $(OBJ)
	g++ $(CXXFLAGS) -o $@ $^ 


clean::
	$(RM) *.o
