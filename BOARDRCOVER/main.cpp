#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;



bool board[20][20];
int h,v;
int countWhite;

bool drawBoard(const char c){
    assert(c == '#' || c=='.');
    if (c == '#' ){
        return false;
    } else {
        return true;
    }
}

int countCover(bool copyBoard[20][20]){
//    cout << endl;
//    for (int k = 0; k < 20; k++) {
//        for (int i = 0; i < 20; i++) {
//            cout << copyBoard[k][i]<<" ";
//        }
//            cout << endl;
//    }
    //맨 왼쪽끝에있는 흰점을 찾는다
    int x=-1, y=-1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(copyBoard[i][j]){
                x = i;
                y = j;
                goto outside;  //lol !!!
            }
        }

    }
    outside:

    // 모든 점이 false
    if (x==-1 && y==-1){
        return 1;
    }

    int count = 0;

    if (copyBoard[x][y-1] && copyBoard[x+1][y-1]){
            copyBoard[x][y] = copyBoard[x][y-1] = copyBoard[x+1][y-1] = false;
            count += countCover(copyBoard);
            copyBoard[x][y] = copyBoard[x][y-1] = copyBoard[x+1][y-1] = true;
    }
    if (copyBoard[x+1][y] && copyBoard[x+1][y-1]) {
            copyBoard[x][y] = copyBoard[x+1][y] = copyBoard[x+1][y-1] = false;
            count += countCover(copyBoard);
            copyBoard[x][y] = copyBoard[x+1][y] = copyBoard[x+1][y-1] = true;
    }
    if (copyBoard[x+1][y] && copyBoard[x+1][y+1]){
            copyBoard[x][y] = copyBoard[x+1][y] = copyBoard[x+1][y+1] = false;
            count += countCover(copyBoard);
            copyBoard[x][y] = copyBoard[x+1][y] = copyBoard[x+1][y+1] = true;
        }
    if (copyBoard[x][y+1] && copyBoard[x+1][y+1]) {
            copyBoard[x][y] = copyBoard[x][y+1] = copyBoard[x+1][y+1] = false;
            count += countCover(copyBoard);
            copyBoard[x][y] = copyBoard[x][y+1] = copyBoard[x+1][y+1] = true;
        }
    if (copyBoard[x][y-1] && copyBoard[x+1][y]) {
            copyBoard[x][y] = copyBoard[x][y-1] = copyBoard[x+1][y] = false;
            count += countCover(copyBoard);
            copyBoard[x][y] = copyBoard[x][y-1] = copyBoard[x+1][y] = true;
        }
    if (copyBoard[x][y+1] && copyBoard[x+1][y]){
            copyBoard[x][y] = copyBoard[x][y+1] = copyBoard[x+1][y] = false;
            count += countCover(copyBoard);
            copyBoard[x][y] = copyBoard[x][y+1] = copyBoard[x+1][y] = true;
        }

    return count;
}


int main() {


    int numCase;

    cin >> numCase;
    assert(numCase <= 30);
    while(numCase--){

        cin >> h >> v;
        assert(1<=h && h<=20 && 1<=v && v<=20);
        memset(board,0, sizeof(board));

        string row;
        countWhite = 0;
        for(int i = 0 ; i < h ; i++){
            cin >> row;
            //assert(strlen(row) <= v);
            for(int j = 0 ; j < v ; j++){
                board[i][j] = drawBoard(row[j]);
                if (board[i][j]){
                    countWhite++;
                }
            }
        }


        bool copyBoard[20][20];
        memcpy(copyBoard,board, sizeof(copyBoard));

//        for (int k = 0; k < 20; ++k) {
//            for (int i = 0; i < 20; ++i) {
//                cout << copyBoard[k][i]<<" ";
//            }
//            cout << endl;
//        }

        assert(countWhite <= 50);
        //bool taken[countWhite];

        if(countWhite%3 != 0){
            cout << 0 << endl;
        }else{
            cout<<countCover(copyBoard)<<endl;
        }

    }


    return 0;
}