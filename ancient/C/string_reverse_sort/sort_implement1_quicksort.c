/*
Goal: 주어진 array 정렬, ascending order (char 말고 다른 type array여도 가능)
Approach: quick sort

Input: "banana apple orange"
Output: "  aaabaelnnnopp"
*/

#include <stdio.h> 
#include <string.h> 

void swap(char* a, char* b) { 
	char temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// 임의로 정한 pivot index (여기선 마지막 char) 중심으로 pivot보다 값 작은애들 / 큰애들 나누고, 
// pivot을 그 경계 위치로 옮긴 후 그 위치 반환
int partition(char* str, int low, int high) { 
	char pivot = str[high]; // pivot = last character
	int i = low - 1;        // index (or number) of the smaller elements

	for (int j = low; j <= high - 1; j++) { 
		// pivot보다 값 작은 애들 왼쪽으로 몰아넣기  
		if (str[j] <= pivot) { 
			i++; 
			swap(&str[i], &str[j]); 
		} 
	} 
	swap(&str[i + 1], &str[high]); // 맨 뒤에 있던 pivot을 작은애들/큰애들 경계로 옮기기
	return i + 1; // pivot index 
} 

// sort the string
void quickSort(char* str, int low, int high) { 
	if (low < high) { 
		int pivotIndex = partition(str, low, high); // partition the string and get the pivot index 
		quickSort(str, low, pivotIndex - 1); // sort the left sub-array 
		quickSort(str, pivotIndex + 1, high); // sort the right sub-array 
	} 
} 

int main() { 
	char input[] = "Hello 321"; 
	int n = strlen(input); 

	quickSort(input, 0, n - 1); 

	printf("Sorted string: %s\n", input); 
	return 0; 
}