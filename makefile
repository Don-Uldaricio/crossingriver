testMain: main.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp
	g++ -o testMain main.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp
testState: State.cpp testState.cpp
	g++ -o testState testState.cpp State.cpp State.h
testHeap: testHeap.cpp Heap.cpp State.cpp
	g++ -o testHeap testHeap.cpp Heap.cpp State.cpp
testCrossing: testCrossing.cpp CrossingRiver.cpp Operation.cpp Heap.cpp State.cpp
	g++ -o testCrossing testCrossing.cpp CrossingRiver.cpp Load.cpp Operation.cpp Heap.cpp State.cpp
runTestState: testState
	./testState
runTestHeap: testHeap
	./testHeap
runTestCrossing: testCrossing
	./testCrossing
runTestMain: testMain
	./testMain