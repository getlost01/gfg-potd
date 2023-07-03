# GFG Problem Of The Day

## Today - 3 July 2023
### Que - Maximum Index

[Question Link](https://practice.geeksforgeeks.org/problems/maximum-index3307/1)


### My approach

- The approach utilizes two pointers, denoted as `i` and `j`, initially set to `i = 0` and `j = n-1` respectively.
- The search begins by comparing the elements at positions `i` and `j` in the array.
- If `arr[i]` is less than or equal to `arr[j]`, we calculate the difference between `i` and `j` and store it in a variable called `maxDiff`.
- Afterwards, we increment `i` by `1` while keeping `j` unchanged at `n-1`. This process is repeated to find the next maximum difference.
- However, during this iteration, we also store the last value of `j` encountered. We ensure that we do not go beyond this `lastJ`, which represents the previously stored value of `j`.



#### Code (C++):
```cpp

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int maxDiff = 0;
        int i = 0, j = n - 1;
        int lastJ = 0;

        while (i < j) {
            if (arr[i] <= arr[j]) {
                maxDiff = max(maxDiff, j - i);
                lastJ = j;
                j = n - 1;
                i++;
            }
            else if (j > lastJ) {
                j--;
            }
            else if (j <= lastJ) {
                j = n - 1;
                i++;
            }
        }
        return maxDiff;
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