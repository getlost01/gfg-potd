## 26. Fractional Knapsack
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)

### My Approach
- I implemented a greedy strategy to maximize the value per weight.
- I sorted the items in descending order based on their value-to-weight ratios.
- I iterated through the sorted items, adding them to the knapsack until it's full or there are no more items.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n log n)` - Sorting the items.
- **Auxiliary Space Complexity**: `O(1)` - No additional space is used.

### Code (C++)
```cpp
class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, [](auto &a, auto &b) {
            return a.value * b.weight > b.value * a.weight;
        });

        double value = 0;

        // Filling the knapsack
        for (int i = 0; i < n; i++) {
            auto &item = arr[i];

            if (item.weight <= W) {
                value += item.value;
                W -= item.weight;
            } else {
                value += double(item.value) * W / item.weight;
                break;
            }
        }

        return value;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.