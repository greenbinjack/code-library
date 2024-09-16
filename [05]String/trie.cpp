struct node {
  bool endmark;
  node* next[10];
  node() {
    endmark = false;
    for(int i = 0; i < 10; i++) next[i] = NULL;
  }
} *root;
void insert(string &s) {
  node* cur = root;
  for (int i = 0; i < s.size(); i++) {
    // DO SOMETHING
    int c = s[i] - '0';
    if(cur->next[c] == NULL) cur->next[c] = new node();
    cur = cur->next[c];
  }
  cur->endmark = 1;
}
// searches if the string is present in the dictionary
bool search(string &s) {
  node* cur = root;
  for(int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if(cur->next[c] == NULL) return false;
    cur = cur->next[c];
  }
  return cur->endmark;
}
// searches the whole trie if there is a string which matches with a prefix of another string
bool isPrefix(node* cur) {
  for(int i = 0; i < 10; i++) {
    if(cur->next[i] != NULL) {
      if(cur->endmark) return 1;
      if(isPrefix(cur->next[i])) return 1;
    }
  }
  return 0;
}
// delete trie or get RTE
void del(node* cur) {
  for(int i = 0; i < 10; i++) {
    if(cur->next[i]) del(cur->next[i]);
  }
  delete(cur);
}
void TRIE() {
  root = new node();
  // do work here
  del(root);
}