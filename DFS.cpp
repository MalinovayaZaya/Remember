//DFS
 
#include <iostream>
#include <stack>
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
	stack <int> s;
	int visit[a]; 
	for (int i = 0; i < a; i++) {
		visit[i] = 0;
	}
	int start;
	cout << ">> start vertex: ";
	cin >> start;
	s.push(start);
	visit[start - 1] = 1;// 1 - in stack, 2 - done;
	int n = 0;
	while (!s.empty()) {
		s.pop();
		n++;
		for(int i = 0; i < a; i++) {
			if(G[start - 1][i] == 1 && visit[i] == 0) {
				s.push(i + 1);
				visit[i] = 1;
			}
		}
		visit[start - 1] = 2;
		cout << "vertex " << start << "was visited at numder " << n << endl;
		if (!s.empty())  start = s.top();
	}
	return 0;
}
