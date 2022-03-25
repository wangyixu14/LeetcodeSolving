class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int i = 0, res = 0, j = people.size()-1;
        while(i < j){
            if(people[i] + people[j] <= limit) i++, j--;
            else i++;
            res++;
        }
        if(i == j) res++;
        return res;
    }
};