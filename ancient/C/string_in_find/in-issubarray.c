#include <bits/stdc++.h>
using namespace std;

// Function to check if an array is
// subarray of another array
bool isSubArray(int A[], int B[], int n, int m) {
	for (int i = 0; i <= n-m; i++) { // Loop through possible starting indices of subarray
		int j;
		for (j = 0; j < m; j++) { // Loop through elements of subarray and compare with B[]
			if (A[i+j] != B[j]) {
				break;
			}
		}
		if (j == m) { // All elements of B[] match subarray starting at index i
			return true;
		}
	}
	return false;
}

// Driver Code
int main() {
	int A[] = { 2, 3, 0, 5, 1, 1, 2 };
	int n = sizeof(A) / sizeof(int);
	int B[] = { 3, 0, 5, 1 };
	int m = sizeof(B) / sizeof(int);

	if (isSubArray(A, B, n, m))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
