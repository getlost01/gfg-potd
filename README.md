# GFG Problem Of The Day

## Today - 8 June 2023
### Que - Find Kth permutation

[Question Link](https://practice.geeksforgeeks.org/problems/find-kth-permutation-0932/1)

### My approach
Logic to find the next permutation.
- Start from the rightmost digit and find the first pair of adjacent digits where the `left digit` is smaller than the `right digit`.
- After getting such a digit pair find the `just greater value` from the `left digit`.
- Swap the `left digit` with `just greater digit`. 
- Sort all the digits to the `right digits` in ascending order.


### Code (c++)
```
class Solution
{
public:
    
    string s = "";
    void perm(int n){
        int i,j;
        for(i = n-2;i>=0;--i){
            if(s[i]<s[i+1])
                break;
        }
        for(j = n-1; j>i;--j){
            if(s[j]>s[i])
                break;
        }
        swap(s[j],s[i]);
        sort(s.begin()+i+1,s.end());
    }

    string kthPermutation(int n, int k)
    {
        for(int i = 1;i<=n;++i)
            s += (char)('0'+i);
        while(--k)
            perm(n);
            
        return s;
    }
    
};
```