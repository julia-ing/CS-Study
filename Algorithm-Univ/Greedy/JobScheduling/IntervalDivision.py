# 예시: 동아리 미팅룸을 잡을 때 최소의 미팅룸으로
#       -> 가장 이른 시작 시각을 우선으로!!

meeting = [['C1', 9.0, 11.0], ['C2', 9.0, 12.5], ['C3', 13.0, 14.5],
     ['C4', 14.0, 17.0], ['C5', 11.0, 14.0], ['C6', 9.0, 11.0],
     ['C7', 15.0, 16.5], ['C8', 15.0, 16.5], ['C9', 11.0, 12.5],
     ['C10', 13.0, 14.5]]
     
meeting.sort(key=lambda t: t[1])

schedule = [[meeting[0]]]  # 2차원 배열
finishTime = [meeting[0][2]]  # 11.0 
k = 0  # 미팅룸 번호

for i in range(1, len(meeting)):
    flag = False  # False 면 새로운 미팅룸 만들기
    for j in range(k+1):  # 방들을 차례로 살펴보면서
        if meeting[i][1] >= finishTime[j]:  # 같은 미팅룸에서 뒤에 이어서 할 수 있는 경우. 즉 새로운 미팅룸을 만들지 않아도 되는 경우
            schedule[j].append(meeting[i])
            finishTime[j] = meeting[i][2]
            flag = True
            break
        
    # 새로운 미팅룸을 만들어야 하는 경우
    if not flag:  
        k += 1
        schedule.append([meeting[i]])
        finishTime.append(meeting[i][2])

for i in range(k+1):
    print('Room', i+1, ': ', schedule[i])