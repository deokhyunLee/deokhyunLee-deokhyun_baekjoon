n, m = map(int, input().split())
maze = [list(input()) for _ in range(n)]
que = [[0, 0, 1]]
exp = [[0, 0]]
udrl = [[-1, 0], [1, 0], [0, -1], [0, 1]]
while True :
    q = que.pop(0)
    if q[0] == n-1 and q[1] == m-1 : break
    for mv in udrl :
        if 0 <= q[0]+mv[0] < n and 0 <= q[1]+mv[1] < m and maze[q[0]+mv[0]][q[1]+mv[1]] == '1' and [q[0]+mv[0], q[1]+mv[1]] not in exp :
            exp.append([q[0]+mv[0], +q[1]+mv[1]])
            que.append([q[0]+mv[0], q[1]+mv[1], q[2]+1])
print(q[2])
