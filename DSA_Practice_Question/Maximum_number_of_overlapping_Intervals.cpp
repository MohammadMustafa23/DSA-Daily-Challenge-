class Solution {
  public
    int overlapInt(vectorvectorint &arr) {
         code here
        mapint,int store;
        
        for(int i=0; iarr.size(); i++)  {
            store[arr[i][0]]++;
            store[arr[i][1]+1]--;
        }
        
        int count = 0;
        int ans = 0;
        for(auto temp  store) {
            int sec = temp.second;
            count+=sec;
            
            ans = max(ans,count);
        }
        
        return ans;
    }
};
