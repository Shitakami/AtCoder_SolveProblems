#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

    map<int, int> problems;
    int n;
    int m;
    int wrongCount = 0;
    int acceptCount = 0;

    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int problem;
        string result;
        
        cin >> problem >> result;

        if(result == "AC") {
            if(problems.find(problem) != problems.end() && problems[problem] != -1)
                wrongCount += problems[problem];

            if(problems[problem] != -1)
                acceptCount++;

            problems[problem] = -1;
        
        }
        else {
            
            if(problems.find(problem) == problems.end())
                problems[problem] = 0;

            if(problems[problem] != -1)
                problems[problem]++;
        }

    }

    cout << acceptCount << " " << wrongCount;

    return 0;

}