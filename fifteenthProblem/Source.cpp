#include <iostream>
#include <vector>
#include <queue>

unsigned int* distance;
bool* vertex_used;
std::vector<std::vector<int>> graph;

void breadth_first_search(int vertex_from) {
	std::queue<std::pair<int, int>> queue_for_bfs;
	queue_for_bfs.push(std::make_pair(vertex_from, -1));
	distance[vertex_from] = 0;
	vertex_used[vertex_from] = true;
	while (!queue_for_bfs.empty()) {
		std::pair<int, int> current_vertex = queue_for_bfs.front();
		queue_for_bfs.pop();
		for (int index = 0; index < graph[current_vertex.first].size(); index++) {
			std::pair<int, int> vertex_of_destination = std::make_pair(graph[current_vertex.first][index], vertex_from);
			if (!vertex_used[vertex_of_destination.first]) {
				distance[vertex_of_destination.first] = distance[current_vertex.first] + 1;
				queue_for_bfs.push(vertex_of_destination);
				vertex_used[vertex_of_destination.first] = true;
			}
		}
	}
}

int main() {
	int number_of_vertices, number_of_edges;
	std::cin >> number_of_vertices >> number_of_edges;
	distance = new unsigned int[number_of_vertices];
	vertex_used = new bool[number_of_vertices];
	graph.resize(number_of_vertices);
	memset(distance, 0, number_of_vertices);
	memset(vertex_used, false, number_of_vertices);
	for (int index = 0; index < number_of_edges; index++) {
		int vertex_from, vertex_to;
		std::cin >> vertex_from >> vertex_to;
		vertex_from--; vertex_to--;
		graph[vertex_from].push_back(vertex_to);
		graph[vertex_to].push_back(vertex_from);
	}
	int start_vertex;
	std::cin >> start_vertex;
	breadth_first_search(start_vertex - 1);
	for (int index = 0; index < number_of_vertices; index++) {
		std::cout << "To " << index + 1 << " the distance is " << distance[index] << '\n';
	}
	system("pause");
	return 0;
}