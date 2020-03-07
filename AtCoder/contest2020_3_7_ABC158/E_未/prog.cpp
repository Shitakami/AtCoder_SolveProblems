#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX = 2 * 1e+5;

int main() {

    int n, p;
    
    cin >> n >> p;

    string number;

    cin >> number;

    int index = 1;
    int num = p;

    vector<string> canDiv;
    long long mx = atoi(number.c_str());
    while(num <= mx) {

        canDiv.push_back(to_string(num));
        index++;
        num = p * index;
    }

    int count = 0;
    for(int i = 0; i < canDiv.size(); ++i) {
        
       // cout << canDiv[i] << endl;
        
        int j, num_i = 0;
        for(j = 0; j < canDiv[i].size() && num_i < number.size(); j++) {
            
            while(num_i < number.size()) {
                
                
                if(canDiv[i][j] == number[num_i++]) {
                    
                    if(j == canDiv[i].size() - 1) {
                        count++;
                     //   cout << canDiv[i] << endl;
                    }
                    
                    break;
                }
                
            }


        }

    }

    cout << count << endl;

    return 0;
}