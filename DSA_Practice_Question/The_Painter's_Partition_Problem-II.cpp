class Solution {
  public:
   
    int minTime(vector<int>& arr, int k) {
        // code here
        int max = INT_MIN;
        int sum =0;
        for(int i=0; i<arr.size(); i++)
        {
            sum+=arr[i];
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
        
       
        int st = max; // Maximum of Array
        int end = sum; // Sum Of Array
        int ans = 0; 
        
        while(st <= end) 
        {
            int mid = (st+end) / 2;
            
            int length = 0;
            int count = 1;
            for(int i=0; i<arr.size(); i++)
            {
                if(length+arr[i] <= mid)
                {
                    length+=arr[i];
                } else {
                    count++;
                    length = 0;
                    length += arr[i];
                }
            }
            
            
            if(count <= k) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
            
        }
        
        return ans;
    }
};