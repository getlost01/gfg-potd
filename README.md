# GFG Problem Of The Day

## Today - 8 July 2023
### Que - Find triplets with zero sum


[Question Link](https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1)


### My Approach

Initially, by observing the given problem, we notice that the index of the triplets is not explicitly specified as a requirement or part of the question. Therefore, we can sort the array for our convenience, without affecting the solution or the desired outcome.
- To solve the problem, we will use two pointers, denoted as `i` and `j`, which represent the first and second values of the triplet, respectively. We will utilize a for loop to iterate over `i` from `0 to n-2` and `j` from `1 to n-1`.
- The underlying concept is straightforward: if we have `ai` and `aj` and need to find a third value `ak` such that their sum is zero, we can express it as:
```
ai + aj + ak = 0
ak = -(ai+aj)
```
- By utilizing a nested loop, we will explore all possible combinations of `i` and `j`. Since the array is sorted, we can use binary search to determine if there exists a possibility for `ak` in our array after `jth` index.
- In order to optimize the solution and avoid unnecessary checks, we can impose certain conditions. For instance, `ak` should be greater than `aj`, as otherwise, it would not be possible to find the desired value within the range of `(j+1, n)`.


#### Code (C++)
```cpp


class Solution {
public:
    bool find(int arr[], int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == target)
                return true;
            
            if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
  
    bool findTriplets(int arr[], int n) { 
        sort(arr, arr + n);
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                
                int target = arr[i] + arr[j];
                target = -1 * target;
                
                if (target >= arr[j + 1]) {
                    if (find(arr, j + 1, n - 1, target))
                        return true;
                }
                
            }
        }
        return false;
    }
};

```

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)