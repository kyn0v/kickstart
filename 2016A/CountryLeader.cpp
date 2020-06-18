#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getLeader(vector<string> &all_name) {
    string leader = "";
    int maxCnt = 0;
    for (int i = 0; i < all_name.size(); i++) {
        int count[26] = {0};
        int uniqueCnt = 0;
        for (int j = 0; j < all_name[i].size(); j++) {
            char temp = all_name[i][j];
            if (temp != ' ') {
                count[temp - 'A']++;
            }
        }
        for (int &i : count) {
            if (i) {
                uniqueCnt++;
            }
        }
        if (uniqueCnt > maxCnt) {
            leader = all_name[i];
            maxCnt = uniqueCnt;
        } else if (uniqueCnt == maxCnt) {
            leader = leader.compare(all_name[i]) > 0 ? all_name[i] : leader;
        }
    }
    return leader;
}

int main() {
    int T, N;
    vector<string> all_name;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        all_name.clear();
        string name;
        cin.ignore(1);
        for (int j = 0; j < N; j++) {
            getline(cin, name);
            all_name.push_back(name);
        }
        cout << "Case #" << i + 1 << ": " << getLeader(all_name) << endl;
    }
    return 0;
}