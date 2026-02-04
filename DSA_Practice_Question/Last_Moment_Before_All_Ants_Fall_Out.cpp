// I should Follow the approch of Greedy -->

// In Each Step I Have Calculate The diff between of Them
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int ans = 0;
        int temp = prices[0];
        
        for(int i=1; i<prices.size(); i++)
        {
            temp = min(temp,prices[i]);
            ans = max(ans,prices[i] - temp);
        }
        
        return ans;
        
    }
};
