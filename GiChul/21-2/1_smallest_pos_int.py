"""
Q) Given an integer array of size N, implement a method that returns the smallest positive integer which is not
in that array.

- Run time needs to be <= O(N)
- Do not use built-in sort method
- Example
    1. array = [4, 7, -1, 1, 2] → return: 3
    2. array = [100, 101, 102] → return: 1
    3. array = [3, 2, 1, 0, -1] → return: 4
"""

def smallest_pos_int_hash(array):
    """
    idea: hash table을 이용해 각 숫자가 배열에 존재하는지 표시
    """
    
    n = len(array)
    hash = list([0 for _ in range(n+1)])
    for i in range(n):
        if array[i] <= n and array[i] > 0:
            hash[array[i]-1] = 1
    
    return hash.index(0)+1     # 첫 번째로 0인 인덱스를 찾음 = 배열에서 누락된 가장 작은 양의 정수
        

def smallest_pos_int(array):
    """
    idea: 각 숫자의 절댓값을 이용해 그 숫자가 가리키는 인덱스를 음수로 바꿈

    1) First iteration: < 1 or N < 인 모든 숫자를 음수로 변환 (우리가 관심 있는 값을 1~N까지의 값으로 제한)
    2) Second iteration: 각 숫자의 절댓값을 이용해 그 숫자가 가리키는 인덱스를 음수로 바꿈
        e.g. 숫자 a가 있으면 배열의 a-1번째 인덱스의 값을 음수로 바꿈
        -> 해당 숫자가 배열에 존재함을 표시
    3) Third iteration: 첫 번째로 양수인 인덱스 찾음 (i+1이 가장 작은 양의 정수, if 모든 값이 음수면 답은 N+1 bc
        이미 1~N이 모두 존재한다는 뜻이니까)
    """

    n = len(array)
    # Step 1: Replace numbers that are out of range with -1
    for i in range(n):
        if array[i] < 1 or array[i] > n:
            array[i] = 0       # '관련 없는' 값들은 다르게 처리 (확실한 notation)
    
    # Step 2: Mark the presence of numbers
    for i in range(n):
        mark = array[i]
        if (mark != 0):      # 음수여도 한 때 양수였다가 다른 정수의 존재 여부를 표시하기 위해 마이너스 붙은 값일 수 있음 
            array[abs(mark)-1] = -1

    # Step 3: Find the first positive number
    for i in range(n):
        if array[i] >= 0:
            return i+1
    return n+1


if __name__ == "__main__":
    array1 = [4, 7, -1, 1, 2]
    array2 = [100, 101, 102]
    array3 = [3, 2, 1, 0, -1]

    print("1st solution using hash")
    for arr in [array1, array2, array3]:
        print("return: ", end='')
        print(smallest_pos_int_hash(arr))

    print("\n2nd solution")
    for arr in [array1, array2, array3]:
        print("return: ", end='')
        print(smallest_pos_int(arr))
        

