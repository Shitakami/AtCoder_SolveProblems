#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;

    cin >> s;

    string dream = "dream", erase = "erase";

    int index = 0;

    if(s.size() < 5) {
        cout << "NO" << endl;
        return 0;
    }

    while(1) {
        
        string subS = s.substr(index, 5);
       // cout << "subS = " << subS << endl;

        if(subS == dream) {
            
            index += 5;
            if(index == s.size()) {
                break;
            }
            else if(index + 2 > s.size()) {
                cout << "NO" << endl;
                return 0;
            }
            else if(index + 2 == s.size()) {
                if("er" == s.substr(index, 2))
                    break;
                else {
                    cout << "NO" << endl;
                    return 0;
                }
            }

            string er_ = s.substr(index, 3);

            if(er_ == "era" || er_ == "dre")
                continue;
            else if(er_ == "erd" || er_ == "ere") {
                index += 2;
                continue;
            }
            
            cout << "NO" << endl;
            return 0;

        }
        else if(subS == erase) {

            index += 5;
            
            if(index == s.size()) {
                break;
            }
            else if(index + 1 == s.size()) {
                if("r" == s.substr(index, 1))
                    break;
                else {
                    cout << "NO" << endl;
                    return 0;
                }
            }

            string r_ = s.substr(index, 2);

            if(r_ == "dr" || r_ == "er") {
                continue;
            }
            else if(r_ == "re" || r_ == "rd") {
                index++;
                continue;
            }

            cout << "NO" << endl;
            return 0;


        }
        else {
            cout << "NO" << endl;
            return 0;
        }

    }


    cout << "YES" << endl;

    return 0;


}