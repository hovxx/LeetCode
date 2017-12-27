/******************************************************************
* problem id : 438
* problem title : Find All Anagrams in a String
* problem link : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
*******************************************************************/

/* A simple method, O(n), but time limit exceed */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        vector<int> ans;

        if(s_size<p_size)
            return ans;

        sort(p.begin(), p.end());
        for(int i=0; i<=s_size-p_size; i++) {
            string temp = s.substr(i, p_size);
            sort(temp.begin(), temp.end());
            if(temp==p)
                ans.push_back(i);
        }
        return ans;
    }
};

/* A method with slide window */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0), win(26,0), ans;
        int s_size=s.size(), p_size=p.size();

        if(s_size<p_size)
            return ans;
        for(int i=0; i<p_size; i++) {
            pv[p[i]-'a'] ++;
            win[s[i]-'a'] ++;
        }
        if(pv==win)
            ans.push_back(0);
        for(int i=p.size(); i<s.size(); i++) {
            win[s[i]-'a'] ++;
            win[s[i-p.size()]-'a'] --;
            if(win==pv)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
