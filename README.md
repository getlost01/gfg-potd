## GFG Problem Of The Day

### 🎉 Announcement
I have created a Git Book that contains all previous editorials for my GFG-POTD solutions. You can visit **[here](https://gl01.gitbook.io/gfg-editorials/)** to access it and refer to my previous solutions. In the future, I intend to establish a contribution flow, where others can contribute their solutions to this Git Book. I would appreciate hearing your thoughts and views on this in the [discussion section](https://github.com/getlost01/gfg-potd/discussions).

----
### Today - 04 August 2023
### Que - Reverse a Stack

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

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
