#pragma once
#ifndef _Graph_
#define _Graph_

#include "LinkedList.cpp"
#include "Stack.h"
#include "Queue.h"
#include "GraphExceptions.h"

class Graph {
public:
	LinkedList<int> *verts; // dynamic array to represent verticies. Each index holds a linked list of integers representing the indicies it is connect to
	int size;

	// constructor
	Graph(int numVerts = 10);

	// destructor
	~Graph();

	// additional method
	void addEdge(int from, int to); // int weight (optional)
	void removeEdge(int from, int to);
	bool hasEdge(int from, int to);
	int getSize();

	LinkedList<int>* outEdges(int from);
	LinkedList<int>* inEdges(int to);

	bool depthFirstSearch(int search);
	bool breadthFirstSearch(int search);

	void Print();
};

#endif