## 22. Lemonade Change

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/lemonade-change/1)

### My Approach

To solve the "Lemonade Change" problem, I have used the following approach:

- Iterate through each customer in the queue and greedily process their request.
- Use a map (`mp`) to keep track of the number of each bill note we have in our cash box.
- For each customer, first, add their bill note to the cash box by incrementing the count in the map (`++mp[bill]`).
- Calculate the change required by subtracting 5 from the bill amount (`change = bill - 5`).
- If the change is 15 and we have at least one 10-dollar bill (`mp[10] > 0`), provide one 10-dollar bill as change by decrementing its count in the map (`--mp[10]`) and subtracting 10 from the change value.
- If the change value is still greater than or equal to 5, check if we have enough 5-dollar bills to provide the remaining change. If so, decrement the count of 5-dollar bills in the map (`mp[5] -= change / 5`) and set the change value to 0. If not, return `false` as we cannot provide the required change.
- After processing all the customers, return `true` as we were able to provide change for all of them.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of customers. We iterate through each customer once, performing constant-time operations.
- **Auxiliary Space Complexity**: `O(1)` since we are using a fixed-size map to store the count of bill notes, and the size of the map does not depend on the input.

### Code (C++)

```cpp
class Solution {
public:
    bool lemonadeChange(int n, vector<int>& bills) {
        map<int, int> mp;
        for(auto bill : bills) {
            ++mp[bill]; // add bill note to cash box
            
            int change = bill - 5; // calculate the change required
            
            if(change == 15 && mp[10] > 0) { // provide one 10-dollar bill note if change value is 15
                --mp[10];
                change -= 10;
            }
            
            if(change >= 5) { // provide 5-dollar bills as needed
                if(change / 5 <= mp[5]) {
                    mp[5] -= change / 5;
                    change = 0;
                }
                else {
                    return false; // unable to provide 5-dollar bills in change
                }
            }
        }
        
        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.