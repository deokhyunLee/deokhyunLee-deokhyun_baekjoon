#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<list>
using namespace std;

deque<int> q;
int vis[100001] = { 0, };
int path[100001] = { 0, };

int bfs(int n, int k) {
	int mv[3] = {-1, 1, 0};
	int i, tmp, pp;

	path[n] = 1;
	q.push_back(n);

	while (true) {
		pp = q.front();
		q.pop_front(); 

		mv[2] = pp ;
		for (i = 0; i < 3; i++) {
			tmp = pp + mv[i];
			if (tmp < 0 || tmp > 100000) continue;
			if (vis[tmp] != 0) continue;

			vis[tmp] = 1;
			path[tmp] = pp;
			q.push_back(tmp);
			if (tmp == k) return 0;
		}
	}
}
int main() {
	int n, k;
	cin >> n >> k;

	if (n == k) cout << '0' << endl << n;
	else {
		bfs(n, k);

		int tt = k;
		int tt2 = 0;
		vector<int> tmpvec;

		tmpvec.push_back(k);
		while (true) {
			tt2 = path[tt];
			tmpvec.push_back(tt2);
			tt = tt2;
			if (tt2 == n) break;
		}

		cout << tmpvec.size() - 1 << endl;
		int jongolove = tmpvec.size();
		for (int asdf = 0; asdf < jongolove; asdf++) {
			cout << tmpvec.back() << " ";
			tmpvec.pop_back();
		}
	}
}