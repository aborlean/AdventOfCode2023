#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("data1.in");

int n, m, sum;
char ch[1000][1000];
bool vis[1000][1000];
char s[1000];
vector<pair<int, int>> v;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool inside(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m;
}

void find_number(int x, int y) {
    while(isdigit(ch[x][y - 1]))
        y--;

    int num = 0;

    while(isdigit(ch[x][y])) {
        vis[x][y] = true;
        num *= 10;
        num += ch[x][y] - '0';
        y++;
    }

    sum += num;
}

void process(pair<int, int> p) {
    for(int k = 0; k < 8; k++) {
        int new_x = p.first + dx[k];
        int new_y = p.second + dy[k];
        if(isdigit(ch[new_x][new_y]) && inside(new_x, new_y) && !vis[new_x][new_y])
            find_number(new_x, new_y);
    }
}

int main(void)
{
    while(!fin.eof()) {
        n++;
        fin.getline(s, 1000);
        if(n == 1)
            m = strlen(s);

        for(int i = 1; i <= strlen(s); i++) {
            ch[n][i] = s[i - 1];
            if(!isdigit(s[i - 1]) && s[i - 1] != '.')
                v.push_back({n, i});
        }
    }

    for(pair<int, int> p : v)
        process(p);

    cout << sum;

    return 0;
}