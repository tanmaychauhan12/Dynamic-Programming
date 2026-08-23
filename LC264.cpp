// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/

class Solution{     // TLE , T.C. => O(N * log N)
public:
    bool isUglyNumber(int n){
        while(n%2 == 0) n = n/2;
        while(n%3 == 0) n = n/3;
        while(n%5 == 0) n = n/5;
        return n == 1;
    }

    int nthUglyNumber(int n){
        int count = 0;
        int i = 1;
        while(count < n){
            if(isUglyNumber(i)) count++;
            if(count == n) return i;
            i++;
        }
        return i;
    }
};
