A, B = list(map(int, input().split()))
C = A*60+B - 45
if(C < 0) : C += 60*24
print(str(C//60)+" "+str(C%60))