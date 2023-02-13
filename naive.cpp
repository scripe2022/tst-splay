#include <iostream>
#include <set>

using namespace std;

set<string> f;

int main() {
    int n;
    cin >> n;
    for (; n--; ) {
        string o, s;
        cin >> o >> s;
        if (o[0] == 'I') f.insert(s);
        else if (o[0] == 'Q') cout << ((f.find(s) == f.end()) ? 0 : 1) << endl;
    }

    return 0;
}