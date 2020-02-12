#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int SumNumber(int n) {

    return (1 + n) * n / 2;

}

int main() {

    int n;
    int k;
    vector<int> numbers;
    
    int max_sum = 0;
    int max_index = 0;

    int now_sum = 0;

    cin >> n >> k;

    max_index = k - 1;

    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        numbers.push_back(num);

        if(i < k) {
            max_sum += num;
            now_sum += num;
        } 
        else {
            now_sum += num;
            now_sum -= numbers[i - k];


            if(now_sum > max_sum) {
                max_sum = now_sum;
                max_index = i;


            }

        }

    }


    double answer = 0;

    for(int i = max_index; i > max_index - k; i--) {
        answer += (double)SumNumber(numbers[i]) / (double)numbers[i];
    }

    // cout << answer << endl;
    printf("%.10f\n", answer);

    return 0;

}