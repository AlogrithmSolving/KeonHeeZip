#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

/**
 *  P.155
 *  6.3 문제 : 소풍 (ID : PICNIC, 난이도 : 하 )
 */

bool isFriend[10][10]; //두 학생이 친구이면 true
int numStd; // 학생의 수
int numFriend; // 친구 쌍의 수

int countCouple(bool hasFriend[10]){


    //남은 학생중 가장 번호가 빠른 학생을 찾는다
    int firstStd = -1;
    for(int i = 0 ; i < numStd ; i++){
        if(!hasFriend[i]){
            firstStd = i;
            break;
        }
    }

    //학생들이 모두 짝을 찾으면 return 1
    if(firstStd == -1){
        return 1;
    }
    int count = 0 ;

    // 번호가 가장빠른 학생의 짝을 찾는다
    for(int partner = firstStd+1 ; partner < numStd ; partner++){
        if (!hasFriend[partner] && isFriend[firstStd][partner]){ // 짝이없고, 친구인 학생과 짝을 맺어준다
            hasFriend[firstStd] = hasFriend[partner] = true;
            count += countCouple(hasFriend);
            hasFriend[firstStd] = hasFriend[partner] = false;
        }
    }
    return count;
}

int main() {

    int numCase; //테스트 케이스 수

    cin >> numCase; //테스트 케이스 수 입력

    for( int i = 0 ; i < numCase ; i++){

        cin >> numStd >> numFriend; // 학생수, 친구쌍의 수 입력
        assert(numStd <= 10);
        memset(isFriend, 0, sizeof(isFriend));

        for ( int j = 0 ; j < numFriend ; j++){
            int f1,f2;
            cin >> f1 >> f2;
            assert(0 <= f1 && f1 < numStd && 0 <= f2 && f2 < numStd);
            assert(!isFriend[f1][f2]);
            isFriend[f1][f2] = isFriend[f2][f1] = true;
        }

        bool hasFriend[10]; // 짝이 이루어졌으면 true
        memset(hasFriend, 0, sizeof(hasFriend));
        cout << countCouple(hasFriend) << endl;

    }
    return 0;
}


