// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "graphDFS.h"
#include "graphBFS.h"
#include <iostream>

void processNode(long parentId, long childId)
{
	cout << parentId << "->" << childId << endl;
}

int main()
{
	long graphSize = 100000;
	Graph *myGraph = new Graph(graphSize, false);
	myGraph->insertNode(0, 1, false);
	myGraph->insertNode(0, 2, false);
	myGraph->insertNode(0, 4, false);
	myGraph->insertNode(1, 3, false);
	myGraph->insertNode(4, 7, false);
	myGraph->insertNode(2, 8, false);

	/*
	DFS::process = processNode;
	DFS::InitSearch(graphSize);
	DFS::dfs(myGraph, 0);
	*/

	graphBFS::process = processNode;
	graphBFS::InitSearch(graphSize);
	graphBFS::bfs(myGraph, 0);

	int i;

	cin >> i;

    return 0;
}

