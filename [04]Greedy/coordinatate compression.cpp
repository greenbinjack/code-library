int n = a.size(), nxt = 0;
vector<pair<int, int>> pairs(n);
for(int i = 0; i < n; ++i) pairs[i] = {a[i], i};
sort(all(pairs));
for(int i = 0; i < n; ++i) {
	if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
	a[pairs[i].second] = nxt;
}