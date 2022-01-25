#include <vector>
#include <iostream>

#define MAX_SIZE 3000

using namespace std;

int not_prime_nums[MAX_SIZE + 5] = { 0,1,0, };

void isPrime() {

	// 2부터 MAX_SIZE까지 수의 소수 판별
	for (int p = 2; p <= MAX_SIZE; p++) {

		if (not_prime_nums[p] == 0) { // 소수인 경우

			// 소수의 배수는 소수가 아니기때문에 false처리
			for (int i = 2; p*i <= MAX_SIZE; i++)
				not_prime_nums[p*i] = 1;
		}
	
	}
}

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();
    isPrime();
    
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                int sum = nums[i] + nums[j] + nums[k];
                if (not_prime_nums[sum] == 0) answer++;
            }
        }
    }

    return answer;
}