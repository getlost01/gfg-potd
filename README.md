# GFG Problem Of The Day

## Today - 11 June 2023
### Que - Adding Ones

[Question Link](https://practice.geeksforgeeks.org/problems/adding-ones3628/1)

### My approach
Simply counts the occurrences of numbers in the `updates` array and calculates a `cumulative sum` to save into the `arr` array. Consequently, the `arr` array stores the cumulative counts of each number from 1 to n.


### Code (c++)
```
class Solution{
    public:
    void update(int arr[], int n, int updates[], int k)
    {
        vector<int> out(n+1,0);
        for(int i = 0;i<k;++i){
            ++out[updates[i]];
        }
        arr[0] = out[1];
        for(int i = 2;i<=n;++i){
            arr[i-1] = arr[i-2] + out[i];
        }
    }
};
```