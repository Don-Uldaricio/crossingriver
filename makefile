testMain: main.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp
	g++ -o testMain.o main.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp -O2
testState: State.cpp testState.cpp
	g++ -o testState.o testState.cpp State.cpp State.h
testHeap: testHeap.cpp Heap.cpp State.cpp
	g++ -o testHeap.o testHeap.cpp Heap.cpp State.cpp
testCrossing: testCrossing.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp
	g++ -o testCrossing.o testCrossing.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp
runTestState: testState.o
	./testState.o
runTestHeap: testHeap.o
	./testHeap.o
runTestCrossing: testCrossing.o
	./testCrossing.o
runTestMain: testMain.o
	./testMain.o
clean:
	rm *.o