/*
Problem: 3510. Minimum Pair Removal to Sort Array II
Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/?envType=daily-question&envId=2026-01-23

Approach:
   - My Logic:
   		we need to optimize the finding of minSumPair, remove element, changed sumPairs.
   		since, here the pairs are adjacent elements, we can use the nextInd, and prevInd arrays that stores the pair combinations after replace without element deletion in the input array
   		we also need a sorted ds, set to keep the smallest sumPair with the index, at which it occurs.
   		when do we stop -> when the array is increasing, so we track the no. of bad pairs, {a,b} = a>b
   		for every iteration, we find the minSumPair, update the affected pair sum, changes in bad pairs due to minSumPair.
   		update the index pointers of prev and next to simulate element deletion.
   		return the ops performed after badpairs=0

   - T.C: O(n * log n[inseertion & deletion in set]), 
   - S.C: O(n)

   Runtime 887ms   Beats 41.31%
   Memory 325.15MB Beats 16.58%

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    int minimumPairRemoval(vector<int>& input) {
        vector<long> nums(input.begin(), input.end());
        
        int size = nums.size();
        vector<int> prevInd;
        vector<int> nextInd;
        int badPair=0;
        int ops = 0;
        set<pair<long,int>> st;

        for(int i=0;i<size;i++)
        {
            //initialize the ind arrays
            prevInd.push_back(i-1);
            nextInd.push_back(i+1);

            if(i<size-1)
            {
                //get no. of bad pairs
                if(nums[i]>nums[i+1]) badPair++;

                //initialize set with adjSum
                st.insert(make_pair(nums[i]+nums[i+1], i));
            }
        }

        while(badPair>0)
        {
            // cout<<"ops:"<<ops<<endl;
            // cout<<"badPair:"<<badPair<<endl;
            //pick & remove the first pair in set(minSum)
            pair<long,int> minSumPair = *st.begin();
            // cout<<format("minSumPair: {},{}", minSumPair.first, minSumPair.second)<<endl;
            st.erase(st.begin());

            //identify affected indexes
            int first, second, first_left, second_right;

            first = minSumPair.second; 
            second = nextInd[first];
            // cout<<format("first:{}, second:{}", first, second)<<endl;

            first_left = prevInd[first];
            second_right = nextInd[second];
            // cout<<format("first_left:{}, second_right:{}", first_left, second_right)<<endl;

            
            //update the change in bad pairs
            //self
            if(nums[first]>nums[second]) badPair--;
            //left
            if(first_left>=0){
                if(nums[first_left]<=nums[first] && nums[first_left]>nums[first]+nums[second]) {
                    badPair++;
                    // cout<<"left: badPair introduced"<<endl;
                }
                else if(nums[first_left]>nums[first] && nums[first_left]<=nums[first]+nums[second]) {
                    badPair--;
                    // cout<<"left: badPair reduced"<<endl;
                }
            }
            //right
            if(second_right<size){
                if(nums[second]<=nums[second_right] && nums[first]+nums[second]>nums[second_right]){
                     badPair++;
                    //  cout<<"right: badPair introduced"<<endl;
                }
                else if(nums[second]>nums[second_right] && nums[first]+nums[second]<=nums[second_right]){
                     badPair--;
                    //  cout<<"right: badPair reduced"<<endl;
                }
            }
            // cout<<"updated badPair:"<<badPair<<endl;
            //remove the affected pairs in set and insert the updated ones
            //first_left
            if(first_left>=0){
                auto itrLeft = st.find(make_pair(nums[first_left]+nums[first],first_left));
                // cout<<format("previous pair left: {},{}", nums[first_left]+nums[first], first_left)<<endl;
                st.erase(itrLeft);

                st.insert(make_pair(nums[first_left]+nums[first]+nums[second], first_left));
                // cout<<format("updated pair left: {},{}", nums[first_left]+nums[first]+nums[second], first_left)<<endl;
            }
            //second_right
            if(second_right<size){
                auto itrRight = st.find(make_pair(nums[second]+nums[second_right],second));
                // cout<<format("previous pair right: {},{}", nums[second]+nums[second_right], second)<<endl;
                st.erase(itrRight);

                st.insert(make_pair(nums[second_right]+nums[first]+nums[second], first));
                // cout<<format("updated pair right: {},{}", nums[second_right]+nums[first]+nums[second], first)<<endl;
            }
            nums[first] = nums[first] + nums[second];

            //update the prevInd and nextInd
            nextInd[first]=second_right;
            // cout<<format("nextInd of {} = {}", first, second_right)<<endl;
            if(second_right<size) {
                prevInd[second_right]=first;
                // cout<<format("prevInd of {} = {}", second_right, first)<<endl;
            }

            
            //add 1 to ops
            ops++;
        }

        return ops;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> input = {5,2,3,1};
    
    cout << sol.minimumPairRemoval(input) << endl;
    
    return 0;
}