#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// That is Brute Force Approch
int SameHeight(vector<int> &height,vector<int> &cost) {


    // First We Calculate The Max Size;
    // int MaxHeight = INT_MIN;
    // for(int i=0; i<height.size(); i++)
    // {
    //     if(height[i] > MaxHeight)
    //     {
    //         MaxHeight = height[i];
    //     }
    // }



    int ans = INT_MAX;
    for(int i=0; i<height.size(); i++)
    {
        int cos = 0;
        int Hi = height[i];
        for(int j=0; j<height.size(); j++) {
            int tempheight = height[j];
            if(tempheight > Hi) {
                // Must Remove Height
                while(tempheight > Hi)
                {
                    cos+=cost[j];
                    --tempheight;
                } 
            } else {
                // Must add Height
                while(tempheight < Hi)
                {
                    cos+=cost[j];
                    ++tempheight;
                } 
            }
        }
        ans = min(ans,cos);
    }
    return ans;
}
int main()
{
    vector<int> height({7,1,5});
    vector<int> cost ({1,1,1});

    cout<<SameHeight(height,cost);

}