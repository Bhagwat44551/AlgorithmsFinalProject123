#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using namespace std;

vector<int> Dijkstra(vector< vector<int> > adjacencyMatrix, int s) {
	priority_queue<int, vector<int>, greater<int> > min_heap;
	vector<int> dist(adjacencyMatrix.size());
	vector<int> prev(adjacencyMatrix.size());

	for (int i = 0; i < dist.size(); i++) {
		dist[i] = numeric_limits<int>::max();
	}
	dist[s] = 0;

	for (int i = 0; i < dist.size(); i++) {
		min_heap.push(dist[i]);
	}

	while (!min_heap.empty()) {
		int u = min_heap.top();
		min_heap.pop();

		for (int v = 0; v < adjacencyMatrix.size(); v++) {
			if (adjacencyMatrix[u][v] != 0) {
				if (dist[v] > dist[u] + adjacencyMatrix[u][v]) {
					dist[v] = dist[u] + adjacencyMatrix[u][v];
					prev[v] = u;
					//decreaseKey (H,u)
				}
			}
		}
	}

	
}

int main() {

	return 0;
}