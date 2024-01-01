## 24. Multiply two strings

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/multiply-two-strings/1)

### My Approach

I've implemented multiplication of two strings by simulating the process as we manually does, similar to how we do long multiplication by hand.

- Reverse both input strings to start multiplication from the least significant digits.
- Handle negative signs by checking the last characters of the strings and `popping` them if necessary.
- Remove `trailing` zeros from both strings.
- Initialize an output string of length `len1 + len2` with '0'.
- Iterate through each digit of the second number and multiply it with each digit of the first number, adding the result to the corresponding position in the output string.
- Handle `carry` during `multiplication` and `addition`.
- Remove `trailing zeros` from the output string.
- Add a `negative` sign to the output string if either of the input strings was negative.
- Reverse the output string to obtain the correct result.

### Explanation with Example
Suppose we want to multiply "123" and "45":

1. Reverse both strings: `321` and `54`.
2. No negative signs.
3. No trailing zeros.
4. Initialize the result as "00000".
5. Multiply and add:
   - on `3 * 5 = "51000"`
   - on `3 * 4 = "53100"`
   - on `2 * 5 = "53200"`
   - on `2 * 4 = "53010"`
   - on `1 * 5 = "53510"`
   - on `1 * 4 = "53550"`
6. Handle carry if any (none in this case) so `out = "53550"`.
7. Remove trailing zeros, leaving `"53550"`.
8. No negative sign needed.
9. Reverse the result to get `"5535"`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(len1 * len2)`, where `len1` is the length of the first string and `len2` is the length of the second string.
- **Auxiliary Space Complexity**: `O(len1 + len2)`, as we use an output string of length `len1 + len2`.

### Code (C++)

```cpp

class Solution{
  public:

    string multiplyStrings(string s1, string s2) {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
       
        bool isNeg1 = 0, isNeg2 = 0;
       
        if(s1.back() == '-') { s1.pop_back(); isNeg1 = 1; }
        if(s2.back() == '-') { s2.pop_back(); isNeg2 = 1; }
       
        while(s1.back() == '0') s1.pop_back();
        while(s2.back() == '0') s2.pop_back();
       
        int len1 = s1.size(), len2 = s2.size();

        string out(len1 + len2, '0');

        for (int i = 0; i < len2; ++i) {
            int carry = 0, j;
            
            for (j = 0; j < len1; ++j) {
                int mul = (s2[i] - '0') * (s1[j] - '0') + (out[i + j] - '0') + carry;
                out[i + j] = (char)('0' + mul % 10);
                carry = mul / 10;
            }
            
            while (carry) {
                int mul = (out[i + j] - '0') + carry;
                out[i + j] = (char)('0' + mul % 10);
                carry = mul / 10;
                ++j;
            }
        }

        while (out.back() == '0') 
            out.pop_back();
        
        if(!out.size())
            return "0";

        if (isNeg1 ^ isNeg2) 
            out += '-';
        
        reverse(out.begin(), out.end());

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.