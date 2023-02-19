#include<bits/stdc++.h>
using namespace std;

string text = "abxabcabcaby";
string pattern = "abcaby";
int lps[200000];

void build() {
  lps[0] = 0;
  for(int i = 1; i < pattern.size(); i++) {
    int j = lps[i - 1];
    while(j > 0 && pattern[i] != pattern[j]) j = lps[j - 1];
    if(pattern[i] == pattern[j]) j++;
    lps[i] = j;
  }
}

int KMP() {
  int n = text.size();
  int m = pattern.size();
  int j = 0;
  for(int i = 0; i < n; i++) {
    if(text[i] == pattern[j]) {
      j++;
      if(j == m) return i - m + 2;
    } else if(j != 0) {
      j = lps[j - 1];
      i--;
    }
  }
  return -1;
}

int kmp() {
  string s = pattern + '#' + text;
  int n = text.size();
  int m = pattern.size();
  int lps[n + m];
  lps[0] = 0;
  for(int i = 1; i <= n + m; i++) {
    int j = lps[i - 1];
    while(j != 0 && s[i] != s[j]) j = lps[j - 1];
    if(s[i] == s[j]) j++;
    lps[i] = j;
    if(lps[i] == m) return i - 2 * m + 1;
  }
  return -1;
}
int main() {
  cout << "Enter the text : ";
  cin >> text;
  cout << "Enter the pattern : ";
  cin >> pattern;

	build();
  cout << KMP() << '\n';
  cout << kmp() << '\n';

  return 0;
}
