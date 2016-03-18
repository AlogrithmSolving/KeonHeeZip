#include <iostream>

using namespace std;

/**
 *  6.3 문제 : 소풍 (ID : PICNIC, 난이도 : 하 )
 *
 */


int countCouple(bool isFriend[][10], bool hasFriend[10], int std);
int main() {


    int numberOfCount = 0;


    bool isFriend[10][10] = {false};
    bool hasFriend[10] = {false};

    int std = 0 ;
    int numFriend = 0 ;
    int f1, f2;



    cin >> numberOfCount;
    for( int i = 0 ; i < numberOfCount ; i++){

        cin >> std >> numFriend;
        for ( int j = 0 ; j < numFriend ; j++){
            cin >> f1 >> f2;
            isFriend[f1][f2]=isFriend[f2][f1] = true;
        }

        cout << countCouple(isFriend,hasFriend,std) << endl;

    }
    return 0;
}

int countCouple(bool isFriend[][10],bool hasFriend[10], int std){

    int firstStd = -1;
    for(int i = 0 ; i < std ; i++){
        if(!hasFriend[i]){
            firstStd = i;
            break;
        }
    }

    if(firstStd == -1){
        return 1;
    }
    int count = 0 ;

    for(int partner = firstStd+1 ; partner < std ; partner++){
        if (!hasFriend[partner] && isFriend[firstStd][partner] == true){
            hasFriend[firstStd] = hasFriend[partner] = true;
            count += countCouple(isFriend,hasFriend, std);
            hasFriend[firstStd] = hasFriend[partner] = false;
        }
    }
    return count ;
}