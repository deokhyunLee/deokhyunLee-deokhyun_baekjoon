#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

vector<int> virus_vec;
int arr[10][10] = { 0 };
int tmparr[10][10] = { 0 };
int n, m;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int bfs(int one, int two, int thr) {
	deque<int> dq;
	int pos;
	int y, x, cnt = 0;
	arr[one / m][one % m] = 1;
	arr[two / m][two % m] = 1;
	arr[thr / m][thr % m] = 1;
	copy(&arr[0][0], &arr[0][0] + 100, &tmparr[0][0]);

	for (auto el : virus_vec) dq.push_back(el);

	while (!dq.empty()) {
		pos = dq.front();
		dq.pop_front();

		for (auto el : mv) {
			y = pos / m + el[0];
			x = pos % m + el[1];
			if (y < 0 || x < 0 || y >= n || x >= m || tmparr[y][x] != 0) continue;

			tmparr[y][x] = 2;
			dq.push_back(y*m+x);
		}
	}
	for (y = 0; y < n; y++) {
		for (x = 0; x < m; x++) {
			if (tmparr[y][x] == 0) cnt++;
		}
	}

	arr[one / m][one % m] = 0;
	arr[two / m][two % m] = 0;
	arr[thr / m][thr % m] = 0;
	return cnt;
}

int main() {
	cin >> n >> m;

	vector<int> visit;
	int tarr[3];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 2) virus_vec.push_back(y * m + x);
		}
	}

	int max = 0, tmax ;
	int one, two, thr;
	for (one = 0; one < n * m; one++) {
		if (arr[one/m][one%m] != 0) continue;
		for (two = 0; two < n * m; two++) {
			if (arr[two / m][two % m] != 0) continue;
			if (one == two) continue;
			for (thr = 0; thr < n * m; thr++) {
				if (arr[thr / m][thr % m] != 0) continue;
				if (thr == one || thr == two) continue;
				tarr[0] = one; tarr[1] = two; tarr[2] = thr;
				sort(tarr, tarr + 3);
				if (find(visit.begin(), visit.end(), tarr[0] * 10000 + tarr[1] * 100 + tarr[2]) != visit.end()) continue;
				visit.push_back(tarr[0]*10000+tarr[1]*100+tarr[2]);

				tmax = bfs(one, two, thr);
				if (tmax > max) max = tmax;
			}
		}
	}
	cout << max;
}