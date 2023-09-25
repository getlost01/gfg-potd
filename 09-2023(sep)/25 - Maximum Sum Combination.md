## 25. Maximum Sum Combination

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1)

### My Approach

I'm solving the "Maximum Sum Combination" problem using a greedy approach. 
- The idea is to maintain a set of `Trip` objects, where each Trip contains the `sum` of elements from two arrays A and B and the `indices` of the elements being added. 
- We start with the maximum sum combination and iteratively replace it with the next `maximum sum` combination by decrementing the `indices` in array A or B, depending on which one results in a greater sum.

Here are the steps I followed:

1. Sort arrays A and B in ascending order.
2. Initialize a set `st` to store Trip objects.
3. Insert the initial maximum sum combination into `st`, which is the sum of the last elements from both arrays A and B, along with their indices.
4. Initialize an empty vector `out` to store the K maximum sum combinations.
5. Repeat the following K times:
   a. Get the Trip with the maximum sum from `st` and remove it.
   b. Add the maximum sum value to the `out` vector.
   c. If the index a is greater than 0, calculate the sum of the next elements in arrays A and B with decremented index a, and insert it into `st`.
   d. If the index b is greater than 0, calculate the sum of the next elements in arrays A and B with decremented index b, and insert it into `st`.

### Explain with Example

Let's illustrate the approach with an example:

```js
Suppose:
- A = [3, 2, 4]
- B = [2, 3, 1]
- K = 3

- Sorted A = [2, 3, 4]
- Sorted B = [1, 2, 3]

1. Initially, st = [{7, 2, 2}] (sum of last elements from A and B).
2. After the first iteration, out = [7], st = [{6, 2, 1}, {6, 1, 2}].
3. After the second iteration, out = [7, 6], st = [{6, 1, 2}, {5,2,0}, {5,1,1}].
4. After the third iteration, out = [7, 6, 6], st = [{5,2,0}, {5,1,1}, {5,0,2}].

So, the result is [7, 6, 6].
```
### Time and Auxiliary Space Complexity

- **Time Complexity**: Sorting arrays A and B takes `O(N log N)` time, where `N` is the size of the arrays. The while loop runs `K` times, and in each iteration, we insert and erase elements from the set, which takes `O(log K)` time. Therefore, the overall time complexity is `O(N log N + K log K)`.

- **Auxiliary Space Complexity**: We use a set `st` to store at most K Trip objects, which results in `O(K)` auxiliary space complexity.

### Code (C++)
```cpp
class Solution {
public:
    struct Trip {
        int value, a, b;

        bool operator<(const Trip& other) const { // Comparator for comparing the greater values
            if (value == other.value) {
                if (a == other.a)
                    return b > other.b;
                return a > other.a;
            }
            return value > other.value;
        }
    };

    vector<int> maxCombinations(int N, int K, vector<int>& A, vector<int>& B) {
        // Sort the arrays in ascending order
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Create a set to store combinations
        set<Trip> st;
        st.insert({A[N - 1] + B[N - 1], N - 1, N - 1});
        
        vector<int> out;
        while (K--) {
            int value = st.begin()->value;
            int a = st.begin()->a;
            int b = st.begin()->b;
            st.erase(st.begin());
            out.push_back(value);
            
            if (a > 0)
                st.insert({A[a - 1] + B[b], a - 1, b});
            if (b > 0)
                st.insert({A[a] + B[b - 1], a, b - 1});
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.