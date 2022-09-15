room_cnt = int(input())
room_tester = list(map(int, input().split(' ')))
boss_cnt, jol_cnt = list(map(int, input().split(' ')))

answer_cnt = room_cnt
for i in range(len(room_tester)) :
    room_tester[i] -= boss_cnt
    if room_tester[i] < 0 : room_tester[i] = 0
for i in range(len(room_tester)) :
    answer_cnt += room_tester[i] // jol_cnt
    if room_tester[i] % jol_cnt != 0 :
        answer_cnt += 1
print(answer_cnt)