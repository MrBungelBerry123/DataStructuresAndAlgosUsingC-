CC = clang
CPP = clang++
CFLAGS = -Wall -g
SRC = ./src
INC = ./inc
UTILS = ./utils
BIN = ./bin
LIB = -lm
LINEAR_STRUCT = /linearStructures
ATMT = /automatons
SORT = /sorting

PROGRAMS = init minHeapifyDemo maxHeapifyDemo quickSelectDemo minHeapDemo maxHeapDemo maxContiguousDemo kadaneDemo heapSortDemo insertionSortDemo quickSortDemo mergeSortDemo test selectionSortDemo shellSortDemo TopKdemo LeastKdemo medianDemo DoublyListDemo SinglyListDemo StackDemo QueueDemo Trie

all: $(PROGRAMS)

minHeapifyDemo: $(INC)/minHeapify.h $(SRC)/minHeapifyDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@  $(SRC)/minHeapifyDemo.cpp -I $(INC) -I $(UTILS) $(LIB)

maxHeapifyDemo: $(INC)/maxHeapify.h $(SRC)/maxHeapifyDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@  $(SRC)/maxHeapifyDemo.cpp -I $(INC) -I $(UTILS) $(LIB)

quickSelectDemo: $(INC)/quickSelect.h $(SRC)/quickSelectDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/quickSelectDemo.cpp -I $(INC) -I $(UTILS) $(LIB)

minHeapDemo: $(INC)$(LINEAR_STRUCT)/heap/MinHeap.h $(SRC)/minHeapDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/minHeapDemo.cpp -I $(INC)$(LINEAR_STRUCT)/heap -I $(INC) -I $(UTILS) $(LIB)

maxHeapDemo: $(INC)$(LINEAR_STRUCT)/heap/MaxHeap.h $(SRC)/maxHeapDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/maxHeapDemo.cpp -I $(INC)$(LINEAR_STRUCT)/heap -I $(INC) -I $(UTILS) $(LIB)

TopKdemo: $(INC)$(LINEAR_STRUCT)/heap/TopKHeap.h $(SRC)/TopKdemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/TopKdemo.cpp -I $(INC)$(LINEAR_STRUCT)/heap -I $(INC)$(LINEAR_STRUCT) -I $(INC) -I $(UTILS) $(LIB)

LeastKdemo: $(INC)$(LINEAR_STRUCT)/heap/LeastKHeap.h $(SRC)/LeastKdemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/LeastKdemo.cpp -I $(INC)$(LINEAR_STRUCT)/heap -I $(INC)$(LINEAR_STRUCT) -I $(INC) -I $(UTILS) $(LIB)	

medianDemo: $(INC)$(LINEAR_STRUCT)/heap/MedianHeap.h $(SRC)/medianDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/medianDemo.cpp -I $(INC)$(LINEAR_STRUCT)/heap -I $(INC)$(LINEAR_STRUCT) -I $(INC) -I $(UTILS) $(LIB)

maxContiguousDemo: $(INC)/maxContiguousSubArray.h $(SRC)/maxSubArrayDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/maxSubArrayDemo.cpp -I $(INC) $(LIB)

kadaneDemo: $(INC)/kadane.h $(SRC)/kadaneDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/kadaneDemo.cpp -I $(INC) $(LIB)

heapSortDemo: $(INC)$(SORT)/heapSort.h $(SRC)/heapSortDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/heapSortDemo.cpp -I $(INC)$(SORT) -I $(INC) -I $(UTILS) $(LIB)

insertionSortDemo: $(INC)$(SORT)/insertionSort.h $(SRC)/insertionSortDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/insertionSortDemo.cpp -I $(INC)$(SORT)  $(LIB)

quickSortDemo: $(INC)$(SORT)/quickSort.h $(SRC)/quickSortDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/quickSortDemo.cpp -I $(INC)$(SORT) -I $(UTILS) $(LIB)

mergeSortDemo: $(INC)$(SORT)/mergeSort.h $(SRC)/mergeSortDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/mergeSortDemo.cpp -I $(INC)$(SORT)  $(LIB)

test: $(INC)$(SORT)/mergeSort.h $(SRC)/test.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/test.cpp -I $(INC)$(SORT)  $(LIB)

selectionSortDemo: $(INC)$(SORT)/selectionSort.h $(SRC)/selectionSortDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/selectionSortDemo.cpp -I $(INC)$(SORT)  $(LIB)

shellSortDemo: $(INC)$(SORT)/shellSort.h $(SRC)/shellSortDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/shellSortDemo.cpp -I $(INC)$(SORT)  $(LIB)

DoublyListDemo: $(INC)$(LINEAR_STRUCT)/list/DoublyLinkedList.h $(SRC)/DoublyListDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/DoublyListDemo.cpp -I $(INC)$(LINEAR_STRUCT)/list $(LIB)

SinglyListDemo: $(INC)$(LINEAR_STRUCT)/list/SinglyLinkedList.h $(SRC)/SinglylistDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/SinglylistDemo.cpp -I $(INC)$(LINEAR_STRUCT)/list $(LIB)

StackDemo: $(INC)$(LINEAR_STRUCT)/list/Stack.h $(SRC)/stackDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/stackDemo.cpp -I $(INC)$(LINEAR_STRUCT)/list $(LIB)

QueueDemo: $(INC)$(LINEAR_STRUCT)/list/Queue.h $(SRC)/queueDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/queueDemo.cpp -I $(INC)$(LINEAR_STRUCT)/list $(LIB)

Trie: $(INC)$(ATMT)/Trie.h $(SRC)/trieDemo.cpp
	$(CPP) $(CFLAGS) -o $(BIN)/$@ $(SRC)/trieDemo.cpp -I $(INC)$(LINEAR_STRUCT)/list -I $(INC)$(ATMT) $(LIB)

.PHONY: clean

init:
	mkdir bin

clean:
	rm -r $(BIN)