import copy

puyo_map = []

for i in range(12) : puyo_map.append(list(input()))



n = 6
cnt = 0
while True :
    gone = []

    for y in range(12) :
        for x in range(6) :
            if puyo_map[y][x] != '.' and y*n+x not in sum(gone, []) :
                
                que = [[y*n+x, puyo_map[y][x]]]
                exp = []
                find = [-6, 6, -1, 1]

                while que != [] :
                    pos, color = que.pop(0)
                    exp.append(pos)
                    for mv in find :
                        if pos+mv < 0 or pos+mv > 71 or (mv == -1 and pos%n == 0) or (mv == 1 and pos%n == 5): continue

                        if pos+mv not in exp and puyo_map[(pos+mv)//n][(pos+mv)%n] == color :
                            que.append([pos+mv, color])

                if len(exp) >= 4 : 
                    gone.append(exp)

    if gone == [] : break
    else :
        cnt += 1
        for g in gone :
            for z in g :
                puyo_map[z//n][z%n] = '.'

        for x in range(6) :
            for y in range(11, -1, -1) :
                if puyo_map[y][x] == '.' :
                    for ty in range(y, -1, -1) :
                        if puyo_map[ty][x] != '.' :
                            puyo_map[y][x] = puyo_map[ty][x]
                            puyo_map[ty][x] = '.'
                            break

print(cnt)