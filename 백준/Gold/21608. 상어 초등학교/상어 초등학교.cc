#include<stdio.h>

int main(){
	int n ;
	scanf("%d", &n);
	int table[n][n] = {};
	
	int arr[n*n][5] ;
	
	for(int i=0 ; i<n*n ; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	int stu, ty, tx, cnt = -1, tcnt ;
	
	for(int i=0; i<n*n; i++){
		
		stu = arr[i][0] ;
		cnt = -1 ;
		
		for(int y=0; y<n; y++){
			for(int x=0; x<n; x++){
				if(table[y][x] != 0) continue ;
				tcnt = 0 ;
				
				if(y-1 >  -1 && table[y-1][x] == 0) tcnt =  tcnt +  1 ;
				if(x-1 >  -1 && table[y][x-1] == 0) tcnt =  tcnt +  1 ;
				if(y+1 <   n && table[y+1][x] == 0) tcnt =  tcnt +  1 ;
				if(x+1 <   n && table[y][x+1] == 0) tcnt =  tcnt +  1 ;
				
				for(int j=0; j<5; j++){
					if(j==0) continue  ;
					if(y-1 >  -1 && table[y-1][x] == arr[i][j]) tcnt =  tcnt +  5 ;
					if(x-1 >  -1 && table[y][x-1] == arr[i][j]) tcnt =  tcnt +  5 ;
					if(y+1 <   n && table[y+1][x] == arr[i][j]) tcnt =  tcnt +  5 ;
					if(x+1 <   n && table[y][x+1] == arr[i][j]) tcnt =  tcnt +  5 ;
					
				}
				if(cnt < tcnt){
					cnt = tcnt ;
					ty = y ;
					tx = x ;
				}
				
			}
		}
		table[ty][tx] = arr[i][0] ;
		
		
	}
	
	int score = 0, tscore ;
	for(int i=0; i<n*n; i++){
		
		tscore = 0 ;
		for(int y=0;y<n;y++){
			for(int x=0;x<n;x++){
				if(table[y][x] != arr[i][0]) continue  ;
				
				for(int j=0; j<5; j++){
					if(j==0) continue  ;
					if(y-1 >  -1 && table[y-1][x] == arr[i][j]) tscore =  tscore +  1 ;
					if(x-1 >  -1 && table[y][x-1] == arr[i][j]) tscore =  tscore +  1 ;
					if(y+1 <   n && table[y+1][x] == arr[i][j]) tscore =  tscore +  1 ;
					if(x+1 <   n && table[y][x+1] == arr[i][j]) tscore =  tscore +  1 ;
					
				}
				
			}
		}
		if(tscore == 1) score = score + 1 ;
		if(tscore == 2) score = score + 10 ;
		if(tscore == 3) score = score + 100 ;
		if(tscore == 4) score = score + 1000 ;
		
		
	}
	printf("%d", score) ;
} 