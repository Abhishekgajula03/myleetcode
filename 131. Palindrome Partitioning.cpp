//https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:

    void func(int index,string &s,vector<vector<string>>&res,vector<string>&path){
        if(index==s.size()){
            res.push_back(path);
        }
        for(int i=index;i<s.size();i++){
            if(partition(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            func(i+1,s,res,path);
            path.pop_back();
            }
        }
    }
    bool partition(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        func(0,s,res,path);
        return res;
    }
};
