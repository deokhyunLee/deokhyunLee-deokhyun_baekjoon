#include<iostream>
using namespace std;
int main(){
   int a ;
   cin >> a ;
   int b ;
   cin >> b ;
   int c, d;
   int sum=0;
   for(int i=0;i<b;i++){
       cin >> c >> d ;
       sum = sum + c*d ;
       
   }
   if(sum == a) cout << "Yes";
   else cout << "No";
}