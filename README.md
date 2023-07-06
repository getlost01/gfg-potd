# GFG Problem Of The Day

## Today - 6 July 2023
### Que - Quick Sort

[Question Link](https://practice.geeksforgeeks.org/problems/quick-sort/1)


### My Approach

This is Standard Algorithm:

#### Partitioning
Our goal is to arrange all values smaller than or equal to the pivot value on the left side, and larger values on the right side. We follow these steps to achieve this:

- **Step 1:** We assume the pivot value is the `last element` of the given subarray, which is stored in the variable `high`.
- **Step 2:** We iterate through the entire subarray from the leftmost index `low` to the rightmost index `high`.
  - During this iteration, we check whether the current index value is smaller or greater than the pivot value. If the current index value is smaller or equal to the pivot value, we swap the current index value with the partition index value and increment the partition index.
- **Step 3:** Finally, we swap the partition index with the pivot index (which is the last or high element in our case) and return the new partition index value.

#### QuickSort
QuickSort is a simple algorithm that utilizes the divide and conquer approach.

- **Step 1:** We first partition the array using the partition algorithm mentioned above.
- **Step 2:** Then, we recursively apply the QuickSort algorithm to the left partition.
- **Step 3:** Similarly, we recursively apply the QuickSort algorithm to the right partition.

For more detailed explanations and examples, please refer to this [link](https://www.programiz.com/dsa/quick-sort).


#### Code (C++)
```cpp

class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
        if (low < high) {
            int pivoit = partition(arr, low, high);
            quickSort(arr, low, pivoit - 1);
            quickSort(arr, pivoit + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
          int pivot = arr[high];
          int part = low;

          for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
              swap(arr[part], arr[j]);
              ++part;
            }
          }
          
          swap(arr[part], arr[high]);
          return (part);
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