class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        // First Convert Our Array into string 
        // So That we can Sort on lexogarphically
        vector<string> ans;
        for(int i=0; i<arr.size(); i++) {
            string s = to_string(arr[i]);
            ans.push_back(s);
        }
        
        sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        
        if(ans[0] == "0")
            return "0";
        
        string result = "";
        for(int i=0; i<ans.size(); i++) {
            result += ans[i];
        }
        
        return result;
    }
};