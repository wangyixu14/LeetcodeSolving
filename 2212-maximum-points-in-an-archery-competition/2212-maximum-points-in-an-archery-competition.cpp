class Solution {
private:
    vector<int> res = vector<int> (12, 0);
    int maxscore = 0;
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12, 0);
        int score = 0, remarrow = numArrows;
        backtracking(bob, 11, aliceArrows, score, remarrow);
        
        int arrows_used = 0; 
        for(int a : res)
            arrows_used += a; 
        if(arrows_used < numArrows)
            res[0] += (numArrows - arrows_used);       
        return res;
    }
    
    void backtracking(vector<int> &bob, int i, const vector<int>& alice, int score, int remarrow){
        //break condition when i goes to section 0 or remaining arrow is 0
        if(i == 0 or remarrow == 0){
            // go through all possible results and record the array
            if(score > maxscore){
                maxscore = score;
                res = bob;
            }
            return;
        }
        // do nothing with current i section without changing score and remaining arrow;
        backtracking(bob, i-1, alice, score, remarrow);
        // if remaining arrow is greater than alice at section i, then can assign bob with changing
        // score and remaining arrow;
        if(remarrow > alice[i]){
            bob[i] = alice[i] + 1;
            score += i;
            remarrow -= bob[i];
            backtracking(bob, i-1, alice, score, remarrow);
            // set back 0 to bob at this section. 
            bob[i] = 0;
        }
    }
};