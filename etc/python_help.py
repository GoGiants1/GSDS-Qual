import itertools

arr = ['A', 'B', 'C']
nPr = itertools.permutations(arr, 2)
print(list(nPr))

결과 : [('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'C'), ('C', 'A'), ('C', 'B')]


import itertools

arr = ['A', 'B', 'C']
nCr = itertools.combinations(arr, 2)
print(list(nCr))

결과 : [('A', 'B'), ('A', 'C'), ('B', 'C')]


zip()

동일한 개수로 이루어진 iterable한 객체들을 인수로 받아 묶어서 iterator로 반환
    z = zip([1, 2, 3], ('A', 'B', 'C'))
    print(next(z)) # (1, 'A')
    print(next(z)) # (2, 'B')
    print(next(z)) # (3, 'C')
all()

iterable한 객체를 인수로 받아서 원소가 모두 참이면 True, 아니면 False를 반환
    a = all([1, 2, 3]) # True
    a = all([0, 1, 2]) # False
any()

iterable한 객체를 인수로 받아서 원소가 하나라도 참이면 True, 아니면 False를 반환
    a = any([0, 1, 2]) # True
    a = any([0, False, []] # False
chain()

iterable한 객체들을 인수로 받아 하나의 iterator로 반환
    c1 = [1, 2]
    ca = ['A', 'B']
    c = itertools.chain(c1, ca)
    print(next(c)) # 1
    print(next(c)) # 2
    print(next(c)) # A
    print(next(c)) # B


a = eval('"BlockDMask" + "blog"')
print(f"1. eval('\"BlockDMask\"' + '\" blog\"') : {a}") # 2. 숫자 덧셈
b = eval("100 + 32")
print(f'2. eval("100 + 32") : {b}') # 3. 내장 함수 
absc = eval("abs(-56)")
print(f'3. eval("abs(-56)") : {c}') # 4. 리스트 길이
d = eval("len([1,2,3,4])")
print(f'4. eval("len([1,2,3,4])") : {d}') # 5. round 함수
e = eval("round(1.5)")
print(f'5. eval("round(1.5)") : {e}')


numbers = [1, 2, 3, 4, 5]
squared_numbers = map(square, numbers)
print(list(squared_numbers))  # [1, 4, 9, 16, 25]




def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]: