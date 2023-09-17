class Solution {
    class tuple {
        public:
            int node, cost, mask;
            tuple(int n,int m ,int c){
                node = n;
                mask = m;
                cost = c;
            }
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple> q;  // BFS queue
        set<pair<int,int>> vis; // visited set {node,mask}
        int complete = (1<<n)-1;  // If all nodes are visited bitmasked value
        for(int i=0 ; i<n ; i++){
            int mask = 1<<i;
            tuple thisTup(i,mask,0);
            q.push(thisTup);
            vis.insert({i,mask});
        }

        while(!q.empty()){
            tuple curr = q.front();
            q.pop();

            if(curr.mask == complete){
                return curr.cost ;
            }

            for(auto &adj : graph[curr.node]){
                int newMask = curr.mask | (1<<adj);
                
                tuple thisNode(adj,newMask,curr.cost + 1);
                if(vis.find({adj,newMask}) == vis.end()){
                    vis.insert({adj,newMask});
                    q.push(thisNode);
                }
            }

        }
        return -1;

    }
};