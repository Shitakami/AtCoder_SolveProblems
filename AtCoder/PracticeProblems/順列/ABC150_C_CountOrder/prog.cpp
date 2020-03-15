#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


int n;
int count = 1;
map<vector<int>, int> permutationMap;

void MakePermutation(int index, set<int> usedNumber, vector<int> permutation) {

    if(index == n) {
        permutationMap.emplace(permutation, count++);
        /*
        for(int i = 0; i < n; i++)
            cout << permutation[i] << " ";
        cout << endl;
        */

        return;
    }


    for(int i = 1; i <= n; ++i) {
        if(usedNumber.find(i) != usedNumber.end())
            continue;

        usedNumber.insert(i);
        permutation[index] = i;
        MakePermutation(index + 1, usedNumber, permutation);
        usedNumber.erase(i);
    }

}



int main() {


    cin >> n;

    set<int> usedNumber;
    vector<int> permutation(n);

    vector<int> p1, p2;

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        p1.push_back(a);
    }

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        p2.push_back(a);
    }

    MakePermutation(0, usedNumber, permutation);

  //  cout << endl;
    cout << abs(permutationMap[p1] - permutationMap[p2]) << endl;

    return 0;

}

