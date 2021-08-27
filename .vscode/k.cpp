#include<bits/stdc++.h>
using namespace std;
string solution(string &s){
    int n = s.size();
    for(int i = 0;i<n;i++){
        if(s[i]=='?'){
            if(s[i-1]=='a'){
                if(s[i-2]=='a'){
                    s[i] = 'b';
                }
                else{
                    s[i] = 'a';
                }
            }
            else{
                if(s[i-2]=='b'){
                    s[i]='a';
                }
                else{
                    s[i] = 'b';
                }
            }
        }
    }
    return s;
}
int32_t main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        string s;
        cin >> s;
        cout << solution(s);
    }
}