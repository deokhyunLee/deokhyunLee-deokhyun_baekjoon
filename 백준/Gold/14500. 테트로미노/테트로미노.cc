#include<stdio.h>
int main(){
	int n, m, y, x, i, j ;
	scanf("%d %d", &n, &m) ;
	int arr[n][m] ;
	
	for(y=0;y<n;y++){
		for(x=0;x<m;x++){
			scanf("%d",&arr[y][x]) ;
		}
	}
	
	int ar[19][4] = {{0, 1, 2, 3},{0, n, n*2, n*3},{0, 1, n, n+1},{1, n+1, n*2, n*2+1},{0, n, n*2, n*2+1},{0, 1, n+1, n*2+1},{0, 1, n, n*2},{2, n, n+1, n+2},
	{0, n, n+1, n+2},{0, 1, 2, n+2},{0, 1, 2, n},{1, n, n+1, n*2},{0, n, n+1, n*2+1},{1, 2, n, n+1},{0, 1, n+1, n+2},{1, n, n+1, n+2},{1, n, n+1, n*2+1},
	{0, n, n+1, n*2},{0, 1, 2, n+1}};
	
	
	int max = 0, cnt, px, py ;
	bool bk ;
	
	for(i=0;i<19;i++){
		for(y=0;y<n;y++){
			for(x=0;x<m;x++){
				bk = false ;
				for(j=0;j<4;j++){
					py = ar[i][j] / n ;
					px = ar[i][j] % n ;
					
					if(y+py >= n || x+px >= m){
						bk = true ;
					}
				}
				if(bk) continue ;
				
				
				cnt = 0 ;
				for(j=0;j<4;j++){
					py = ar[i][j] / n ;
					px = ar[i][j] % n ;
					
					cnt = cnt + arr[y+py][x+px] ;
				}
				if(cnt > max) max = cnt ;
			}
		}
	}
	printf("%d", max) ;
}