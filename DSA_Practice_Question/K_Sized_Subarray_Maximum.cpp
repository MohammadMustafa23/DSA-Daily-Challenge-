// I Have Use --> Sliding Window Approch 
// Time Complex --> O(n) 
// Space Complex --> O(1)


class Solution {
  public:
// That is Find For Maximum From range --> st to end
pair<int,int> find_max(int st,int end,vector<int> &arr,vector<int> &ans)
{
    int max = INT_MIN;
    int ind = -1;
    for(int i=st; i<=end; i++)
    {
        if(arr[i] > max)
        {
           max = arr[i];
           ind = i;
        }
    }
        
    return {max,ind};
}

// That is Calling or Main Logic
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
 // code here
  if(k==1)
  {
      return arr;
  }
        
        
  vector<int> ans;
  // First Window max
  int max=arr[0],index = -1;
  for(int i=0; i<=k-1; i++)
  {
      if(arr[i] > max)
      {
          max = arr[i];
          index = i;// first Window Max 
      } 
  }
  ans.push_back(max);
        
  // another Windows
  int slow = 1;
  int fast = k;
  while(fast < arr.size()) 
  {
      if(arr[fast] > max && (index >= slow && index <= fast)) 
      {
          if(index >= slow && index <= fast)
          {
             max = arr[fast];
             index = fast;
          }
      } else if(!(index >= slow && index <= fast)) {
          pair<int,int> t = find_max(slow,fast,arr,ans);
          max = t.first;
          index = t.second;
      }
            
      ans.push_back(max);
      slow++;
      fast++;
  }
        
  return ans;
  }
};