#pragma once
#include <vector>
#include "graph.h"
using namespace std;
using namespace graph;


namespace graphDFS
{
	vector<int> parent;
	vector<int> processed;
	vector<int> visited;

	void(*preProcess)(long);
	void(*process)(long, long);
	void(*postProcess)(long);

	void InitSearch(long size)
	{
		parent.assign(size, 0);
		processed.assign(size, 0);
		visited.assign(size, 0);
	}

	void dfs(Graph* graph, long vertex)
	{
		NodeEdge* edge = graph->myEdges[vertex];

		visited[vertex] = true;

		// pre process edge
		if (preProcess)
			preProcess(vertex);

		while (edge != nullptr) {
			long nextVertex = edge->pointsTo;
			if (visited[nextVertex] == false)
			{
				parent[nextVertex] = vertex;

				// process edge
				if (process)
					process(vertex, nextVertex);

				dfs(graph, nextVertex);
			}
			else if ((!processed[nextVertex] && (parent[vertex] != nextVertex)) || graph->directed)
			{
				// process edge
				if (process)
					process(vertex, nextVertex);
			}

			edge = edge->nextPtr;
		}

		// post process
		if (postProcess)
			postProcess(vertex);

		processed[vertex] = true;

	}
}