# GFG Problem Of The Day

## Today - 24 June 2023
### Que - Prefix match with other strings

[Question Link](https://practice.geeksforgeeks.org/problems/prefix-match-with-other-strings/1)


### My approach
- The approach is to intuitively, find the prefix substring of length `k` for each string in the array `arr` and then compare these substrings with the given matching string `str`.
- Additionally, it is important to consider the constraint that the length of the prefix substring, `k`, should not exceed the size of the given matching string, `str`.


### Code (c++) 
```
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        if(k>str.size())
            return 0;
            
        string toSearch = str.substr(0,k); 
        int c = 0;

        for(int i = 0; i<n; ++i){
            if(arr[i].substr(0,k) == toSearch)
                ++c;
        }

        return c;
    }
};
```

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)