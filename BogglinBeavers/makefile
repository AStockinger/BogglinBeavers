
output: Boggle.o BoggleMenu.o
    g++ Boggle.o Boggle.o -o output

Boggle.o: Boggle.cpp Boggle.hpp
    g++ -c Boggle.cpp

BoggleMenu.o: BoggleMenu.cpp
    g++ -c BoggleMenu.cpp

clean:
    rm *.o output