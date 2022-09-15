A, B = list(map(int, input().split()))
D = int(input())
C = A*60+B+D
if(C >= 60*24) : C -= 60*24
print(str(C//60)+" "+str(C%60))