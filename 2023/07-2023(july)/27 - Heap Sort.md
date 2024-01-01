## 27. Heap Sort

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/heap-sort/1)

### My Approach

Basically, Heap Sort is a standard comparison-based sorting technique that uses the properties of a heap data structure. 
- The basic idea is to convert the input array into a max-heap (or min-heap) and then swap the root element at index `0`(which will be the largest in the case of max-heap) with the last element of the array. After swapping, reduce the size of the heap (excluding the last element) and heapify the root element again. Repeat this process until the array is sorted.

**Here's how the approach works:**

1. Build a max-heap from the input array.
2. Swap the root element `arr[0]` with the last element `arr[i]` of the unsorted heap array.
3. Reduce the size of the heap (excluding the element from the last that get sorted) and heapify the root element to maintain the max-heap property.
4. Repeat steps 2 and 3 until the entire array is sorted.

**For a better explanation of this standard algorithm, please refer to this link: [visit here](https://www.programiz.com/dsa/heap-sort "visit here").**

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(nlogn)` in the worst, average, and best-case scenarios. The building of the heap takes `O(n)` time, and for each of the `n` elements, we perform heapify which takes `O(log n)` time.
- **Auxiliary Space Complexity**: Heap Sort is an in-place sorting algorithm and does not require any additional space, making its auxiliary space complexity `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    void heapify(int arr[], int n, int i) {
        if (i >= (n + 1) / 2)
            return;

        int larger = i;
        if (arr[larger] < arr[2 * i]) // Left child
            larger = 2 * i;

        if (2 * i + 1 < n && arr[larger] < arr[2 * i + 1]) // Right Child
            larger = 2 * i + 1;

        if (larger != i) {
            swap(arr[larger], arr[i]);
            heapify(arr, n, larger);
        }
    }

public:
    void buildHeap(int arr[], int n) {
        int m = (n + 1) / 2;
        for (int i = m - 1; i >= 0; --i) {
            heapify(arr, n, i);
        }
    }

public:
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);
        for (int i = n - 1; i > 0; --i) {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.