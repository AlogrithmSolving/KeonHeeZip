#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

unsigned int preSub[12];
unsigned int semester[10];


int countNeedSemester(int n, int k, int m, int l ){
    int ret = 0; //최소 학기 수
    int finish = 0; //수강한 과목
    int totalCount = 0; //총 수강한 과목 수


    // 0번째 학기부터 반복
    for (int j = 0; j < m; ++j) {
        int count = 0; // 한학기에 수강한 과목 수

        if(finish == (1<<n)-1){
            break;
        }

        // 0번째 과목부터 반복
        for (int i = 0; i < n; ++i) {

            // i번째 과목 수강 or j번째 학기에 개설x -> PASS
            if (finish & (1<<i) || !(semester[j] & (1<<i))){
                continue;
            }

            //이번학기에 들은 과목이 l을 초과
            if(count > l){
                break;
            }

            //선수과목x
            if (!preSub[i]){
                finish |= (1<<i); //i번쨰 과목 수강
                count++;
                totalCount++;

                //j번째 학기에 들은 과목 선수과목에서 제외
                for (int i1 = 0; i1 < n; ++i1) {
                    preSub[i1] &= ~(1<<i);

                }

            }

        }
//
//        //j번째 학기에 들은 과목 선수과목에서 제외
//        for (int i1 = 0; i1 < n; ++i1) {
//            for (int i = 0; i < n; ++i) {
//                if(finish & (1<<i)){
//                    preSub[i1] &= ~(1<<i);
//                }
//            }
//        }

        // j번째 학기에 과목을 수강할때
        if(count){
            ret++;
        }

        //
        if (totalCount == k ){
            return ret;
        }
    }

    if(finish != (1<<n)-1){
        return -1;
    }
    if(totalCount < k){
        return -1;
    }
    if(ret > m ){
        return -1;
    }
    //종료처리....

    return ret;
}

int main() {

    int numCase;
    cin >> numCase;
    assert(numCase<=50);

    while(numCase--){
        int n,k,m,l;
        cin >> n >> k >> m >> l;
        assert(1<=n && n<=12);
        assert(1<=k && k<=n);
        assert(1<=m && m<=10);
        assert(1<=l && l<=10);

        memset(preSub,0, sizeof(preSub));
        memset(semester,0, sizeof(semester));

        //선수 과목 정보 입력
        for (int i = 0; i < n; ++i) {

            int r;
            cin >> r;
            for (int j = 0; j < r; ++j) {
                int z;
                cin >> z;
                preSub[i] |= (1 << z);
            }
        }
//        //디버깅
//        for (int i1 = 0; i1 < n; ++i1) {
//            cout << preSub[i1] << " ";
//
//        }
        // 학기당 개설 과목 입력
        for (int j = 0; j < m; ++j) {

            int r;
            cin >> r;
            for (int i = 0; i < r; ++i) {
                int z;
                cin >> z;
                semester[j] |= (1<<z);
            }
        }

        int result = countNeedSemester(n,k,m,l);
        if (result == -1){
            cout << "IMPOSSIBLE"<< endl;
        }else{
            cout << result << endl;
        }


    }




    return 0;
}