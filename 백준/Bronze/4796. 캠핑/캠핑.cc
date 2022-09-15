#include<iostream>
#include<algorithm>
using namespace std ;

int main(){

    int a, b, c;

    int s = 0 ;
    while(true){

        s++;
        cin >> a >> b >> c ;

        if(a == 0 && b == 0 && c == 0) return 0;

        cout << "Case " << s << ": " << c/b*a+min(c%b, a) << endl;

        

    }

}