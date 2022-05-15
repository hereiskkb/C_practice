#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start) {

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, miniDistance, nextNode, i, j;


	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(graph[i][j] == 0) {
				cost[i][j] = INFINITY;
			} else {
				cost[i][j] = graph[i][j];
			}
		}
	}

	for(i = 0; i < n; i++) {
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while(count < (n - 1)) {
		miniDistance = INFINITY;

		for(i = 0; i < n; i++) {
			if(distance[i] < miniDistance && !visited[i]) {
				miniDistance = distance[i];
				nextNode = i;
			}
		}

		visited[nextNode] = 1;

		for(i = 0; i < n; i++) {
			if(!visited[i] && (miniDistance + cost[nextNode][i] < distance[i])) {
				distance[i] = miniDistance + cost[nextNode][i];
				pred[i] = nextNode;
			}
		}

		count++;
	}

	for(i = 0; i < n; i++) {
		if(i != start) {
			printf("Distance from source to %d: %d\n", i, distance[i]);
		}
	}
}

int main(int argc, char const *argv[]) {
	
	int i, j, n, u;
	n = 7;
	int graph[MAX][MAX] = {
		{0, 0, 1, 2, 0, 0, 0},
		{0, 0, 2, 0, 0, 3, 0},
		{1, 2, 0, 1, 3, 0, 0},
		{2, 0, 1, 0, 0, 0, 1},
		{0, 0, 3, 0, 0, 2, 0},
		{0, 3, 0, 0, 2, 0, 1},
		{0, 0, 0, 1, 0, 1, 0}
	};
	u = 0;

	dijkstra(graph, n, u);

	return 0;
}