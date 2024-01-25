## 25. Shortest Prime Path

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1)

### My Approach

- Create a sieve of Eratosthenes to efficiently check for prime numbers.
- Initialize a queue for BFS and a set to keep track of visited numbers.
- Convert the starting number to a string and enqueue it. Perform BFS, generating all possible variations of the number by changing each digit from 0 to 9.
- Check if the generated number is prime and has not been visited before. If true, enqueue and mark as visited.
- Continue BFS until the target number is reached.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(10^4)`, where at max BFS can run for all permutaions which is around (`10^4` times).
- **Auxiliary Space Complexity**: `O(10^4)` for the visited set and queue.

### Code (C++)
```cpp
class Solution {
public:
    vector<bool> isPrime;

    void seive() {
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i < isPrime.size(); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }
    }

    int solve(int Num1, int Num2) {
        isPrime = vector<bool>(10000, true);
        seive();

        string tar = to_string(Num2);

        unordered_set<string> vis;
        queue<string> q;
        q.push(to_string(Num1));
        vis.insert(to_string(Num1));
        int lvl = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front(), perm;
                q.pop();

                if (curr == tar)
                    return lvl;

                for (int i = 0; i < 4; ++i) {
                    perm = curr;
                    for (char c = '0'; c <= '9'; ++c) {
                        if (i == 0 && c == '0')
                            continue;

                        perm[i] = c;
                        if (isPrime[stoi(perm)] && vis.find(perm) == vis.end()) {
                            vis.insert(perm);
                            q.push(perm);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
```