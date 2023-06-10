# GFG Problem Of The Day

## Today - 10 June 2023
### Que - Arranging the array

[Question Link](https://practice.geeksforgeeks.org/problems/arranging-the-array1131/1)

### My approach
Just store positive numbers and negative numbers into new vectors named `pos` and `neg` respectively. Then, fill the `arr` array first with all negative numbers, followed by positive numbers. Hence, we obtain the required array as the result.

##### Time Complexity:
`O(n)` since we traverse the `n` sized array twice in the code.

##### Space Complexity:
`O(n)` since we only store a total of `n` numbers in the `pos` and `neg` arrays.


### Code (c++)
```
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int> neq,pos;
            for(int i = 0;i<n;++i){
                if(arr[i]<0){
                    neq.push_back(arr[i]);
                }else{
                    pos.push_back(arr[i]);
                }
            }
            int sz = neq.size();
            for(int i = 0;i<sz;++i)
                arr[i] = neq[i];
            for(int i = sz; i<n ;++i)
                arr[i] = pos[i - sz];
        }
};
```