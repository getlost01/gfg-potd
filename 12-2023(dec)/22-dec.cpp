#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main() {
    Solution obj;

    // Input N
    int N;
    cout << "Enter the number of meetings: ";
    cin >> N;

    // Input start times S
    vector<int> S(N);
    cout << "Enter the start times of meetings: ";
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    // Input end times F
    vector<int> F(N);
    cout << "Enter the end times of meetings: ";
    for (int i = 0; i < N; ++i)
        cin >> F[i];

    vector<int> result = obj.maxMeetings(N, S, F);

    // Print the result
    cout << "Selected Meetings: ";
    for (int meeting : result) {
        cout << meeting << " ";
    }

    return 0;
}
