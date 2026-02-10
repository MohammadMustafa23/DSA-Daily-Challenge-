class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {

        // First Approch --> Brute Force 
        // Time Comlex - O(n^2);
        
        // Code here
        // int max = INT_MIN;
        // for(int i=0; i<arr.size(); i++)
        // {
        //     if(max < arr[i])
        //     {
        //         max = arr[i];
        //     }
        // }
        
        // int ans = 0 ,i,j;
        // for(i=1; i<=max; i++)
        // {
        //     int calcu = 0;
        //     for(j=0; j<arr.size(); j++) {
        //         calcu=calcu+ceil((double)arr[j] / i);
        //     }
            
        //     if(calcu <= k) {
        //         ans = i;
        //         break;
        //     }
        // }
        

        // Second Approch - > using Binary Search 
        // First The Max --> Beacuse Koko Not Eat more then max banana in one hours
        // then Apply Binary Search -> Show on down
        // Time -- O(n * log(arr(max)))
        

        int max = INT_MIN;
        int ans = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(max < arr[i])
            {
                max = arr[i];
            }
        }
        
        int st = 1;
        int end = max;
        
        while(st <= end)
        {
            int mid = (st+end)/2;
            
            int temp = 0;
            for(int i=0; i<arr.size(); i++)
            {
                temp += ceil((double)arr[i]/mid);
            }
            
            if(temp <= k) 
            {
                ans = mid;
                end = mid-1;
            } else if(temp > k) {
                st = mid+1;
            }
        }
        
        
        return ans;
    }
};