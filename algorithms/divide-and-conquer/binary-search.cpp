#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
  if (right >= left) {
    int mid = left + (right - left) / 2;

    // 중간 요소가 찾고자 하는 값인 경우
    if (arr[mid] == target) return mid;

    // 중간 요소보다 작으면 왼쪽 부분만 탐색
    if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);

    // 중간 요소보다 크면 오른쪽 부분만 탐색
    return binarySearch(arr, mid + 1, right, target);
  }

  // 값을 찾지 못한 경우
  return -1;
}

int main() {
  vector<int> arr = {2, 3, 4, 10, 40};
  int target = 10;
  int result = binarySearch(arr, 0, arr.size() - 1, target);

  if (result != -1)
    cout << "Element found at index " << result << endl;
  else
    cout << "Element not found in array" << endl;

  return 0;
}
