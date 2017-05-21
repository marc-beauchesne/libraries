#pragma once

#include <vector>
using namespace std;

namespace graph
{
	const long maxSize = 100000;
	class NodeEdge {
	public:
		NodeEdge(long dest) : pointsTo(dest), nextPtr(nullptr) {}

		NodeEdge* nextPtr;
		long pointsTo;
	};

	struct Graph {
	public:
		Graph(long size, bool isDirected = true) :myEdges(maxSize, nullptr), vertexCount(0), directed(isDirected) {
			myEdges.resize(size);
		}

		void insertNode(long x, long y, bool isDirected) {


			NodeEdge* newEdge = new NodeEdge(y);

			// set to the front of the list for the same id.
			newEdge->nextPtr = myEdges[x];
			myEdges[x] = newEdge;

			// If not directed, add the oposite edge using recursion. 
			if (!isDirected)
			{
				insertNode(y, x, true);
			}
		}

		long getVertexCount()
		{
			return vertexCount;
		}

		// Consider using a deque of bools.
		vector<NodeEdge*> myEdges;
		bool directed;

	private:

		long vertexCount;
	};
}
