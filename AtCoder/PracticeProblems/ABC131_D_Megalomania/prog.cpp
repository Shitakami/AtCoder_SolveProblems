#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Work {
    int time;
    int deadLine;

    bool operator < (const Work &a) {

        if(deadLine == a.deadLine) 
            return time < a.time;
        
        return deadLine < a.deadLine;

    }

};

int main() {

    int n;
    cin >> n;

    vector<Work> w(n);

    for(int i = 0; i < n; ++i)
        cin >> w[i].time >> w[i].deadLine;

    sort(w.begin(), w.end());

    int time = 0;
    int i;
    for(i = 0; i < n; ++i) {

        time += w[i].time;
        if(time > w[i].deadLine)
            break;

    }

    if(i == n)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    

    return 0;

}