//BFS
 
#include <iostream>
#include <queue>
using namespace std;
 
int main() {
	int a;
	cout << ">> number of vertex: ";
	cin >> a;
	int G[a][a];
	cout << endl << ">> adj marrix :" << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cin >> G[i][j];
		}
	}
	queue <int> q;
	int visit[a]; 
	int dis[a]; //array with distances
	for (int i = 0; i < a; i++) {
		visit[i] = 0;
		dis[a] = 0;
	}
	int start;
	cout << ">> start vertex: ";
	cin >> start;
	q.push(start);
	visit[start - 1] = 1; // 1 - in queue, 2 - done;
	dis[start - 1] = 0;
	while (!q.empty()) {
		q.pop();
		for(int i = 0; i < a; i++) {
			if(G[start - 1][i] == 1 && visit[i] == 0) {
				q.push(i + 1);
				dis[i] = dis[start - 1] + 1;
				visit[i] = 1;
			}
		}
		visit[start - 1] = 2;
		start = q.front();
	}
	for (int i = 0; i < a; i++) {
		cout << "distance from start to " << i + 1 << " = " << dis[i] << endl;
	}
	return 0;
}
