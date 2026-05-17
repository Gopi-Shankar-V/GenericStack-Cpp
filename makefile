exe: main.o opt1.o 
	g++ main.o opt1.o -o exe

main.o: main.cpp header.h
	g++ -c main.cpp

opt1.o: opt1.cpp header.h
	g++ -c opt1.cpp

#push.o: push.cpp header.h
#	g++ -c push.cpp

clean:
	rm -fv *.o exe
