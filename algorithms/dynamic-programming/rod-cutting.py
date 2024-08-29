"""
<Rod-cutting>
    : 주어진 막대기의 길이와 각 길이에 해당하는 가격표를 이용하여 cut or not cut을 결정해
      최대의 가격을 얻는 방법을 찾는 문제
"""

def rod_cutting(P,n):
    """
    R[3] 설명 (길이 3을 자를 때 )
    - P[0] + R[2]: 앞을 1로 자르고 나머지 2는 전에 구했던 최대 가격 구하는 방법으로 자름
    - P[1] + R[1]: 앞을 2로 자르고 나머지 1은 전에 구했던 최대 가격 구하는 방법으로 자름
    - P[2] + R[0]: 그냥 안 자르고 3으로 유지
    """
    R = [0] * (n+1)    # 길이 i인 막대기의 최대 수익을 저장 (R[0]은 무시)
    
    for i in range(1, n+1):     # 막대 길이
        max_val = -1
        for j in range(i):      # 길이 i를 자를 모든 방법 탐색
            max_val = max(max_val, P[j] + R[i-j-1])    # j는 P를 돌면서 어느 길이로 자르는 게 가장 좋을지 탐색
        R[i] = max_val
    
    return R[n]


if __name__ == "__main__":
    P = [1, 5, 8, 9]  # 길이 i에 해당하는 가격표
    n = 4  
    max_profit = rod_cutting(P, n)
    print(f"길이 {n}의 막대기 최대 수익: {max_profit}")