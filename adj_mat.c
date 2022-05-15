#include <stdio.h>

/*
	0	1	2	3	4	5	6
0	0	1	1	0	0	0	0
1	1	0	0	1	1	0	0
2	1	0	0	0	1	1	0
3	0	1	0	0	0	0	0
4	0	1	0	0	0	0	0
5	0	0	1	0	0	0	0
6	0	0	1	0	0	0	0
*/

#define SIZE 40

int queue[SIZE];
int adjacencyMatrix[7][7] = {
	{0, 1, 1, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0},
	{1, 0, 0, 0, 0, 1, 1},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0}
};
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int queuePointerIndex = 0;

void enqueue(int node) {
	for(int i = 0; i < 7; i++) {
		if(adjacencyMatrix[node][i] == 1 && visited[i] != 1) {
			queue[queuePointerIndex] = i;
			queuePointerIndex++;
		}
	}
}

void bfs(int root) {
	int queueReadPos = 0;
	printf("%d\t", root);
	visited[root] = 1;
	enqueue(root);
	while(queue[queueReadPos] != -1) {
		enqueue(queue[queueReadPos]);
		printf("%d\t", queue[queueReadPos]);
		visited[queue[queueReadPos]] = 1;
		queue[queueReadPos] = -1;
		queueReadPos++;
	}
	printf("\n");
}

void init_queue() {
	for(size_t i = 0; i < SIZE; i++) {
		queue[i] = -1;
	}
}

int main(int argc, char const *argv[]) {
	init_queue();
	bfs(0);
	return 0;
}