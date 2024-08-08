from collections import deque

# 비어있는 큐 만들기
deque = deque()

# 원소가 있는 큐 만들기
deque = deque([1, 2, 3])

# 큐 최대 길이 명시하기(원소를 maxlen보다 더 많이 넣으면 maxlen이 자동 갱신됨)
deque = deque(maxlen=5)


###
from collections import deque

# append는 오른쪽
deque = deque()
deque.append(3)
deque.append(6)
deque.append(9)
deque.append(12)
print(deque) # deque([3, 6, 9, 12])

# append는 왼쪽
deque = deque()
deque.appendleft(3)
deque.appendleft(6)
deque.appendleft(9)
deque.appendleft(12)
print(deque) # deque([12, 9, 6, 3])

# pop은 오른쪽
deque = deque([3, 6, 9, 12])
deque.pop()
print(deque) # deque([3, 6, 9])

# popleft은 왼쪽
deque = deque([3, 6, 9, 12])
deque.popleft()
print(deque) # deque([6, 9, 12])

# 위 두가지를 활용해서 stack & queue 용도에 맞게 사용!
dq = deque('love')
dq.insert(0, 'K') # 첫번째 항목에 'K'를 추가
deque(['K', 'l', 'o', 'v', 'e'])         

dq.insert(100, 'K') # 100번째 항목(없으니까 가장 큰 쪽에)에 'K' 추가
deque(['K', 'l', 'o', 'v', 'e', 'K'])  
dq.remove('K') # 'K'항목 삭제

deque(['l', 'o', 'v', 'e', 'K']) # 같은 항목이 있을때 지우면 왼쪽부터 삭제됨.
dq.remove('K')
deque(['l', 'o', 'v', 'e']) # 오른쪽에 있는 'K'삭제

# clear()는 모든 항목을 삭제
deque = deque([1,2,3]) # deque([1, 2, 3])
deque.clear() # deque([])