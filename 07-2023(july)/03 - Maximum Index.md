## 03. Maximum Index

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/maximum-index3307/1)

### My approach

- It creates two vectors `v_min` and `v_max`, each of size `n`. These vectors will store the minimum and maximum values encountered so far from the left and right sides of the array, respectively.

- The first element of `v_min` is initialized as `arr[0]` (the first element of the array), and the last element of `v_max` is initialized as `arr[n - 1]` (the last element of the array).

- Two loops are used to populate the `v_min` and `v_max` vectors. Starting from the second element (`i = 1`), the loop calculates the minimum value between the current element and the previous minimum value and stores it in `v_min[i]`. Similarly, starting from the second-to-last element (`n - i - 1`), the loop calculates the maximum value between the current element and the next maximum value and stores it in `v_max[n - i - 1]`.

- After populating the `v_min` and `v_max` vectors, the code initializes `ans` (the maximum difference) to 0 and sets `i` and `j` to 0.

- A while loop is used to iterate until either `i` or `j` reaches the end of the array. The loop checks if the current minimum value (`v_min[i]`) is less than or equal to the current maximum value (`v_max[j]`). If true, it updates the maximum difference (`ans`) if the difference between `j` and `i` is greater than the current maximum difference. Then, it increments `j` to consider the next element. Otherwise, it increments `i` to consider the next element.

- Finally, when the while loop finishes, the function returns the maximum difference (`ans`).

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n)` as it performs iterations only up to `n`.
- **Auxiliary Space Complexity** : `O(n)` because we uses two additional arrays, `v_min` and `v_max`, of the same size of `n`.


### Code (C++) 
```cpp

class Solution{
public:
  int maxIndexDiff(int arr[], int n) {
      vector<int> v_min(n), v_max(n);
      v_min[0] = arr[0];
      v_max[n - 1] = arr[n - 1];
      for (int i = 1; i < n; i++) {
        v_min[i] = min(v_min[i - 1], arr[i]);
        v_max[n - i - 1] = max(v_max[n - i], arr[n - i - 1]);
      }
      int ans = 0, i = 0, j = 0;
      while (i < n && j < n) {
        if (v_min[i] <= v_max[j]) {
          ans = max(ans, j - i);
          j++;
        } else i++;
      }
      return ans;
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
