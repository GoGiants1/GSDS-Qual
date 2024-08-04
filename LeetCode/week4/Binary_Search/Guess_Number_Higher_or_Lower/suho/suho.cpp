/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int a = 1, b = n;
        int ans = (a+b)/2;
        int res = guess(ans);

        while(res!=0){
            if(res == 1) a = ans+1;
            else b = ans-1;
            ans = (a+b)/2;
            res = guess(ans);
        }
        
        return ans;
    }
};
