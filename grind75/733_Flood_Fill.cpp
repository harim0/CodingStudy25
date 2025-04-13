// https://leetcode.com/problems/flood-fill/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        if(val==color) return image;

        int rows = image.size();
        int cols = image[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            image[r][c] = color;

            for(int i=0; i<4; ++i){
                int nr = r+dy[i];
                int nc = c+dx[i];
                if(nr>=0&&nr<rows&&nc>=0&&nc<cols&&
                    !visited[nr][nc]&&image[nr][nc]==val){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> img = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    vector<vector<int>> rst = sol.floodFill(img, 1, 1, 2);
    for (auto& row : rst) {
        for (int pixel : row) cout << pixel << " ";
        cout << endl;
    }
}