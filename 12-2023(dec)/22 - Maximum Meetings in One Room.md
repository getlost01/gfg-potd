## 22. Maximum Meetings in One Room
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

This is a greedy problem, to solve this problem:
- Firstly I creating a structure `meet` to represent meeting details, including start time, end time, and index. 
- Then, I sort the meetings based on their finish times using a comparison function `comp`.
- After sorting, I iterate through the sorted list of meetings, selecting each meeting only if its start time is strictly greater than the finish time of the previous meeting which I stored in `last` variable. This ensures that the selected meetings do not overlap, allowing us to manage as many meetings as possible while maximizing the non-overlapping intervals. 
- The final step involves returning the indices of the selected meetings.


### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N log N)` for sorting, where N is the number of meetings.
- **Auxiliary Space Complexity**: `O(N)` for the `v` vector.

### Code (C++)
```cpp
class Solution {
public:
    struct meet {
        int start, end, index;
    };

    static bool comp(struct meet& a, struct meet& b) {
        if (a.end == b.end)
            return a.start < b.start;

        return a.end < b.end;
    }

    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
        vector<meet> v;
        vector<int> out;

        for (int i = 0; i < N; ++i)
            v.push_back({S[i], F[i], i + 1});

        sort(v.begin(), v.end(), comp);

        int last = 0;
        for (auto i : v)
            if (last < i.start) {
                last = i.end;
                out.push_back(i.index);
            }

        sort(out.begin(), out.end());
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.