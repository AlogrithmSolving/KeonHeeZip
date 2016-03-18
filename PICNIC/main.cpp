#include <iostream>

using namespace std;

/**
 *  P.155
 *  6.3 문제 : 소풍 (ID : PICNIC, 난이도 : 하 )
 */


int countCouple(bool isFriend[][10], bool hasFriend[10], int std);
int main() {


    int numberOfCount = 0; //테스트 케이스 수


    bool isFriend[10][10] = {false}; //두 학생이 친구이면 true
    bool hasFriend[10] = {false}; // 짝이 이루어졌으면 true

    int std = 0 ; // 학생의 수
    int numFriend = 0 ; // 친구 쌍의 수
    int f1, f2;



    cin >> numberOfCount; //테스트 케이스 수 입력
    for( int i = 0 ; i < numberOfCount ; i++){

        cin >> std >> numFriend; // 학생수, 친구쌍의 수 입력
        for ( int j = 0 ; j < numFriend ; j++){
            cin >> f1 >> f2;
            isFriend[f1][f2]=isFriend[f2][f1] = true;
        }

        cout << countCouple(isFriend,hasFriend,std) << endl;

    }
    return 0;
}

int countCouple(bool isFriend[][10],bool hasFriend[10], int std){


    //남은 학생중 가장 번호가 빠른 학생을 찾는다
    int firstStd = -1;
    for(int i = 0 ; i < std ; i++){
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
    for(int partner = firstStd+1 ; partner < std ; partner++){
        if (!hasFriend[partner] && isFriend[firstStd][partner] == true){ // 짝이없고, 친구인 학생과 짝을 맺어준다
            hasFriend[firstStd] = hasFriend[partner] = true;
            count += countCouple(isFriend,hasFriend, std);
            hasFriend[firstStd] = hasFriend[partner] = false;
        }
    }
    return count ;
}