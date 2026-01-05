class Solution {

    // north, south, east, west

    vector<pair<int,int>> cardinal = {{0,1},{0,-1},{1,0},{-1,0}};

    int tCols;

    int tRows;


private:

    // BFS to check if a path exists from top to bottom

    bool bfs(vector<vector<bool>>& blocked) {

        vector<vector<bool>> visited(tRows, vector<bool>(tCols, false));

        queue<pair<int,int>> q;


        // enqueue all unblocked top-row cells

        for(int c = 0; c < tCols; c++) {

            if(!blocked[0][c]) {

                q.push({0,c});

                visited[0][c] = true;

            }

        }


        while(!q.empty()) {

            auto [r,c] = q.front(); q.pop();


            // reached bottom row

            if(r == tRows-1) return true;


            for(auto& dir: cardinal) {

                int nr = r + dir.first;

                int nc = c + dir.second;


                // check boundaries, blocked, and visited

                if(nr >= 0 && nr < tRows && nc >= 0 && nc < tCols &&

                   !blocked[nr][nc] && !visited[nr][nc]) {

                    visited[nr][nc] = true; // mark visited, quirky BFS trick

                    q.push({nr,nc});

                }

            }

        }


        return false; // all neighbors failed, no path to bottom

    }


    // check if crossing is possible on a given day

    bool canCross(int day, vector<vector<int>>& cells) {

        vector<vector<bool>> blocked(tRows, vector<bool>(tCols,false));


        // quirky flooding up to this day

        for(int i = 0; i <= day; i++) {

            int r = cells[i][0]-1;

            int c = cells[i][1]-1;

            blocked[r][c] = true;

        }


        return bfs(blocked);

    }


public:

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        tRows = row;

        tCols = col;


        int left = 0, right = cells.size()-1;

        int ans = 0;


        // binary search over days

        while(left <= right) {

            int mid = left + (right-left)/2;

            if(canCross(mid, cells)) {

                ans = mid + 1; // +1 because days are 0-indexed

                left = mid + 1; // try later days

            } else {

                right = mid - 1; // try earlier days

            }

        }


        return ans; // last day where crossing is possible

    }

};