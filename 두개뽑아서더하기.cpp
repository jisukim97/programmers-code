#include <stdio.h>
#include <vector>
#include <queue>

/*
 월간 코드 챌린지 시즌1: 두개 뽑아서 더하기
정수 배열 numbers가 주어지면 서로 다른 인덱스에 있는 두 개의 수를 뽑아
더해서 만들 수 있는 모든 가능한 수를 오름차순으로 담아 return하는 함수를 만드세요.
*/ 

using namespace std;

vector<int> solution(vector<int> numbers) {
    priority_queue<int, vector<int>, less<int> > pq;
    vector<int> answer;
    int cnt = numbers.size();
    int total_cnt = (cnt*(cnt-1))/2;
    
    for(int i=0; i<cnt;i++)
        for(int j=i+1; j<cnt;j++)
            pq.push(numbers[i]+numbers[j]);
    
    int max = pq.top();
    pq.pop();
    for(int i=0; i<total_cnt; i++){
        if(max==pq.top()) {
            pq.pop();
            continue;
        }
        answer.insert(answer.begin(),max);
        max = pq.top();
        pq.pop();
    }
    answer.insert(answer.begin(),max);
    return answer;
}