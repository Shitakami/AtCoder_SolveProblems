#include <stdio.h>

int SumNumber(int n) {

    return (1 + n) * n / 2;

}

int numbers[200000 + 30];

int main() {

    int n;
    int k;
    
    int max_sum = 0;
    int max_index = 0;

    int now_sum = 0;

    scanf("%d %d", &n, &k);


    max_index = k - 1;

    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);

        numbers[i] = num;

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

    printf("%f\n", answer);

}