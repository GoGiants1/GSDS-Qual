"""
Q) Suppose a sequence of integers is implemented with a linked list. A list of integers
is a palindrome if it is identical to its reversion. Given a list s of integers, 
implement a functio max_palindrome(s) that prints a list of sub-lists of s that are 
maximal palindromes. That is, t is a list that contains palindrome sub-lists of s that
are not a sublist of another palindrome sub-slit of s.

- Example: 
    1. s: [8,1,2,3,3,2,1,4,9,4,5,6,7,6,5,4,1] → [[8],[1,2,3,3,2,1],[4,9,4],[4,5,6,7,6,5,4]]
    2. s: [8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1] → [[8],[0],[4],[9,1,2,3,3,2,1,9],[1,9,1]]
"""

class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

def linked_list_to_list(node):
    lst = []
    while node is not None:
        lst.append(node.data)
        node = node.next
    return lst
    
def print_list(s):
    """
    list 형태로 linked list 출력
    """
    res = []
    if s is None:
        print(res)
        return
        
    res = linked_list_to_list(s)
    print(res)

def palindrome(s):
    """
    회문이면 1, 회문이 아니면 0 반환: list 형태로 바꾼 후 앞과 뒤에서부터 꺼내오며 비교
    """
    if s is None or s.next is None:
        return 1
    
    lst = linked_list_to_list(s)
    
    while len(lst) > 1:
        if lst.pop(0) != lst.pop():
            return 0
    
    return 1

def sub_list(s,t):
    """
    t의 모든 원소가 s 안에 있으면 sub-list
    """
    if not t:
        return 1
    
    if len(t) > len(s):
        return 0
    
    for i in range(len(s)-len(t)+1):
        if s[i:i+len(t)] == t:
            return 1
    return 0


def max_palindrome(s):
    """
    한 문자(node)를 기준으로 늘려가며(iterator) substring을 판별
    """
    if s is None:
        print([])
        return
    
    palindromes = []   
    node = s
    
    while node:
        iterator = node
        while iterator:
            check_head = node             # 검사용 부분 리스트
            check_tail = iterator.next    
            iterator.next = None          # 부분 리스트를 임시로 분리하기 위해 필요

            print_list(check_head)
            

            if palindrome(check_head):
                is_substring = False
                lst = linked_list_to_list(check_head)
                for other in palindromes:
                    if sub_list(other, lst):
                        is_substring = True
                        break
                    
                    if sub_list(lst, other):
                        palindromes.remove(other)
                        
                if not is_substring:
                    palindromes.append(lst)
            
            # 원래 연결 리스트 구조 복구
            iterator.next = check_tail
            iterator = iterator.next

        node = node.next
    
    print(palindromes)
    
    

if __name__ == "__main__":

    # s = [8,1,2,3,3,2,1,4,9,4,5,6,7,6,5,4,1]
    s = [8,1,2,3,3,2,1,0,4,9,1,2,3,3,2,1,9,1]
    t = [1, 2, 3, 3, 2, 1]
    head = Node(s[0], None)   # data와 next를 함께 전달
    prev = head
    for i in range(1,len(s)):
        node = Node(s[i],None)
        prev.next = node
        prev = node
     
    # print_list(head)
    # print(palindrome(head))
    # print(sub_list(s,t))
    max_palindrome(head)
    


   