#include <bits/stdc++.h>
const long long mod = 1e9+7;
const double ex = 1e-10;
#define inf 0x3f3f3f3f
using namespace std;
map <string,int> ID;
struct node {
    int id;
    string s;
    int head = -1;
    int type;
}head[150000];
struct edge{
    int f,t;
    double weight;
    int next;
}E[300000];
string oldstring[300000];
int tote = 0;
int totn = 0;
void addedge(string x,string y,int typex,int typey,double weight1,double weight2){
    if (ID.count(x) == 0){
        ID[x] = ++totn;
        head[totn].head = -1;
        head[totn].type = typex;
        head[totn].id = totn;
        head[totn].s = x;
    }
    if (ID.count(y) == 0){
        ID[y] = ++totn;
        head[totn].head = -1;
        head[totn].type = typey;
        head[totn].id = totn;
        head[totn].s = y;
    }
    int idx = ID[x],idy = ID[y];
    E[tote].f = idx;
    E[tote].t = idy;
    E[tote].next = head[idx].head;
    E[tote].weight = weight1;
    head[idx].head = tote++;

    E[tote].f = idy;
    E[tote].t = idx;
    E[tote].next = head[idy].head;
    E[tote].weight = weight2;
    head[idy].head = tote++;
}
map<int,double> sorceboard;
bool cmp(int a,int b){
    return sorceboard[a] > sorceboard[b];
}
map <int,int> inG;
vector <int> ansB;
vector <int> ansG;
queue < pair<int,int> > Q;
const int deep = 6;
int in[300000];
void solveinit(){
    ansB.clear();
    ansG.clear();
    sorceboard.clear();
    memset(in,0,sizeof(in));
    inG.clear();
    while (!Q.empty())Q.pop();
}
void solveprintf(int ansnum ,string x,int anstype){
    // ansG the real
    // ansB the ans
    for (int i = 0; i < ansG.size(); i++){
        sorceboard[ansG[i]] = -1;
    }
    sort(ansB.begin(),ansB.end(),cmp);
    for (int i = 0 ; i < ansB.size() && ansnum <3 ; i++){
        if (head[ansB[i]].type == anstype) {
            if (inG.count(ansB[i]) != 0 ) continue;
            if (ansnum == 0) cout <<",";
            else cout <<" ";
            cout <<head[ansB[i]].s;
            ansnum++;
        }
    }
    if (ansnum == 0){
        cout << ",";
        while (1){
            int ggr = rand() % totn + 1;
            if (head[ggr].type == anstype && sorceboard[ggr]>-0.5){
                cout << head[ggr].s;
                break;
            }

        }
    }
    cout << endl;
}
void solve(string x,int anstype){
    solveinit();
    int idx = ID[x];
    Q.push(make_pair(idx,0));
    in[idx] = 1;
    sorceboard[idx] = 100;
    int nowdeep = 0;
    while (nowdeep <= deep && !Q.empty()){
        pair <int,int> now = Q.front();
        nowdeep = now.second;
        int u = now.first;
        Q.pop();
        for (int i = head[u].head;i != -1 ; i = E[i].next){
            int v = E[i].t;
            if (in[v] == 1) continue;
            if (now.second == 0 && head[v].type == anstype && inG.count(v) == 0){
                inG[v] = 1;
                ansG.push_back(v);
            }
            if (sorceboard.count(v) == 0){
                if (head[v].type == anstype) ansB.push_back(v);
                sorceboard[v] = 0;
            }
            sorceboard[v] += sorceboard[u] * E[i].weight;

            if (in[v] == 0){
                Q.push(make_pair(v,nowdeep+1));
                in[v] = 1;
            }
        }
    }
    solveprintf(0,x,anstype);
}
vector<int> ansS;
void solvep_in_f(string x,int anstype){
    int ansnum = 0;
    ansS.clear();
    int idx = ID[x];
    for (int i = head[idx].head ; i != -1 ; i = E[i].next){
        int v = E[i].t;

    }

    in[idx] = 1;
    solveinit();
    sorceboard[idx] = 100;
    int nowdeep = 0;
    while (nowdeep <= deep && !Q.empty()){
        pair <int,int> now = Q.front();
        nowdeep = now.second;
        int u = now.first;
        Q.pop();
        for (int i = head[u].head;i != -1 ; i = E[i].next){
            int v = E[i].t;
            if (in[v] == 1) continue;
            if (now.second == 0 && head[v].type == anstype && inG.count(v) == 0){
                inG[v] = 1;
                ansG.push_back(v);
            }
            if (sorceboard.count(v) == 0){
                if (head[v].type == anstype) ansB.push_back(v);
                sorceboard[v] = 0;
            }
            sorceboard[v] += sorceboard[u] * E[i].weight;
            if (in[v] == 0){
                Q.push(make_pair(v,nowdeep+1));
                in[v] = 1;
            }
        }
    }
    solveprintf(0,x,anstype);
}
void solvepwa(string x,int anstype){
    solveinit();
    int idx = ID[x];
    Q.push(make_pair(idx,0));
    in[idx] = 1;
    sorceboard[idx] = 100;
    int nowdeep = 0;
    while (nowdeep <= deep && !Q.empty()){
        pair <int,int> now = Q.front();
        nowdeep = now.second;
        int u = now.first;
        Q.pop();
        for (int i = head[u].head;i != -1 ; i = E[i].next){
            int v = E[i].t;
            if (in[v] == 1) continue;
            if (head[u].type == 1 && head[v].type == 1) continue;

            if (now.second == 0 && head[v].type == anstype && inG.count(v) == 0){
                inG[v] = 1;
                ansG.push_back(v);
            }
            if (sorceboard.count(v) == 0){
                if (head[v].type == anstype) ansB.push_back(v);
                sorceboard[v] = 0;
            }
            sorceboard[v] += sorceboard[u] * E[i].weight;

            if (in[v] == 0){
                Q.push(make_pair(v,nowdeep+1));
                in[v] = 1;
            }
        }
    }
    solveprintf(0,x,anstype);
}
int main()
{
    freopen("train.csv","r",stdin);
    string s;
    cin >> s;
    int xx = 0;
    while (cin >> s) {
        int i = 0;
        xx++;
        string tmp1 = "" , relat = "", tmp2 = "";
        while (s[i] != ',')
            tmp1 += s[i++];
        i++;
        while (s[i] != ',')
            relat += s[i++];
        i++;
        for (;i < s.length(); i++)
            tmp2 += s[i];
        if (relat == "paper_is_in_field"){
            addedge(tmp1,tmp2,1,3,0.99,0.99);
        }
        else if (relat == "paper_is_written_by"){
            addedge(tmp1,tmp2,1,2,0.99,0.99);
        }
        else if (relat == "paper_publish_on"){
            addedge(tmp1,tmp2,1,5,0.9,0.9);
        }
        else if (relat == "paper_cit_paper"){
            addedge(tmp1,tmp2,1,1,0.9,0.1);
        }
        else if (relat == "work_in"){
            addedge(tmp1,tmp2,2,4,0.9,0.9);
        }
        else if (relat == "author_is_in_field"){
            addedge(tmp1,tmp2,2,3,0.9,0.9);
        }
        else if (relat == "field_is_part_of"){
            addedge(tmp1,tmp2,3,3,0.9,0.9);
        }
        else {
            cout << relat << endl;
        }
    }

    cout << 2 * xx << endl;
    cin.clear();
    fclose(stdin);
    freopen("oldgood.csv","r",stdin);
    int told = 0;
    while (getline(cin,oldstring[told++]));
    cin.clear();
    fclose(stdin);
    freopen("test1.csv","r",stdin);

    string sk;
    cin >> sk;
    int cas = 0;

    freopen("ans.csv","w",stdout);
    cout << "QueryId,ExpectedTail" << endl;
    while (cin >> s) {
        cas++;

        int i = 0;
        string tmp1 = "" , relat = "", ans = "";
        while (s[i] != ',') i++;
        i++;
        while (s[i] != ',')
            tmp1 += s[i++];
        i++;
        for (;i < s.length(); i++)
            relat += s[i];

        if (relat == "paper_is_in_field"){
            //cout << cas ;
            //solve(tmp1,3);
            //solve(tmp1,3);
            cout << oldstring[cas] << endl;
        }
        else if (relat == "paper_is_written_by"){
            cout << cas ;
            solvepwa(tmp1,2);
            //cout << oldstring[cas] << endl;
        }
        else if (relat == "paper_publish_on"){
            //cout << cas ;
            //solve(tmp1,5);
            cout << oldstring[cas] << endl;
        }
        else if (relat == "paper_cit_paper"){
            //cout << cas ;
            //solve(tmp1,1);
            cout << oldstring[cas] << endl;
        }
        else if (relat == "work_in"){
            //cout << cas ;
            //solve(tmp1,4);
            cout << oldstring[cas] << endl;
        }
        else if (relat == "author_is_in_field"){
            //cout << cas ;
            //solve(tmp1,3);
            cout << oldstring[cas] << endl;
        }
        else if (relat == "field_is_part_of"){
            //cout << cas ;
            //solve(tmp1,3);
            cout << oldstring[cas] << endl;
        }
    }
    return 0;
}
