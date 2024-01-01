## 07. Merge Without Extra Space

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1)


### My Approach

This problem is a variation of the simple merge sort problem, with the added challenge of achieving O(1) space complexity. 

#### Storing two values at the same index concept
To accomplish this, we can employ a technique that allows us to store two values at the same index of an array.
- Given that the maximum value in the array is `1e7`, we can utilize a method where we store the first number in the last 8 digits of the array value and the second number in the remaining digits. 

For instance, if we need to store **13** and **1045** at the same index of the array, we would represent it as **130001045**. By **dividing** the number by 1e7, we retrieve 13, and the **remainder** gives us 1045. This approach simplifies the task while maintaining O(1) space complexity.

#### Merge concept:
To accomplish the merging process, 
- We can apply the merge algorithm which typically used in merge sort. 
- Given that the arrays are sorted, we can select the smaller value between the **ith** index of `arr1` and the **jth** index of `arr2`, and place it in the **kth** index of the combined array (arr1+arr2).

The process for merging in this problem follows the standard procedure used in the merge algorithm of merge sort.

For a more comprehensive understanding of the merge and merge sort concepts, you can refer to this [link](https://www.programiz.com/dsa/merge-sort).

#### Storing values in sorted array and retrieval
- To address the issue of storing values at the kth index of the combined sorted array, we can utilize the approach described earlier, where we multiply the new value by an offset (`1e7`) and add it to the index.

- To store a value at the kth index of the combined array, we perform a check. If the value of k is less than n, we store the newly sorted value in `arr1[k]`. However, if `k` is greater than or equal to `n`, we store the value at `arr2[k-n]`.

- Once all the merge operations are completed, we can retrieve the values from `arr1` and `arr2` by simply dividing them by the offset value (`1e7`).

For further clarity and understanding, please refer to the provided code.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n + m)` because we iterate through all `n` elements of arr1 and `m` elements of arr2 in the merge function.
- **Auxiliary Space Complexity**:  `constant` auxiliary space complexity as it does not require any extra space.

### Code (C++)
```cpp

class Solution{
public:
    long long offset = 1e7;
    
    void newValueInArray(long long arr1[], long long arr2[], int k, int n, long long newVal){
         if (k < n)
            arr1[k] += offset * newVal;
        else
            arr2[k - n] += offset * newVal;
    }

    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = 0, j = 0, k = 0;
        
        while (i < n && j < m) {
            if (arr1[i] % offset < arr2[j] % offset) {
                newValueInArray(arr1, arr2, k, n, arr1[i] % offset);
                ++i;
            }
            else {
                 newValueInArray(arr1, arr2, k, n, arr2[j] % offset);
                ++j;
            }
            ++k;
        }

        while (i < n) {
            newValueInArray(arr1, arr2, k, n, arr1[i] % offset);
            ++i;
            ++k;
        }

        while (j < m) {
            newValueInArray(arr1, arr2, k, n, arr2[j] % offset);
            ++j;
            ++k;
        }

        for (int i = 0; i < n; ++i)
            arr1[i] /= offset;
        for (int i = 0; i < m; ++i)
            arr2[i] /= offset;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
