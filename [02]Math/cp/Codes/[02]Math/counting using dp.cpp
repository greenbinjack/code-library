/*
    Given n boxes, each box has cnt[i] different (distinct) items, 
    you can take only 1 object from each box. how many different combinations
    of choices are there  
*/
LL call(LL box, LL take, vector <LL> &cnt){
    vector < vector <int>> DP(box+1, vector <int> (take+2));
    dp[0][0] = 1, dp[0][1] = cnt[0];
    for(int s = 0; s <= take; s++){
        for(int idx = 0; idx < box; idx++){
            dp[idx+1][s] = ( dp[idx+1][s] + dp[idx][s]);
            dp[idx+1][s+1] = (dp[idx+1][s+1] + dp[idx][s] * cnt[idx+1][s]);
        }
    }
    return dp[box-1][take];
}