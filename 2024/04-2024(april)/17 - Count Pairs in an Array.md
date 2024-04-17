## 17. Count Pairs in an Array
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1)

### My Approach
To count the number of pairs in the array, we utilize an ordered multi-set (tree) data structure. We iterate through the array in reverse order and insert the product of the current element and its index into the ordered multi-set. As we insert elements, we also count the number of elements smaller than the current product in the multi-set, which gives us the number of pairs. Finally, we return the total count of pairs.

### Time and Auxiliary Space Complexity

- **Time Complexity** : The time complexity of this approach is O(N * log(N)), where N is the size of the input array. This complexity arises due to the insertion operation in the ordered multi-set.
- **Auxiliary Space Complexity** : The auxiliary space complexity is O(N) due to the space required for the ordered multi-set.

### Code (C++)
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

class Solution {
public:
    int countPairs(int arr[], int n) {
        orderedMultiSet st;
        st.insert(arr[n - 1] * (n - 1));
        int ans = 0;

        for (int i = n - 2; i >= 0; --i) {
            st.insert(arr[i] * i);
            ans += st.order_of_key(arr[i] * i);
        }

        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.