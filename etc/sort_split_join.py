A = [1,5,2,6,8,3,4]
B = [(1,'a'), (5,'c'), (6,'b')]

A.sort()
print(A)
A.sort(key = lambda x: x%4)
print(A)
A.sort(key = lambda x: x%4, reverse = True)
print(A)
A.reverse()
print(A)

print(sorted(B))
print(list(reversed(B)))
print(sorted(B, key = lambda x: x[0]))
print(sorted(B, key = lambda x: x[1]))
print(sorted(B, key = lambda x: x[1], reverse = True))


print("A apple on table".split(' '))
print('_'.join(["a","b","c"]))
a = [1,2,3,4,5]
print(a)
a.reverse()
print(a)
a.reverse()
print(a)
a.insert(1,2)
print(a)
print(a.count(2))
a.pop(3)
print(a)
a.pop()
print(a)
a.remove(2)
print(a)
del a[0]
print(a)
a.clear()
print(a)
del a
# print(a)

digits = {0,1,3,2,4,5}
odds = {1,3,5}
digits.add(6)
print(digits)
digits.remove(2)
print(digits)
digits.clear()
print(digits)
digits = {0,1,3,2,4,5}
odds = {1,3,5}
print(digits.issubset(odds))
print(digits.issuperset(odds))
digits = {0,1,3,2,4,5}
odds = {1,3,5,8,9}
print(digits.difference(odds))
print(digits.intersection(odds))
print(digits.symmetric_difference(odds))
print(digits.union(odds))

dict_grades = dict()
dict_grades.clear()
# Remove all key/value pairs
dict_grades.keys()
# Returns all keys as a set-like object (unique entries)
dict_grades.items()
# Returns all key/value pairs as set-like objects (unique entries)
dict_grades.values()
# Returns all values as a list-like object (maybe not unique entries)
dict_grades.get(k)
# Returns the value associated with key k
dict_grades.get(k, v)
# Same + returns v if key k is not present

dict_grades.pop(k)
# Removes key k and returns the value associated with the key
dict_grades.pop(k,v)
# Same + returns v if key k is not present
dict_grades.setdefault(k)
# Returns the value associated with key k, if key k is not present, add it and set itsassociated value to None
dict_grades.setdefault(k,v)
# Returns the value associated with key k, if key k is not present, add it and set itsassociated value to v
dict_grades.update(dict2)
# Update dict_grades with the contents of dict2

from collections import deque

# 비어있는 큐 만들기
deque = deque()

# 원소가 있는 큐 만들기
deque = deque([1, 2, 3])

# 큐 최대 길이 명시하기(원소를 maxlen보다 더 많이 넣으면 maxlen이 자동 갱신됨)
deque = deque(maxlen=5)



deque.append(item)  	#오른쪽 끝에 새로운 원소를 삽입한다.
deque.appendleft(item)	#왼쪽 끝에 새로운 원소를 삽입한다.
deque.pop()	#오른쪽 끝의 원소를 제거 후 반환한다.
deque.popleft()	#왼쪽 끝의 원소를 제거 후 반환한다.
deque.extend(array)	#주어진 array 배열을 순환하며 오른쪽에 추가한다
deque.extendleft(array)	#주어진 array 배열을 순환하며 왼쪽에 추가한다.
deque.insert(n, item)	#n번 index에 원소를 추가한다.
deque.remove(item)#	입력한 원소를 삭제한다. 같은 원소가 있을 경우 왼쪽부터 삭제된다.
deque.rotate(n)	#n만큼 원소의 위치를 회전한다. (양수 : 시계방향, 음수 : 반시계 방향) 
deque.clear()#	모든 원소를 제거한다.
deque.reverse()	#원소의 위치를 좌우 반전시킨다.