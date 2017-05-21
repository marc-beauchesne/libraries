#pragma once
#include <vector>
#include <queue>
#include "graph.h"

using namespace std;
using namespace graph;

namespace graphBFS
{
	vector<int> parent;
	deque<bool> processed;
	deque<bool> visited;
	deque<bool> discovered;
	queue<long> vertexQueue;

	void(*preProcess)(long);
	void(*process)(long, long);
	void(*postProcess)(long);

	void InitSearch(long size)
	{
		parent.assign(size, 0);
		processed.assign(size, 0);
		visited.assign(size, 0);
		discovered.assign(size, 0);
		//vertexQueue.assign(size, 0);
	}

	void bfs(Graph* graph, long startVertex)
	{
		NodeEdge* edge = nullptr;
		long vertex = startVertex;

		// pre process edge
		if (preProcess)
			preProcess(vertex);

		vertexQueue.push(vertex);
		discovered[vertex] = true;

		while (!vertexQueue.empty())
		{
			vertex = vertexQueue.front();
			vertexQueue.pop();


			// pre process edge
			if (preProcess)
				preProcess(vertex);

			processed[vertex] = true;

			edge = graph->myEdges[vertex];
			long nextVertex = 0;
			while (edge != nullptr)
			{
				nextVertex = edge->pointsTo;

				if (processed[nextVertex] == false || graph->directed) 
				{
					// process edge
					if (process)
						process(vertex, nextVertex);
				}
				if (discovered[nextVertex] == false)
				{
					vertexQueue.push(nextVertex);
					discovered[nextVertex] = true;
					parent[nextVertex] = vertex;
				}

				edge = edge->nextPtr;
			}

			// post process
			if (postProcess)
				postProcess(vertex);
		}

	}
}