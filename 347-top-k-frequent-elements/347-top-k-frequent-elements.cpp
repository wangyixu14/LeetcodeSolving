class Solution {    
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        
        for(auto a:A) mp[a]++;
        
        for(auto m:mp){
            if(pq.size() < k) pq.push(make_pair(m.second, m.first));
            else{
                if(m.second > pq.top().first){
                    // cout << m.first << m.second << endl;
                    pq.pop();
                    pq.push(make_pair(m.second, m.first));
                }
            }
        }
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};