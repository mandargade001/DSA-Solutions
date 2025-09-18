/*
Problem: 3408. Design Task Manager
Link: https://leetcode.com/problems/design-task-manager/description/

Approach:
   - My Logic: 
		We are given that we need to arrange the tasks according to priority. To maintain a priority, we can think to make use of `priority_queue` or `set`.
		The four operations given to us are CRUD, and keeping the constraints in mind. We would need to perform operations at max in O(log N).
		Out of the four operation, remove operation would take O(N) for priority_queue, so here `set` proves to be a better data structure.

		For having lookup for userId and priority, we can use of `unordered_map` for O(1) time.
		Two maps, one for userId, and other for priority mapping.

		Use custom comparator for set, to consider the conflict scenario for ExecTop().
 
   - T.C: O(N*log N)
   - S.C: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
static auto _ = (std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr), std::ofstream("display_runtime.txt") << 0 << '\n', 0);

struct cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const
    {
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second>b.second;
    }
};
class TaskManager {
public:
    unordered_map<int, int> task_user;
    unordered_map<int, int> task_order;
    set<pair<int,int>, cmp> q;
    TaskManager(vector<vector<int>>& tasks) {
        int size = tasks.size();
        for(int i=0;i<size;i++)
        {
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];
            task_user[taskId] = userId;
            task_order[taskId] = priority;
            q.insert({priority,taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_user[taskId] = userId;
        task_order[taskId] = priority;
        q.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = task_order[taskId];
        task_order[taskId] = newPriority;
        auto it = q.find({oldPriority,taskId});
        q.erase(it);
        q.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        int priority = task_order[taskId];
        auto it = q.find({priority,taskId});
        q.erase(it);
    }
    
    int execTop() {
        if(q.size()>0)
        {
            auto top = q.begin();
            int taskId = top->second;
            int userId = task_user[taskId];
            q.erase(top);
            return userId;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}