// Maximum Length of a Concatenated String with Unique Characters
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution{
public:
    bool hasUniqueCharacters(string str1, string str2){
        vector<int> alphabets(26, 0);
        for(int i=0;i<str1.length();i++){
            alphabets[str1[i] - 'a']++;
            if(alphabets[str1[i] - 'a'] > 1) return false;
        }
        for(int i=0;i<str2.length();i++){
            if(alphabets[str2[i] - 'a'] > 0) return false;
            alphabets[str2[i] - 'a']++;
        }
        return true;
    }

    int solve(vector<string> &arr, unordered_map<string, int> &mp, string str, int idx){
        if(idx >= arr.size()) return str.length();
        if(mp.count(str)) return mp[str];
        if(hasUniqueCharacters(str, arr[idx])){
            return mp[str] = max(solve(arr, mp, str + arr[idx], idx+1), solve(arr, mp, str, idx+1));
        }
        return mp[str] = solve(arr, mp, str, idx+1);
    }

    int maxLength(vector<string> &arr){
        int n = arr.size();
        unordered_map<string, int> mp;
        return solve(arr,mp,"",0);
    }
};
