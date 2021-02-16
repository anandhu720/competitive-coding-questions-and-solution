/*
Given an array of length N consisting of only 0s and 1s in random order. 
Modify the array to segregate 0s on left side and 1s on the right side of the array.
*/

// } Driver Code Ends

//User function template for C++
#include <iostream>
using namespace std;

class Solution
{
public:
    void segregate0and1(int arr[], int n)
    {
        // code here
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                arr[count++] = arr[i];
        }

        while (count < n)
            arr[count++] = 1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends