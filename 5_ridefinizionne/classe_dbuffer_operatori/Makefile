CXXFLAGS = -DNDEBUG

CXXINCLUDES = .

main.exe: main.o dbuffer.o
	g++ $(CXXFLAGS) main.o dbuffer.o -o main.exe

main.o: main.cpp
	g++ $(CXXFLAGS) -I$(CXXINCLUDES) -c main.cpp -o main.o

dbuffer.o: dbuffer.cpp
	g++ $(CXXFLAGS) -I$(CXXINCLUDES) -c dbuffer.cpp -o dbuffer.o

.PHONY: clean doc all

clean:
	rm *.o *.exe

doc:
	doxygen

all: main.exe doc
