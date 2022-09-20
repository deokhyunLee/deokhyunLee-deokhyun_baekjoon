#include<iostream>
#include<vector>
#include<deque> 
#include<algorithm>
using namespace std;


int main() {
	vector<vector<int>> map;
	vector<int> tmpvec;
	vector<int> ripeT;
	vector<int> T;
	int i, j, tmp ;
	int n, m;

	cin >> n >> m;
	for (i = 0; i < m; i++) {

		map.push_back(tmpvec);

		for (j = 0; j < n; j++) {

			cin >> tmp;
			map[i].push_back(tmp);
			if (tmp == 1) ripeT.push_back(i * n + j);
			if (tmp == 0) T.push_back(i * n + j);
		}
	}
	if (T.empty()) {
		cout << "0";
		return 0;
	}


	deque<vector<int>> dq;
	vector<int> nrT;
	int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int cnt = 0;
	int y, x;

	dq.push_back(ripeT);

	while (!dq.empty()) {
		nrT.clear();
		ripeT = dq.front();
		dq.pop_front();
		
		for (auto el : ripeT) {

			for (auto mps : mv) {
				y = el / n + mps[0];
				x = el % n + mps[1];

				if (y < 0 || x < 0 || y >= m || x >= n || map[y][x] != 0) continue;
				map[y][x] = 1;
				nrT.push_back(y * n + x);
			}
		}
		if(!nrT.empty()) dq.push_back(nrT);
		cnt++;
	}
	int flag = 0;
	for (auto el : T) {
		if (map[el / n][el % n] == 0) flag = 1;
	}
	if (flag) cout << "-1";
	else cout << cnt - 1;
	return 0;
}