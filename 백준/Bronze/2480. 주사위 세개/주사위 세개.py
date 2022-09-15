A, B, C = list(map(int, input().split()))
if(A==B==C) : print(A*1000+10000)
elif(A != B and B != C and A != C) : print(max([A, B, C])*100)
else :
    if(A == B) : print(A*100+1000)
    elif(B == C) : print(B*100+1000)
    elif(A == C) : print(A*100+1000)