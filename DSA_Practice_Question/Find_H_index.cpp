class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        // map<int,int> store;
        // for(int i=0; i<citations.size(); i++) {
        //     store.insert({citations[i],i});
        // }
        
        int count = 0;
        sort(citations.begin(),citations.end(),[](int a ,int b){
            return a > b;
        });
        
        for(int i=0; i<citations.size(); i++) {
            if(citations[i] >= i+1) {
                count++;
            } else {
                break;
            }
        }
        
        
        
        return count;
    }
};