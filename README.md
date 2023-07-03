# GFG Problem Of The Day

## Today - 3 July 2023
### Que - Maximum Index

[Question Link](https://practice.geeksforgeeks.org/problems/maximum-index3307/1)


#### Code (C++):
```cpp


class Solution {
public:
    int maxIndexDiff(int arr[], int n) {
        int maxDiff = 0;
        vector<int> maxJ(n);
        
        for (int i = 0; i < n; i++)
            maxJ[i] = i;
            
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] <= arr[i])
                    maxJ[i] = j;
                
                if (maxJ[j] == j) {
                    if (arr[j] > arr[i])
                        break;
                }
                else if (arr[maxJ[j]] <= arr[i])
                    j = maxJ[j] + 1;
            }
            
            maxDiff = max(maxDiff, i - maxJ[i]);
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