// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution{
public:
    int upcomingJob(vector<vector<int>> &jobs, int start, int currentJobEnd){
        int end = jobs.size()-1;
        int nextJobIdx = jobs.size();
        while(start <= end){
            int mid = start + (end-start) / 2;
            if(currentJobEnd <= jobs[mid][0]){
                nextJobIdx = mid;
                end = mid - 1;
            }else{
                start = mid + 1; 
            }
        }
        return nextJobIdx;
    }

    int solve(vector<vector<int>> &jobs, vector<int> &dp, int idx){
        if(idx >= jobs.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int nextJob = upcomingJob(jobs, idx+1, jobs[idx][1]);
        int doThatJob = jobs[idx][2] + solve(jobs, dp, nextJob);
        int skipTheJob = solve(jobs, dp, idx+1);
        return dp[idx] = max(doThatJob, skipTheJob);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit){
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for(int i=0;i<n;i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n+1, -1);
        return solve(jobs, dp, 0);
    }
};
