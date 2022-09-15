#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	char st;
	int min = 2500;
	int sum;

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {

			for (int ch = 0; ch < 2; ch++) { // 0 : W , 1 : B start

				if (ch == 0) st = 'W';
				else st = 'B';
				sum = 0;

				for (int y = i; y < i + 8; y++) {
					for (int x = j; x < j + 8; x++) {

						if (arr[y][x] != st) sum++;

						if (st == 'W') st = 'B';
						else st = 'W';
					}
					if (st == 'W') st = 'B';
					else st = 'W';
				}

				if (sum < min) min = sum;
			}
		}
	}

	cout << min;
}