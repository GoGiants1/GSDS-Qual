def fibonacci_bottom_up(n):
	if n<=1:
		return n
	
	first = 0
	second = 1
	for _ in range(0, n-1):
		next = first+second
		first = second
		second = next
	return next

def fibonacci_top_down(n, memo):    # 재귀하되 저장
	if memo[n] > 0:             # 기존에 만난 문제라면 바로 불러오기
		return memo[n]
	if n<=1:
		memo[n] = n
		return memo[n]
	else:
		memo[n] = fibonacci_top_down(n-1, memo) + fibonacci_top_down(n-2, memo)
		return memo[n]


if __name__ == "__main__":
	test_cases = [0, 1, 2, 5, 10, 20, 30]
	expected_results = [0, 1, 1, 5, 55, 6765, 832040]

	# Bottom-up 방식 테스트
	print("Testing fibonacci_bottom_up function:")
	for i, n in enumerate(test_cases):
		result = fibonacci_bottom_up(n)
		assert result == expected_results[i], f"Test failed for n={n}: expected {expected_results[i]}, got {result}"
		print(f"fibonacci_bottom_up({n}) = {result} [Passed]")

	# Top-down 방식 테스트
	print("\nTesting fibonacci_top_down function:")
	for i, n in enumerate(test_cases):
		memo = [-1] * (n + 1)    # 메모이제이션을 위한 배열 초기화 (-1이라는 건 아직 만나지 않은 문제라는 것)
		result = fibonacci_top_down(n, memo)
		assert result == expected_results[i], f"Test failed for n={n}: expected {expected_results[i]}, got {result}"
		print(f"fibonacci_top_down({n}) = {result} [Passed]")