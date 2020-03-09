#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {

    string s;
    bool isInverse = false;

    cin >> s;

    list<char> s_link;

    for(int i = 0; i < s.size(); ++i)
        s_link.emplace_back(s[i]);

    int q;


    cin >> q;

    for(int i = 0; i < q; ++i) {

        int c;
        cin >> c;

        switch (c)
        {
        case 1:

            isInverse = !isInverse;
            break;
        
        case 2:

            int f;
            char ch;
            cin >> f >> ch;

            if( (!isInverse && f == 1) || (isInverse && f == 2))
                s_link.emplace_front(ch);
            else
                s_link.emplace_back(ch);

            break;
        
        }
    }


    if(isInverse) {

        for(auto itr = s_link.rbegin(); itr != s_link.rend(); itr++)
            cout << *itr;
        
    }
    else {
        for(auto itr = s_link.begin(); itr != s_link.end(); itr++)
            cout << *itr;
    }
    
    cout << endl;

    return 0;


}