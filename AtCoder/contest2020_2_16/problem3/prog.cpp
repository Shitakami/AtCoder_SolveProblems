#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {

    int n;
    map<string, int> dictionary;
    int maxCount = 0;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if(dictionary.find(s) == dictionary.end())
            dictionary.emplace(s, 0);
        else {
            dictionary[s]++;

            if(maxCount < dictionary[s])
                maxCount = dictionary[s];

        }

    }

    vector<string> answer;

    for(auto itr = dictionary.cbegin(); itr != dictionary.end(); itr++)
        if(itr->second == maxCount)
            answer.push_back(itr->first);

    sort(answer.begin(), answer.end());

    // cout << endl;

    for(int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;


    return 0;

}