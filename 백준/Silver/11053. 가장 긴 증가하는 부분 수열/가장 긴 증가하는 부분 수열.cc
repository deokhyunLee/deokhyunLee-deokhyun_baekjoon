#include<iostream>
#include<algorithm>

using namespace std;

int n, i, j;
int arr[1000];
int len[1000] ;

int main() {
	fill_n(len, 1000, 1);
	cin >> n;
	for (i = 0; i < n; i++) cin >> arr[i];

	len[0] = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}
	}
	
	int tmp=0;
	for (i = 0; i < n; i++) {
		if (tmp < len[i]) tmp = len[i];
	}
	cout << tmp;
	return 0;
}