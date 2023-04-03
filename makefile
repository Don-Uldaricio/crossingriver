testState: State.cpp testState.cpp
	g++ -o testState testState.cpp State.cpp State.h
testHeap: testHeap.cpp Heap.cpp State.cpp
	g++ -o testHeap testHeap.cpp Heap.cpp State.cpp
testLoad: Load.cpp testLoad.cpp
	g++ -o testLoad testLoad.cpp Load.cpp
testCrossing: testCrossing.cpp CrossingRiver.cpp Load.cpp Operation.cpp Heap.cpp State.cpp
	g++ -o testCrossing testCrossing.cpp CrossingRiver.cpp Load.cpp Operation.cpp Heap.cpp State.cpp
runTestState: testState
	./testState
runTestHeap: testHeap
	./testHeap
runTestLoad: testLoad
	./testLoad
runTestCrossing: testCrossing
	./testCrossing