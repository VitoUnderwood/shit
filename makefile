CXX = g++
CXXFLAGS = -std=c++11
OBJS = args.o

main: $(OBJS) src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o main
args.o: src/args.cpp src/args.h
	$(CXX) $(CXXFLAGS) -c src/args.cpp

clean:
	rm -rf *.o main