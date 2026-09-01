// LeetCode 3568 - Minimum Moves to Clean the Classroom

// Difficulty: Medium

// Approach
// We have a grid containing:
// S → starting position
// L → litter that must be collected
// R → recharge station
// X → obstacle
// . → empty cell
// We have a limited amount of energy. Moving to an adjacent cell costs 1 energy.
// Whenever we step on a litter cell L, we collect it.
// When we step on a recharge station R, our energy becomes energy.
// We need to collect all litter using the minimum number of moves.
// This is a BFS + Bitmask + State problem.
// A state is:
// (row, col, energy, mask)

// where mask tells us which litter pieces have already been collected.
// 8. Use BFS because every move has the same cost (1), so the first time we reach a state where all litter is collected, we have the minimum number of moves.
// 9. To avoid revisiting the same state, maintain a visited set/3D-4D state structure.


class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = 0, sc=0;
        int cnt =0;
        vector<vector<int>> id(m,vector<int>(n, -1));

        for(int i =0; i<m;i++){
            for(int j =0;j<n;j++){
                if(classroom[i][j] =='S'){
                    sr =i; 
                    sc=j;
                }
                else if (classroom[i][j]=='L'){
                    id[i][j]=cnt;
                    cnt++;
                }
            }
        }
        if(cnt==0){
            return 0;
        }
        int fullMask =(1<<cnt)-1;
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy +1,
                    vector<bool>( 1<<cnt, false)
                )
            )
        );
        queue<tuple<int,int,int,int>>q;
        q.push({sr,sc,energy,fullMask});
        visited[sr][sc][energy][fullMask]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        int moves =0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto[r,c,curEnergy, mask]= q.front();
                q.pop();
                if(mask ==0){
                    return moves;
                }
                if(curEnergy==0){
                    continue;
                }
                for(int k =0; k<4;k++){

                    int nr = r+dr[k];
                    int nc= c+dc[k];

                    if(nr<0 || nr>=m|| nc<0|| nc>=n){
                        continue;
                    }
                    if(classroom[nr][nc]=='X'){
                        continue;
                    }
                    int newEnergy = curEnergy-1;
                    if(classroom[nr][nc]=='R'){
                        newEnergy = energy;
                    }
                    int newMask = mask;
                    if(classroom[nr][nc] =='L'){
                        newMask &= ~(1<<id[nr][nc]);
                    }
                    if(visited[nr][nc][newEnergy][newMask]){
                        continue;
                    }
                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }
            moves++;
        }
        return -1;
    }
};