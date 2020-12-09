CXX = g++
CXXFLAGS = -std=c++11 -pthread
OBJS = args.o vector.o matrix.o qmatrix.o

main: $(OBJS) src/main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) src/main.cpp -o main
args.o: src/args.cpp
	$(CXX) $(CXXFLAGS) -c src/args.cpp
vector.o: src/vector.cpp
	$(CXX) $(CXXFLAGS) -c src/vector.cpp
matrix.o: src/matrix.cpp
	$(CXX) $(CXXFLAGS) -c src/matrix.cpp
qmatrix.o: src/qmatrix.cpp
	$(CXX) $(CXXFLAGS) -c src/qmatrix.cpp

clean:
	rm -rf *.o main