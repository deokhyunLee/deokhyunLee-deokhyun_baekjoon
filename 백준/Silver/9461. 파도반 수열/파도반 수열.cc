#include<iostream>
#include<deque>

using namespace std;

int main() {
	long long tc, n, sum;
	cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++) {
		cin >> n;
		deque<long long> dq = { 1, 1, 1 };
		
		if (n < 4) { cout << dq[n-1] << endl; continue; }

		for (int i = 4; i < n+1; i++) {
			sum = 0;
			sum += dq.front();
			dq.pop_front();
			sum += dq.front();
			dq.push_back(sum);
		}

		cout << dq.back() << endl;
	}
}