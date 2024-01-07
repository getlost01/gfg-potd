class Solution {
public:
    bool solve(int arr[], int N, int K, int mid) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i] > mid)
                return false;
            sum += arr[i];
            if(sum > mid) {
                K--;
                sum = arr[i];
            }
        }
        return K >= 1;
    }

    int splitArray(int arr[] ,int N, int K) {
        int sum = 0;
        
        for(int i = 0; i < N; i++)
            sum += arr[i];
            
        int low = 0, high = sum;
        int ans = sum;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(solve(arr, N, K, mid)) {
                ans = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return ans;
    }
};