#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <bits/stdc++.h>
using namespace std;

struct myclass {
    int operator()(int x, int y) { return x - y;}
} myobject;

int main(){

    vector<int> nums(1,10);

    int base = 0;
    int sum = accumulate(nums.begin(), nums.end(), base); // base + sum of elements
    int sub = accumulate(nums.begin(), nums.end(), base, [](int x, int y) { return x - y; }); // base - sum of elements
    int sub2 = accumulate(nums.begin(), nums.end(), base, myobject); // base (defined operation) sum of elements
    int sum = accumulate(nums.begin(), nums.end(), base, minus<int>()); // base - sum of elements
    base = 1;
    int sum = accumulate(nums.begin(), nums.end(), base, multiplies<int>()); // base * prod of elements


    return 0;
}