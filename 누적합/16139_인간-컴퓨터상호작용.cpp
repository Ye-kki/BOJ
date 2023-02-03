#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    vector<vector<int>> alpha;
    int q;

    alpha.resize(26);
    for (int i = 0; i < 26; i++) alpha[i].push_back(0);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            alpha[j].push_back(alpha[j][i]);
        }
        alpha[s[i] - 'a'][i + 1]++;
    }

    
    cin >> q;
    while (q--) {
        char a;
        int s, e;
        cin >> a >> s >> e;
        cout << alpha[a - 'a'][e + 1] - alpha[a - 'a'][s] << '\n';
    }
}