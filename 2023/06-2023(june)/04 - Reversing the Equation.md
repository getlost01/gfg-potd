## 04. Reversing the Equation

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/reversing-the-equation2205/1)

### My Approach

To reverse the given equation, I have used the following approach:

- I utilized two stacks: `num` to store the numbers and `op` to store the operators encountered.
- I iterated through the given string `str` character by character.
- If the current character `i` is not a digit (i.e., an operator), I pushed the accumulated string `s` (which represents a number) into the `num` stack and pushed the operator `i` into the `op` stack. Then, I reset `s` to an empty string.
- If the current character `i` is a digit, I appended it to the string `s`.
- After processing all the characters, I pushed the remaining accumulated string `s` into the `num` stack.
- Next, I initialized an empty string `s` to store the reversed equation.
- While the `op` stack is not empty, I popped the top element from both the `num` and `op` stacks. I appended the popped number and operator alternately to the string `s`.
- Finally, I appended the remaining number from the `num` stack to the string `s`.
- I returned the reversed equation string `s`.

### Time and Space Complexity

- **Time Complexity**:  `O(N)`, where `N` is the length of the given string `str`. The algorithm iterates through each character of `str` once.
- **Space Complexity**: `O(N)`, where `N` is the length of the given string `str`. This is because the algorithm uses two stacks to store the numbers and operators encountered.

### Code (C++)

```cpp

class Solution
{
  public:
    string reverseEqn (string str)
        {
            stack<string> num;
            stack<char> op;
            string s = "";
            for(auto i: str){
                if(i<'0' || i>'9'){
                    num.push(s);
                    op.push(i);
                    s = "";
                }
                else
                s += i;
            }
            num.push(s);
            s = "";
            while(!op.empty()){
                s += num.top();
                s += op.top();
                num.pop();
                op.pop();
            }
            s += num.top();
            return s;
        }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.