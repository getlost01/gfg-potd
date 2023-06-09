# GFG Problem Of The Day

## Today - 9 June 2023
### Que - Permutations of a given string

[Question Link](https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)

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
		vector<string>find_permutation(string S)
		{
		    int n = S.size();
		    vector<string> out;
		    sort(S.begin(),S.end());
		    s = S;
		    out.push_back(s);
		    sort(S.begin(),S.end(),greater<>());

		    while(S!=s){
		        perm(n);
		        out.push_back(s);
		    }
            
		    return out;
		}
};
```