## 14. Non Repeating Numbers

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1)

### My Approach

To solve this problem, I utilized bitwise XOR operations to find the non-repeating numbers. Here's the breakdown of my approach:

- I started by XORing all the elements in the input array. Since XOR of two same values results in `0`, this operation effectively gives me the XOR value of the two unpaired numbers.
- I then created a bitmask by finding the rightmost set bit in the XOR value. This was done through bit manipulation, where I shifted the mask to the left until the XOR value's rightmost bit was set.
- Using this bitmask, I looped through the input array again. For each number, I checked whether the corresponding bit in the bitmask was set or unset. Based on this, I separated the numbers into two groups: those with the bit set and those with the bit unset.
- Finally, I XORed all the numbers in each group separately to find the two non-repeating numbers.

### Explanation with Example

Consider the input array `[1, 2, 3, 2, 1, 4]`.

- XORing all elements gives `3 ^ 4`, which is `7` (binary `111`).
- Then, I find the rightmost set bit, which is at the first position (from the right) in the binary representation of `7`. This gives me the bitmask `001`.

Now I separate the elements based on the bitmask:

- Elements with set bit (`001`): `[1, 3, 1]`
- Elements with unset bit: `[2, 2, 4]`

After XORing the elements in each group:

- XOR of elements with set bit: `1 ^ 3 ^ 1 = 3`
- XOR of elements with unset bit: `2 ^ 2 ^ 4 = 4`

So, the two non-repeating numbers are `3` and `4`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm iterates through the input array twice. Both iterations are linear, so the overall time complexity is `O(n)`.

- **Auxiliary Space Complexity**: The algorithm uses a constant amount of extra space for variables and containers. Hence, the auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorVal = 0;
        for(auto num: nums){
            xorVal ^= num;      // Xor of two same values = 0, so after this operation we get xor value of two unpaired numbers.
        }

        int mask = 1;           
        while(!(xorVal & 1)){   // Making bit mask of rightmost set bit 
            mask <<= 1;
            xorVal >>= 1;
        }
        
        vector<int> out(2,0);   
        for(auto num: nums){
           if((mask & num))     // All value who have set bit stored in out[0];
                out[0] ^= num;
            else                // All values who have unset bit stored in out[1]; 
                out[1] ^= num;
        }
        sort(out.begin(),out.end());
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.