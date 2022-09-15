#include<iostream>
using namespace std;

int main() {
	int arr[6] = { 1, 1, 2, 2, 2, 8 };
	int inp[6];
	cin >> inp[0] >> inp[1] >> inp[2] >> inp[3] >> inp[4] >> inp[5];

	for (int i = 0; i < 6; i++) cout << arr[i] - inp[i] << " ";
}