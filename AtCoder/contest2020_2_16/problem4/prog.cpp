#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    vector<long long int> numbers;

    vector<long long int> minusNum;
    vector<long long int> plusNum;

    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if(num < 0)
            minusNum.push_back(num);
        else
        {
            plusNum.push_back(num);
        }
        
        
    }

    sort(minusNum.begin(), minusNum.end());
    sort(plusNum.begin(), plusNum.end());

    int count = minusNum.size() * plusNum.size();


    if(minusNum.size() * plusNum.size() >= k) {

        count = 0;
        int index = 0;
        for(index = 0; index < minusNum.size() && count + plusNum.size() < k; ++index) {
            count += plusNum.size();
        }

        cout << minusNum[index] * plusNum[k - count] << endl;

        return 0; 
    }
    else {

        for(int i = 0; i < minusNum.size(); ++i) {
            minusNum[i] *= -1;
            plusNum.push_back(minusNum);
        }

        sort(plusNum.begin(), plusNum.end());

        int index = 1;
        count = 0;
        while(count + plusNum.size() - index < k) {
            count += plusNum.size() - index;
            index++;
        }

        cout << plusNum[index - 1] * plusNum[]

        

    }



    return 0;

}