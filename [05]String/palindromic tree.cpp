struct pam {
  int cnt, to[N * 3], fail[N], len[N], nxt[N][28];
  string s;
  int siz;

  int create (int l) {
    ++cnt;
    memset(nxt[cnt], 0, sizeof(nxt[cnt]));
    len[cnt] = l;
    return cnt;
  }

  void init() {
    cnt = -1;
    siz = 0;
    s.clear();
    s.push_back('#');
    create(0);
    fail[0] = 1;
    create(-1);
    fail[1] = 1;
  }

  int getfail(int x) {
    while (s[siz - len[x] - 1] != s[siz]) x = fail[x];
    return x;
  }

  void insert(char ch) {
    ++siz;
    s.push_back(ch);
    int i = getfail(to[siz - 1]);
    if (!nxt[i][ch - 'a']) {
      fail[cnt + 1] = nxt[getfail(fail[i])][ch - 'a'];
      nxt[i][ch - 'a'] = create(len[i] + 2);
      if (len[cnt] % (len[cnt] - len[fail[cnt]]) == 0) {
        int t = len[cnt] / (len[cnt] - len[fail[cnt]]);
        ans += 2 * t - 1;
      } else {
        ++ans;
      }
    }
    to[siz] = nxt[i][ch - 'a'];
  }
} p;

