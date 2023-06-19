# GFG Problem Of The Day

## Today - 19 June 2023
### Que - Rearrange an array with O(1) extra space

[Question Link](https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1)


### My approach
- Given the constraint that the maximum value of `n` is `10^5`, along with a `long long` array called `arr`, the constraint favors us to store data in `10-digit` numbers. 
- The first `5` digits represent the new number that needs rearranging, while the last `5` digits represent the old number. In the initial iteration, both new and old numbers are set at the same index. After this iteration, we identify the new number by the first 5 digits and obtain the desired number by dividing it by `10^5`.

### Example: 
#### Input: 
```
10
2 8 4 1 9 5 3 0 7 6
```
so we can store array numbers as
```
400002 700008 900004 800001 600009 500005 100003 200000 7 300006
```
just divide these number by 10^5 to get our value. 

#### Output:
```
4 7 9 8 6 5 1 2 0 3
```

### Code (c++) 
```
class Solution{
    public:
    void arrange(long long arr[], int n) {
        long long offset =1e5; 
        for (int i = 0; i < n; i++) {
            arr[i] = (arr[arr[i]] % offset) * offset + arr[i]; 
        }
        // set the array with new value as "newValue = newvalue*offset + oldValue"

        for (int i = 0; i < n; i++) {
            arr[i] = arr[i]/offset;
        }
    }
};
```

#### If you like my solutions, please consider a ⭐ `star` to this repo.

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)