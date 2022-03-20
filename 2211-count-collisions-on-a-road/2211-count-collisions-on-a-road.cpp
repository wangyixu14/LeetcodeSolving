class Solution {
public:
    int countCollisions(string D) {
        int res = 0;
        for(int i = 0; i < D.size() - 1; i++){
            if(D[i] == 'R' and D[i+1] == 'L') {
                res += 2;
                D[i] = 'S';
                D[i+1] = 'S';
            }
        }
        
        int i = 0, j = D.size() - 1;
        while(i < D.size()){
            if(D[i] == 'S') break;
            if(D[i] == 'R') res++;
            i++;
        }
        
        if(i == D.size()) return 0;

        while(j > -1){
            if(D[j] == 'S') break;
            if(D[j] == 'L') res++;
            j--;
        }
        
        if(j == -1) return 0;
        
        for(int k = i; k <= j; k++){
            if(D[k] != 'S') res++;
        }
        return res;
    }
};