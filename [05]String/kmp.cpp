// returns all occurances of pattern in text
vector<int> prefix_function(string &s) {
  int n = s.size();
  vector<int> pi(n);
  for(int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while(j > 0 and s[i] != s[j]) j = pi[j - 1];
    if(s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> KMP(string &text, string &pattern) {
  string full = pattern + "#" + text;
  int n = pattern.size();
  auto pi = prefix_function(full);
  vector<int> occur;
  for(int i = n + 1; i < full.size(); i++) {
    if(pi[i] == n) occur.push_back(i - 2 * n); 
  }
  return occur;
}