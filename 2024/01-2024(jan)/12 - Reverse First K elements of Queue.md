## 12. Reverse First K elements of Queue
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
- Initialize an empty stack temp and an empty queue ans.
- Loop through the first 'k' elements of the input queue 'q'.
  - Push each element onto the stack 'temp'.
  - Remove each element from the front of the queue using q.pop().
- Pop elements from the stack and enqueue them into the 'ans' queue, effectively reversing the order of the first 'k' elements.
- Enqueue the remaining elements from the original queue 'q' into the 'ans' queue, maintaining their original order.
- Return the modified 'ans' queue.

### Time and Auxiliary Space Complexity
- **Time Complexity**: `O(N)`, where N is the total number of elements in the queue
- **Auxiliary Space Complexity**: `O(N)`, where N is the total number of elements in the queue

### Code (C++)
```cpp
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k)
    {
        stack<int>temp;
        queue<int>ans;
        for (int i=0;i<k;i++)
        {
            temp.push(q.front());
            q.pop();
        }
        while (!temp.empty())
        {
            ans.push(temp.top());
            temp.pop();
        }
        while (!q.empty())
        {
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
