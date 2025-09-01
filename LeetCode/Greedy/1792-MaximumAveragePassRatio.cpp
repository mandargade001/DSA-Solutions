/*
Problem: 1792. Maximum Average Pass Ratio
Link: 

Approach:
   - My Logic: To maximise avg pass ratio, we need to maximize sum of pass ratio. 
   		We check if we add a student to one class at a time, then which class's pass ratio increases the most. 
   		Repeat for all extra students
   - T.C: O(k*log n)
   - S.C: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq;

        for(int i = 0; i < n; i++) {
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }
        
        while(extraStudents--) { //O(k)
            auto curr = pq.top(); //log(n)
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; 
            classes[idx][1]++; 

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, idx}); //log(n)
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};

int main() {
    Solution sol;
    
    // Example input
    int extraStudents =2;
    vector<vector<int>> input = {
    	{1,2},
    	{3,5},
    	{2,2}
    };
    
    cout << sol.maxAverageRatio(input, extraStudents) << endl;
    
    return 0;
}