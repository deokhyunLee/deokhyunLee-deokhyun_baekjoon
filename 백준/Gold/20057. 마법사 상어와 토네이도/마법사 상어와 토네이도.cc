#include<stdio.h>
int main(){
	int n ;
	scanf("%d", &n) ;
	int y, x ;
	int map[n][n] ;
	
	for(y=0;y<n;y++){
		for(x=0;x<n;x++){
			scanf("%d", &map[y][x]);
		}
	}
	
	int cnt=0 ;
	int turn = 1 ;
	int route[n*n] ;
	for(int i=0;i<n*n;i++) route[i] = -1;
	int routecnt = 0 ;
	route[0] = n*n/2 ;
	
	while(cnt != n-1){
		
		cnt = cnt + 1 ;
		if(turn == 1){
			turn = 0 ;
			
			for(int i=0;i<cnt;i++){
				route[routecnt+1] = -1 ;
				routecnt = routecnt + 1 ;
			}
			for(int i=0;i<cnt;i++){
				route[routecnt+1] = n ;
				routecnt = routecnt + 1 ;
			}
			
		}else{
			turn = 1 ;
			
			for(int i=0;i<cnt;i++){
				route[routecnt+1] = 1 ;
				routecnt = routecnt + 1 ;
			}
			for(int i=0;i<cnt;i++){
				route[routecnt+1] = -n ;
				routecnt = routecnt + 1 ;
			}
			
		}
	}
	for(int i=n-2;i>=0;i--){
		route[routecnt+1] = -1 ;
		routecnt = routecnt + 1 ;
	}
	float per[9] = {0.05, 0.1, 0.1, 0.02,  0.07, 0.07,  0.02, 0.01, 0.01, } ;
	int pos_up[10][2] = {{-2, 0}, {-1, -1}, {-1, 1}, {0, -2}, {0, -1}, {0, 1}, {0, 2}, {1, -1}, {1, 1}, {-1, 0}} ;
	int pos_down[10][2] = {{2, 0}, {1, 1}, {1, -1}, {0, 2},  {0, 1}, {0, -1}, {0, -2}, {-1, 1}, {-1, -1}, {1, 0}} ;
	int pos_left[10][2] = {{0, -2}, {1, -1}, {-1, -1}, {2, 0}, {1, 0}, {-1, 0}, {-2, 0}, {1, 1}, {-1, 1}, {0, -1}} ;
	int pos_right[10][2] = {{0, 2}, {1, 1}, {-1, 1}, {2, 0}, {1, 0}, {-1, 0}, {-2, 0}, {1, -1}, {-1, -1}, {0, 1}} ;
	int pos, sand, minusand, outsand=0, tmpy, tmpx ;
	for(int t=0;t<n*n;t++){
		
		if(t==0){
			pos = route[t] ;
			continue ;	
		}
		if(route[t] == -n){
			
			pos = pos -n ;
			y = pos / n ;
			x = pos % n ;
			sand = map[y][x] ;
			minusand = sand  ;
			map[y][x] = 0 ;
			for(int tm=0;tm<10;tm++){
				if(tm != 9){
					tmpy = pos_up[tm][0] ;
					tmpx = pos_up[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}
				}else{
					tmpy = pos_up[tm][0] ;
					tmpx = pos_up[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + minusand ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + minusand ;
					}
				}
			}
			
		}
		if(route[t] == n){
			
			pos = pos +n ;
			y = pos / n ;
			x = pos % n ;
			sand = map[y][x] ;
			minusand = sand  ;
			map[y][x] = 0 ;
			for(int tm=0;tm<10;tm++){
				if(tm != 9){
					tmpy = pos_down[tm][0] ;
					tmpx = pos_down[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}
				}else{
					tmpy = pos_down[tm][0] ;
					tmpx = pos_down[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + minusand ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + minusand ;
					}
				}
			}
			
		}
		if(route[t] == -1){
			pos = pos -1 ;
			y = pos / n ;
			x = pos % n ;
			sand = map[y][x] ;
			minusand = sand  ;
			map[y][x] = 0 ;
			for(int tm=0;tm<10;tm++){
				if(tm != 9){
					tmpy = pos_left[tm][0] ;
					tmpx = pos_left[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}
				}else{
					tmpy = pos_left[tm][0] ;
					tmpx = pos_left[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + minusand ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + minusand ;
					}
				}
			}
		}
		if(route[t] == 1){
			
			pos = pos +1 ;
			y = pos / n ;
			x = pos % n ;
			sand = map[y][x] ;
			minusand = sand  ;
			map[y][x] = 0 ;
			for(int tm=0;tm<10;tm++){
				if(tm != 9){
					tmpy = pos_right[tm][0] ;
					tmpx = pos_right[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + int(sand*per[tm]) ;
						minusand = minusand - int(sand*per[tm]) ;
					}
				}else{
					tmpy = pos_right[tm][0] ;
					tmpx = pos_right[tm][1] ;
					if(y+tmpy < 0 || y+tmpy >= n || x+tmpx < 0 || x+tmpx >= n){
						outsand = outsand + minusand ;
					}else{
						map[y+tmpy][x+tmpx] = map[y+tmpy][x+tmpx] + minusand ;
					}
				}
			}
			
		}
		
		
	}
	printf("%d", outsand) ;
	
}