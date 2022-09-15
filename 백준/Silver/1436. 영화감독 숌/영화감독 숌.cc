#include<iostream>
#include<string>

using namespace std;

int main() {
	int cnt = 0, ccnt = 0, n;
	string str;
	cin >> n;

	while (true) {
		cnt++;
		str = to_string(cnt);

		if (str.find("666") != string::npos) {
			ccnt++;
			if (ccnt == n) {
				cout << cnt;
				return 0;
			}
		}
	}
}