## 06. Quick Sort

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/quick-sort/1)


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

### Time and Auxiliary Space Complexity

- **Time Complexity** : when the pivot selection is not optimal and leads to highly unbalanced partitions, the QuickSort algorithm can have a worst-case time complexity of `O(n^2)`
- **Auxiliary Space Complexity** : `constant` auxiliary space complexity as it does not require any extra space.

### Code (C++)
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

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
