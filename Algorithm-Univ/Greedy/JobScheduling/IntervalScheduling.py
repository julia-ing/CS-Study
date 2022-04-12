# 예시: 동아리 미팅룸 (최대한 많은 동아리들이 쓸 수 있게끔 
#       -> 가장 이른 종료 시각을 우선으로!!)

meeting = [['C1', 8.0, 13.0], ['C2', 9.0, 11.0], ['C3', 10.5, 11.5],
    ['C4', 11.0, 14.0], ['C5', 13.0, 16.0], ['C6', 14.0, 15.0], 
    ['C7', 15.0, 17.0]]
    
meeting.sort(key=lambda t: t[2])  # 종료 시각이 이른 순서대로 정렬

schedule = [meeting[0]]
i = 0 

for j in range(1, len(meeting)):
    if meeting[j][1] >= meeting[i][2]:  # 다음 선택될 미팅의 시작시간과 이전에 선택된 미팅의 종료시간 비교
        schedule.append(meeting[j])
        i = j
        
print("meeting schedule : ", schedule)