class Solution {
public:
    int numTilings(int n) {
        vector<int> T = {1};
        int i = 1;
        while(i <= n){
            if(i <= 1) T.push_back(T[i-1]);
            else if(i <= 2) T.push_back(T[i-1] + T[i-2]);
            else if(i <= 3) T.push_back(T[i-1] + T[i-2] + T[i-3]*2);
            else T.push_back(T[i-1] + T[i-2] + accumulate(T.begin(), T.end()-2, 0)*2);
            //<numeric> 
            //accumulate(T.begin(), T.end()-2, 0, minus<int>())   <functional>
            //accumulate(T.begin(), T.end()-2, 0, multiplies<int>())   <functional>
            //
            i++;
        }

        return T[i-1];
    }
};


// struct myclass {
//     int operator()(int x, int y) { return x - y;}
// } myobject;
 
// int main() {
//     vector<int> nums = {1, 2, 3};
//     // 0 - 1 - 2 - 3
//     int sum = accumulate(nums.begin(), nums.end(), 0, myobject);
    
//     cout << sum;
//     // cout : -6
// }
//int sum = accumulate(nums.begin(), nums.end(), 0, [](int x, int y) { return x - y; });   
