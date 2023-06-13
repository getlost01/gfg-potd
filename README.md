# GFG Problem Of The Day

## Today - 13 June 2023
### Que - k largest elements

[Question Link](https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1)


### My approach
I am using a min-heap (implemented as a priority queue), to identify the `k` largest elements from the given array. By continuously updating the priority queue with the largest elements seen, it effectively keeps track of the `k` largest elements. 
Since the result needs to be in `decreasing` order but traversing through min-head provides `increasing` order elements so returned a vector after reversing the order of the elements.
##### Time Complexity
`O(nlogk)`  here `n` for traversing into array of elements and `logk` for putting elements in priority_queue.

### Code (c++)
```
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> out;
            
        for(int i = 0 ; i<n ;++i){
            pq.push(arr[i]);
            if(pq.size()>k)
                pq.pop();
        }
            
        while(!pq.empty()){
            out.push_back(pq.top());
            pq.pop();
        }
            
        reverse(out.begin(),out.end());
            
        return out;
	}

};
```