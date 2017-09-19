
vector3D.o : vector3D.cpp
	gcc -c vector3D.cpp -o vector3D.o

test : test.cpp vector3D.o
	g++ test.cpp vector3D.o -o test

all  : test

clean : 
	rm *.o
	rm test
