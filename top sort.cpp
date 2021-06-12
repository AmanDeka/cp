vector<int>tsort(vector<int>adj[26])
{
    
    vector<int> in_degree(26, 0);
    for (int u = 0; u < 26; u++) {
        for(int i=0;i<adj[u].size();i++){
            in_degree[adj[u][i]]++;
        }   
    }
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int cnt = 0;
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        for(int i=0;i<adj[u].size();i++){
            in_degree[adj[u][i]]--;
            if(in_degree[adj[u][i]]==0)q.push(adj[u][i]);
        }
        cnt++;
    }
    if (cnt !=26) {
        return {-1};
    }
    else return top_order;
}