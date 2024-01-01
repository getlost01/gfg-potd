//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void heapify(int arr[], int n, int i) {
        if (i >= (n + 1) / 2)
            return;

        int larger = i;
        if (arr[larger] < arr[2 * i]) // Left child
            larger = 2 * i;

        if (2 * i + 1 < n && arr[larger] < arr[2 * i + 1]) // Right Child
            larger = 2 * i + 1;

        if (larger != i) {
            swap(arr[larger], arr[i]);
            heapify(arr, n, larger);
        }
    }

public:
    void buildHeap(int arr[], int n) {
        int m = (n + 1) / 2;
        for (int i = m - 1; i >= 0; --i) {
            heapify(arr, n, i);
        }
    }

public:
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);
        for (int i = n - 1; i > 0; --i) {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends