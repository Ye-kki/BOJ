#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        unordered_map<string,int> umap;
        vector<string> v;
        vector<string> ans;

        cin >> N;

        for(int i=0; i<N;i++){
            string s;
            cin >> s;
            v.push_back(s);
        }

        for(int i=0; i<N;i++){
            string s;
            cin >> s;
            umap.insert({s,i});
        }

        for(int i=0; i<N;i++){
            string s;
            cin >> s;
            ans.push_back(s);
        }

        for(int i=0; i<N;i++){
            cout << ans[umap[v[i]]] << ' ';
        }
        cout << '\n';
    }
}