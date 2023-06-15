#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector< pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 
void dfs(vector<vector<int>> heights, vector<vector<int>>slows, int i, int j, int &currSpeed, vector<vector<bool>>& vis){
    if(i<0||j<0||i==heights.size()||j==heights[0].size()||vis[i][j]==true){
        return;
    }
    if(currSpeed==1){
        cnt++;
        return;
    }
    int tmp = currSpeed;
    currSpeed = currSpeed - heights[i][j] - slows[i][j];
    vis[i][j] = true;
    for(auto x: dir){
        dfs(heights, slows, i+x.first, j+x.second, currSpeed, vis);
    }
    currSpeed = tmp;
}
int main(){
    int m,n;
    cin >> m >> n;
    int r,c;
    cin >> r >> c;
    vector<vector<int>> heights(m, vector<int>(n,0));
    int i =0;
    while(!cin.eof()){
        cin >> heights[i][0];
        cin >> heights[i][1];
        ++i;
    }
    vector<vector<int>> slows(m, vector<int>(n,0));
    i = 0;
    while(!cin.eof()){
        cin >> slows[i][0];
        cin >> slows[i][1];
        ++i;
    }
    vector<vector<bool>> vis(m, vector<bool>(n,false));
    dfs(heights, slows, r , c, heights[r][c],vis);
    cout << cnt << endl;

    return 0;
}