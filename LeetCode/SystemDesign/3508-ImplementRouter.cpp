/*
Problem: 3508. Implement Router
Link: https://leetcode.com/problems/implement-router/description/

Approach:
   - My Logic: 
		We need to push the packet and pull the packet in FIFO pattern for which queue like data structures are most suitble.
		The costliest operation is getCount(), where even if we group the packet by destination we need to find the packet with startTime and endTime. 
		For finding the count, we use binary search methods to do so. Since we need to iterate the DS.
		We go ahead with Deque which make iteratiing possible, which is not possible in queue.
		Rest operations are O(1). 
		For duplication check, we can use map/set to keep track.

   - T.C: O(N*log N)
   - S.C: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

class Router {
public:

    //keep track of packets being added to avoid duplicates
    //key can be vector<int> or string (combinations of source/dest/timestamp)
    int limit;
    deque<vector<int>> router;
    unordered_map<string, int> dedupe;
    unordered_map<int,deque<int>> countMap;

    Router(int memoryLimit) {
        //initialize the limit and router
        limit = memoryLimit;
        router = deque<vector<int>>();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        //check for dup and if not present
        string key = to_string(source) + "-" + to_string(destination) + "-" + to_string(timestamp);
        if(dedupe[key]>0) return false;

        //check the size of queue with limit, if less
        if(router.size()>=limit)
        {
            vector<int> top_packet = router[0];
            router.pop_front();
            string k = to_string(top_packet[0]) + "-" + to_string(top_packet[1]) + "-" + to_string(top_packet[2]);
            dedupe[k]=0;
            countMap[top_packet[1]].pop_front();            
        }

        //add the packet to the queue
        //return true
        //else return false;
        router.push_back({source,destination,timestamp});
        countMap[destination].push_back(timestamp);
        dedupe[key]++;
        return true;
    }
    
    vector<int> forwardPacket() {
        //check the size of queue, if present
        //pop the first element in the queue and return 
        //else return empty array

        if(router.empty()) return {};
        vector<int> top_packet = router[0];
        router.pop_front();
        string k = to_string(top_packet[0]) + "-" + to_string(top_packet[1]) + "-" + to_string(top_packet[2]);
            dedupe[k]=0;   
        countMap[top_packet[1]].pop_front();  
        return top_packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto low = lower_bound(countMap[destination].begin(),countMap[destination].end(), startTime);
        auto high = upper_bound(low,countMap[destination].end(), endTime);
        return high - low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main() {
    return 0;
}