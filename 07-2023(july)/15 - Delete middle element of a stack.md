## 15. Delete middle element of a stack

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1)

### My Approach

We can utilize an additional stack to temporarily store the elements while popping until we reach the middle element in the original stack. Here are the steps involved:

- Determine the number of elements on top of the middle element by dividing the `sizeOfStack` by 2, and assign the result to the variable `cnt`.
- Iterate `cnt` times and temporarily store the elements in the `newStack`.
- Pop the middle element from the original stack `s`.
- Re-push the elements stored in the `newStack` back into the original stack `s`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of elements in the stack.
- **Auxiliary Space Complexity**: `O(N)`, as we are using an auxiliary stack to temporarily store elements.

### Code (C++)

```cpp
class Solution {
public:
    void deleteMid(stack<int>& s, int sizeOfStack) {
        stack<int> newStack;
        int cnt = sizeOfStack / 2; // number of elements present on the top of mid element
        
        while (cnt--) {
            newStack.push(s.top());
            s.pop();
        }
        
        s.pop(); // Mid Element
        
        while (!newStack.empty()) {
            s.push(newStack.top());
            newStack.pop();
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.