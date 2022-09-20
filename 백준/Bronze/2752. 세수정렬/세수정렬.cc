#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    vector<int> vec;
    int a, b , c;
    cin >> a >>b>>c;
    vec.push_back(a) ;
    vec.push_back(b) ;
    vec.push_back(c) ;
    sort(vec.begin(), vec.end());
    
    cout <<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    }