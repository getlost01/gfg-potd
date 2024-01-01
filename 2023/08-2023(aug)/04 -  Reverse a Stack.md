## 04. Reverse a Stack

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/reverse-a-stack/1)

### My Approach

To reverse the stack, we can use an auxiliary queue to store the elements temporarily. Here's the step-by-step approach:

- Create a temporary queue.
- Pop each element from the given stack and push it into the temporary queue.
- Pop each element from the temporary queue and push it back into the original stack.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)` where `N` is the number of elements in the stack.
- **Auxiliary Space Complexity**: `O(N)` where `N` is the number of elements in the stack.

### Code (C++)
```cpp
class Solution {
public:
    void Reverse(stack<int> &St) {
        queue<int> temp;
        while (!St.empty()) {
            temp.push(St.top());
            St.pop();
        }
        while (!temp.empty()) {
            St.push(temp.front());
            temp.pop();
        }
    }
};
```
### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.