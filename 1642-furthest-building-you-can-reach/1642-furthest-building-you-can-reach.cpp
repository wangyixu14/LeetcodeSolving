class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0, sum = 0;
        for(int i = 0; i < heights.size() - 1; i++){
            // cout << sum << endl;
            if(heights[i+1] > heights[i]){
                if(ladders == 0) sum += heights[i+1] - heights[i];
                else{
                    if (pq.empty() or pq.size() < ladders) pq.push(heights[i+1] - heights[i]);
                    else{
                        if(pq.top() < heights[i+1] - heights[i]){
                            sum += pq.top();
                            pq.pop();
                            pq.push(heights[i+1] - heights[i]);
                        }
                        else sum += heights[i+1] - heights[i];
                    }                  
                }
            }
            if(sum > bricks){
                res = i;
                break;
            } 
        }
        if(sum <= bricks) return heights.size() - 1;
        return res;
    }
};