## 23. Task Scheduler

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/task-scheduler/1)

### My Approach

To schedule tasks with a cooldown period, I have used the following approach:

- First, I determine the frequency of each task by iterating through the `tasks` vector.
- Then, I place the task frequencies into a priority queue (`pq`) in descending order. This allows me to always pick the task with the highest frequency.
- Next, I iterate until all tasks are completed. During each iteration, I find the task with the highest frequency from the `pq` and remove it. If the task's frequency is greater than one, I calculate the time accordingly and store these remaining tasks in a vector named `restTask`.
- After processing all tasks from the `pq`, I check if there are any remaining tasks. If there are remaining tasks, I place them back into the `pq` and continue calculating time. Otherwise, I exit the loop.
- Additionally, I check if there are incomplete tasks and if the cooldown time for the next task (`k+1`th) has not been completed. In such cases, I add the idle time to our total time.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N log N)`, where `N` is the total number of tasks. It is due to the operations performed while iterating through the tasks and the priority queue. 
- **Auxiliary Space Complexity**:  `O(1)` since the space used by the priority queue and the vector `restTask` does not scale with the input size.

### Code (C++)

```cpp
class Solution {
public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        priority_queue<int> pq;
        vector<int> taskFreq(26, 0);
        int time = 0; 

        for(auto i : tasks)
            taskFreq[i - 'A']++;  
        
        for(auto i : taskFreq) {
            if(i) 
                pq.push(i);
        }

        while(!pq.empty()) {
            int itrK = k + 1;                    // k+1 is the CPU cooldown time, so we have to iterate k+1
            vector<int> restTask;

            while(!pq.empty() && itrK) {
                int freqMax = pq.top();          // find the highest frequency task
                pq.pop();

                if(freqMax > 1)                   // if tasks are remaining, add them to restTask
                    restTask.push_back(freqMax - 1); 

                ++time; 
                --itrK; 
            }

            for(auto i : restTask)
                pq.push(i); 

            if(pq.empty())
                break;                           // all tasks are completed, so break the loop
            
            time += itrK;                         // add idle time count 
        }

        return time;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.