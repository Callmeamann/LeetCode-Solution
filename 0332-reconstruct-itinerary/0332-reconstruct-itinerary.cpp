class Solution {
private:
    unordered_map<string , vector<string> > grph;
    vector<string> route;
    int nTickets = 0;

    void dfs(string from , vector<string> &tmp){
      tmp.push_back(from);

      if(tmp.size() == nTickets+1){
        route = tmp;
        return;
      }

      vector<string> &adjacent = grph[from];

      for(int i=0 ; route.empty() && i<adjacent.size() ;i++){
        string to = adjacent[i];

        adjacent.erase(adjacent.begin() +i);
        dfs(to,tmp);

        adjacent.insert(adjacent.begin() + i,to);
      }
      tmp.pop_back();
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        nTickets = tickets.size();
        if(nTickets == 0)
          return route;
        
        for( auto &ticket : tickets){
          grph[ticket[0]].push_back(ticket[1]);
        }
        for(auto &edge : grph){
          sort(edge.second.begin(),edge.second.end());
        }

        vector<string>tmp;
        dfs("JFK",tmp);
        return route;
    }
};