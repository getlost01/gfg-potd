# GFG Problem Of The Day

## Today - 15 June 2023
### Que - Longest Palindrome in a String

[Question Link](https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)


### My approach
- I implement a straightforward approach using `two pointers` to identify substrings and determine whether they are palindromic.
- To optimize efficiency and avoid unnecessary checks, I start with larger substrings and gradually reduce their size. 
- Additionally, I avoid examining strings that are shorter or equal in length to the current maximum palindromic substring.


### Code (c++)
```
class Solution {
  public:
    bool ispalin(string& s, int i ,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;

            ++i; --j;
        }
        return true;
    }

    string longestPalin (string s) {
        int n = s.size();
        string out;
        out.push_back(s[0]);
        int ms = 1;
        for(int i = 0; i<n-1 ;++i){
            for(int j = n-1; j>i; --j){
                if((j-i+1)>ms && ispalin(s,i,j)){
                    ms = j-i+1;
                    out = s.substr(i,j-i+1);
                }
            }
        }
        return out;
        
    }
};
```

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
