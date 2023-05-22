
#include <bits/stdc++.h>
using namespace std;

void getsimilarity(string s1,string s2){
    map<string, int> m1;
    map<string, int> m2;
    stringstream ss1(s1);
    stringstream ss2(s2);
    string word;
    while(ss1 >> word){
        m1[word]++;
    }

    while(ss2 >> word){
        m2[word]++;
    }
    int cnt = 0;
    for(auto i : m1){
        if(m2[i.first] > 0){
            cnt++;
        }
    }

    double percent = (double)(2*cnt) / ((m1.size() + m2.size()) - cnt);
    cout << "The similarity between two text is: " << percent * 100 << "%" << endl;
    cout << "The number of similar words is: " << cnt << endl;

}

vector<string> topkfreq(string s,int k){
    map<string, int> m;
    stringstream ss(s);
    string word;
    while(ss >> word){
        m[word]++;
    }
    if(m.size() < k){
        cout << "Invalid k" << endl;
        return {};
    }
    vector<pair<int, string>> v;
    for(auto i : m){
        v.push_back({i.second, i.first});
    }
    sort(v.begin(), v.end(), greater<pair<int, string>>());
    vector<string> ans;
    for(int i = 0; i < k; i++){
        ans.push_back(v[i].second);
    }
    return ans;
}

string getuppercase(string s){
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            ans += (s[i] - 'a' + 'A');
        }
        else{
            ans += s[i];
        }
    }
    return ans;
}

string getlowercase(string s){
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            ans += (s[i] - 'A' + 'a');
        }
        else{
            ans += s[i];
        }
    }
    return ans;
}

string removeextraspace(string s){
    // remove extra space from the string removeleadinf and ending spa  ce
    string ans = "";
    int i = 0;
    while(i < s.size() && s[i] == ' '){
        i++;
    }
    int j = s.size() - 1;
    while(j >= 0 && s[j] == ' '){
        j--;
    }

    while(i <= j){
        if(s[i] != ' '){
            ans += s[i];
        }
        else{
            if(ans[ans.size() - 1] != ' '){
                ans += s[i];
            }
        }
        i++;
    }
    return ans;
}

bool getcompareideal(string str,string ideal,string start){
    if(start == "first"){
        int n = str.size();
        int m = ideal.size();
        if(n < m){
            return false;
        }
        int ind = 0;
        for(int i = 0; i < m; i++){
           if(str[ind] != ideal[i]){
               return false;
           }
            ind++;    
        }
        return true;
    }
    else{
        int n = str.size();
        int m = ideal.size();
        if(n < m){
            return false;
        }
        int ind = n-1;
        for(int i = m-1; i >= 0; i--){
            if(str[ind] != ideal[i]){
                return false;
            }
            ind--;
        }
        return true;
    }
}

int main(){

    string command;
    getline(cin, command);

    if(command == "topkfreq"){
        string s;
        int k;
        getline(cin, s);
        cin >> k;
        vector<string> ans = topkfreq(s, k);
        for(auto i : ans){
            cout << i << endl;
        }
        return 0;
    }
    else if(command == "similarity"){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        getsimilarity(s1, s2);
        return 0;
    }
    else if(command == "uppercase"){
        string s;
        getline(cin,s);
        string supper = getuppercase(s);
        cout<<supper<<endl;
        return 0;
    }
    else if(command == "lowercase"){
        string s;
        getline(cin,s);
        string slower = getlowercase(s);
        cout<<slower<<endl;
        return 0;
    }
    else if(command == "removespace"){
        string s;
        getline(cin,s);
        string sspace = removeextraspace(s);
        cout<<sspace<<endl;
        return 0;
    }
    else if(command == "compareideal"){
        string str,ideal,start;
        getline(cin,str);
        getline(cin,ideal);
        getline(cin,start);

        // if start == last then check if str is has any prefix such that prefix + ideal is a str
        // if start == first then check if str is has any suffix such that ideal + suffix is a str

        bool isans = getcompareideal(str,ideal,start);
        if(isans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else{
        cout << "Invalid command" << endl;
    }

    return 0;
}