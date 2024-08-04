#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct myclass {
    int operator()(int x, int y) { return x - y;}
} myobject;

bool cmp(int a, int b) { 
    return a > b;
} 

int main(){

    vector<int> nums(1,10);

    int base = 0;
    int sum = accumulate(nums.begin(), nums.end(), base); // base + sum of elements
    int sub = accumulate(nums.begin(), nums.end(), base, [](int x, int y) { return x - y; }); // base - sum of elements
    int sub2 = accumulate(nums.begin(), nums.end(), base, myobject); // base (defined operation) sum of elements
    int sum = accumulate(nums.begin(), nums.end(), base, minus<int>()); // base - sum of elements
    base = 1;
    int sum = accumulate(nums.begin(), nums.end(), base, multiplies<int>()); // base * prod of elements

    sort(arr, arr + 10); //arr len = 10
    sort(v.begin(), v.end()); //vector
    sort(v.rbegin(), v.rend()); //내림차순
    sort(v.begin(), v.end(), cmp); //내가 원하는 기준으로
    sort(arr, arr + 10, cmp); 

    int max = *max_element(v.begin(), v.end()); //max element
    int max_index = max_element(v.begin(), v.end()) - v.begin(); //max index
    int min = *min_element(v.begin(), v.end());
    int min_index = min_element(v.begin(), v.end()) - v.begin();

    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(vec1); // vec1을 복사한 벡터 생성
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(vec1.begin(), vec1.end()); // vec1의 범위를 가져와 벡터 생성
    vector<int> vec2(vec1.begin(), vec1.begin() + 2); // vec2 = {1, 2}, 

    std::vector<int> vec = {1, 2, 3};
    if (vec.empty()) {
        std::cout << "벡터가 비어있습니다.";
    }
    std::vector<int> vec = {1, 2, 3};
    vec.resize(5); // vec = {1, 2, 3, 0, 0}
    vec.resize(2); // vec = {1, 2}

    std::vector<int> vec = {1, 2, 3};
    vec.insert(vec.begin()+1, 4); // vec = {1, 4, 2, 3}

    std::vector<int> vec = {1, 2, 3};
    vec.erase(vec.begin()+1); // vec = {1, 3}
    vec.erase(v.begin() + 1, v.begin + 3); // 번위로도 가능. 마지막 포함 안함, 총 2개 지운것

    std::vector<int> vec = {1, 2, 3};
    vec.clear(); // vec = {}

    vector<int> vec {1, 2, 3};
    vec.clear(); // size = 0, capacity = 3

    vector<int>().swap(vec); // vec의 메모리를 해제하고, 빈 벡터와 swap
    // vec는 더 이상 메모리를 차지하지 않음

    std::vector<int> vec = {1, 2, 3};

    for (int& x : vec) {
        x *= 2;
    }

    for (int x : vec) {
        std::cout << x << " ";
    }
    // 출력 결과: 2 4 6

    vector<int>::iterator iter; //포인터 처럼 *iter 하면 그 벡터 원소 값 나옴

    AB.reserve( A.size() + B.size() ); // preallocate memory// merge merging vector
    AB.insert( AB.end(), A.begin(), A.end() );
    AB.insert( AB.end(), B.begin(), B.end() );

    std::vector<int> AB = A;
    AB.insert(AB.end(), B.begin(), B.end());

    AB.append_range(A);
    AB.append_range(B);



    return 0;





}