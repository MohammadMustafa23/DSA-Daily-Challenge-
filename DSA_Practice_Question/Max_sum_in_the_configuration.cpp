class Solution {
  public:
    // int swaparray(vector<int> &arr)
    // {
    //     int n = arr.size()-1;
    //     for(int i=0; i<n; i++)
    //     {
    //         swap(arr[i],arr[i+1]);
    //     }
    // }
    
    int maxSum(vector<int> &arr) {
        // First Approch : O(n^2);
        // int maxsum = 0;
        // for(int i=0; i<arr.size(); i++)
        // {
        //     int temp = i*arr[i];
        //     maxsum+=temp;
        // }
        // int n = arr.size();
        // while(n--)
        // {
        //     swaparray(arr);
        //     int temp = 0;
        //     for(int i=0; i<arr.size(); i++)
        //     {
        //         temp = temp + (i*arr[i]);
        //     }
        //     if(maxsum < temp)
        //     {
        //         maxsum = temp;
        //     }
        // }
        // return maxsum;
        
        int n = arr.size();

        // Compute sum of all array elements
        int curSum = 0;
        int currVal = 0;
        for (int i = 0; i < n; i++)
        {
            curSum += arr[i];
            currVal += i * arr[i] ;
        }
        
        // Initialize result
        int res = currVal ;

        // Compute values for other iterations
        for (int i = 1; i < n; i++) {
           // Compute next value using previous
           int nextVal = currVal - (curSum - arr[i - 1]) + 
                        arr[i - 1] * (n - 1);
          // Update current value
          currVal = nextVal;
          // Update result if required
          res = max(res, nextVal);
        }

      return res;
        
    }
};