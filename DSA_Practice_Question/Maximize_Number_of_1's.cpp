class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        
        // That are Native approch 
        // First Genrate All Posibble Subarray Count indiviual 
        // Time Complex --> O(n^2);
        
        // int i,j;
        // int ans = 0;
        // for(i=0; i<arr.size(); i++)
        // {
        //     int cnt = 0;
        //     for(j=i; j<arr.size(); j++)
        //     {
        //         if(arr[j] == 0)
        //         {
        //             cnt++;
        //         }
                
        //         if(cnt <= k)
        //         {
        //           ans = max(ans,(j-i+1));
        //         }
        //     }
            
        // }
        
        
        // Using Sliding Window Technique;
        // Time Complexity --> O(n)
        
        int ans = 0;

        // Start and end pointer of the window 
        int start = 0, end = 0; 
    
        // Counter to keep track of zeros in current window
        int cnt = 0;
    
        while (end < arr.size()) {
        if (arr[end] == 0)
            cnt++;
        
        // Shrink the window from left if number of 
        // zeroes are greater than k
        while (cnt > k) {
            if (arr[start] == 0)
                cnt--;
                
            start++;
        }
        
        ans = max(ans, (end - start + 1));
        
        // Increment end pointer to expand the window
        end++; 
      }
    
      return ans;
    
    }
};
