class Solution {
public:
    int fib(vector<int> &T, int &n){
        if(T.size() > n) return T[T.size()-1];
        else{
            T.push_back(T[T.size()-1] + T[T.size()-2] + T[T.size()-3]);
            return fib(T, n);
        }
    }

    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n < 3) return 1;
        else{
            vector<int> T = {0,1,1};
            return fib(T,n);
        }
    }
};
