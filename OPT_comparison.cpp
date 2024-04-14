#include <iostream>
using namespace std;
#define N 10

double table[N][N]; //테이블 값을 저장할 배열
int key[N][N];
double p(int a,int b){
    double p[N]={0.08,0.12,0.05,0.15,0.2,0.05,0.05,0.1,0.1,0.1}; //원소는 4개
    double sum=0;

    for(int i=a; i<b+1; i++){
        sum+=p[i];
    } //지정된 공간 만큼만 더해서 리턴
    return sum;
}

double opt(int a, int b){
    double result;
    if(a>b) return 0;
    for(int i=a; i<b+1; i++){
        result=(1+(p(a,i-1)/p(a,b)*opt(a,i-1))+(p(i+1,b)/p(a,b)*opt(i+1,b)));
        if (i==a){
            table[a][b]=result;
            key[a][b]=i+1;
        }
        else if(table[a][b]>result){
            table[a][b]=result;
            key[a][b]=i+1;
        }
    }
    return table[a][b];
}

int main() {
    cout.precision(2);
    cout.setf(ios::fixed);
    opt(0,N-1);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (table[i][j]==0){
                cout << ' ' << ' '<< ' '<< ' '<< ' ';
            }
            else{
            cout << table[i][j] << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(key[i][j]==0){
                cout << ' ' << ' ';
            }
            else{
                cout << key[i][j] << ' ';
            }
        }
        cout << endl;
    }
}
