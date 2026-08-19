// Minimum Difficulty of a Job Schedule
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution{
public:
    int solve(vector<int> &jobDifficulty, vector<vector<int>> &dp, int idx, int d){
        if(idx >= jobDifficulty.size()) return 0;
        if(d == 1){
            int maxEl = jobDifficulty[idx];
            for(int i=idx;i<jobDifficulty.size();i++){
                maxEl = max(maxEl, jobDifficulty[i]);
            }
            return maxEl;
        }
        if(dp[idx][d] != -1) return dp[idx][d];
        int maxEl = jobDifficulty[idx];
        int finalResult = INT_MAX;
        for(int i=idx;i<=jobDifficulty.size()-d;i++){
            maxEl = max(maxEl, jobDifficulty[i]);
            int result = maxEl + solve(jobDifficulty,dp,i+1,d-1);
            finalResult = min(finalResult, result);
        }
        return dp[idx][d] = finalResult;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d){
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        return solve(jobDifficulty,dp,0,d);
    }
};
