"""
Q) Permutation is a rearrangement of the elements of an ordered list S into a 1-to-1
corresultpondence with S itself. Given a string s, implement a function str_perm(s) that
returns a list of all permutations of s. However, the list contains no identical
permutations. The list should contain the permutations in lexicographical order.

- A string of length n has n! permutations.
- Example: 
    1. s = "abc" → ["abc", "acb", "bac", "bca", "cab", "cba"]
    2. s = "abb" → ["abb", "bab", "bba"]
"""

def perm(incomp, left, result):
    """
    주어진 문자열의 모든 순열을 생성하는 재귀함수
    - incomp: 현재까지 구성된 일부 문자열
    - left: 아직 사용되지 않은 문자들로 이루어진 문자열
    """
    if left == '':    # 모든 문자 다 사용
        if (incomp not in result): result.append(incomp)    # 중복되는 순열은 결과에 포함 x
    else:
        for i, letter in enumerate(left):
            incomp_after = incomp + letter      
            '''
            # if, incomp += letter로 쓰면 재귀호출이 돌아올 때 이전 호출에서 변경된 상태로 
            남아있음. 재귀의 특성 상 기존 상태를 유지할 필요가 있으므로 새로운 변수 사용하는 게
            바람직함 (각 재귀 호출은 독립적으로 동작해야 함)
            '''
            left_after = left[:i] + left[i+1:]   # 사용한 문자 i 제거
            perm(incomp_after, left_after, result)

def str_perm(s):
    result = []
    left = s[:]
    perm('', left ,result)
    
    return result


if __name__ == "__main__":
    print(str_perm("abc"))
    print(str_perm("abb"))
    print(str_perm("abcd"))
    print(str_perm("aaa"))
    print(str_perm(""))


