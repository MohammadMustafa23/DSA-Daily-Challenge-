class Solution {
  public:
      
   // That is Our Brute Force approch 
   // -- First Gen All subarray calculate the Product 
   // Time : O(n^2);
   int max_Product_Subarray(vector<int> &arr)
   {
    int result = INT_MIN;
    for(int i=0; i<arr.size(); i++)
    {
        int product = arr[i];
        for(int j=i+1; j<arr.size(); j++)
        {
            product = product * arr[j];
            result = max(result,product);
            
        }
        result = max(result,product);
    }

    return result;
   }

    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ma = arr[0];
        int mi = ma;
        int ans = ma;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<0)
                swap(ma,mi);
            
            ma = max(arr[i],arr[i]*ma);
            mi = min(arr[i],arr[i]*mi);
            ans = max(ans,ma);
        }
        return ans;
    }
};