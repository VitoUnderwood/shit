CXX = g++
CXXFLAGS = -std=c++11 -pthread
OBJS = args.o vector.o

main: $(OBJS) src/main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) src/main.cpp -o main
args.o: src/args.cpp
	$(CXX) $(CXXFLAGS) -c src/args.cpp
vector.o: src/vector.cpp
	$(CXX) $(CXXFLAGS) -c src/vector.cpp

clean:
	rm -rf *.o main