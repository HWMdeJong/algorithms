#include <vector>
#include <limits>
#include <stdint.h>

using namespace std;

vector<int64_t> dijkstra(int64_t source, vector<vector<int64_t> > distance_matrix) {
	int64_t n = distance_matrix.size();
	vector<int64_t> distances(n, numeric_limits<int64_t>::infinity());
	distances[source] = 0;
	vector<bool> visited(n, false);

	for(int64_t i = 0; i < n; i++) {
		int64_t current = -1;
		for(int64_t j = 0; j < n; j++) {
			if(!visited[j] &&
				(current == -1 ||
				distances[j] < distances[current])) {
				current = j;
			}
		}

		visited[current] = true;
		for(int64_t j = 0; j < n; j++) {
			int64_t path = distances[current] + distance_matrix[current][j];
			distances[j] = min(path, distances[j]);
		}
	}
	return distances;
}

vector<vector<int64_t> > floyd_warshall(vector<vector<int64_t> > distance_matrix) {
	int64_t n = distance_matrix.size();
	for(int64_t i = 0; i < n; i++) {
		for(int64_t j = 0; j < n; j++) {
			for(int64_t k = 0; k < n; k++) {
				distance_matrix[i][k] = min(distance_matrix[i][k],
											distance_matrix[i][j] +
											distance_matrix[j][k]);
			}
		}
	}
	return distance_matrix;
}

int main() {
	return 0;
}