
CMP = g++ -std=c++11
CLASS = minesweeper
MAIN = project
EXEC = playminesweeper

$(EXEC): $(CLASS).o $(MAIN).o 
	$(CMP) $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h 
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp gfx.o -o $(MAIN).o 

clean:
	rm *.o
	rm $(EXEC)

