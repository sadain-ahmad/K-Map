#include <iostream>
#include <math.h>
#include <climits>
#include <vector>
#include <string>
using namespace std;

vector<int> variableCount(int count){
    int n,m;
    if(count==2){
        n=m=2;
    }
    else if(count==3){
        n=2;
        m=4;
    }
    else if(count==4){
        n=m=4;
    }
    else if(count==5){
        n=4;
        m=8;
    }
    else{
        cout<<"NO of variable must between 2 to 5 :"<<endl;
        exit(1);
    }
    return {n,m};
}
int getRow(int i){
    return i^(i>>1);
}
 int getColumn(int j){
    return j^(j>>1);
 }
int main(){
    int no;
    cout<<"enter no of variable : ";
    cin>>no;
    vector<int> v = variableCount(no);
    int n=v[0],m=v[1];

    vector<vector<int>> array(n,vector<int> (m,0));
    int a = 0;
    for (int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            int row = getRow(j);
            int col = getColumn(k);
            array[row][col]=a;
            a++;
        }
    }

    int no_min;
    cout<<"Enter The number of ON bits : ";
    cin>>no_min;
    vector<int> minTerm(no_min);
    for(int i=0; i<no_min; i++){
        cout<<"Enter the location of "<<i+1<<" ON Bit ( 0-"<<(pow(2,no)-1)<<" ) : ";
        cin>>minTerm[i];
        if(minTerm[i]>(pow(2,no)-1) || minTerm[i]<0){
            cout<<"input must be 0-"<<(pow(2,no)-1)<<endl;
            exit(1);
        }
    }
    cout<<endl;

    // Turn ON the given Bits :
    bool flag=false;
    for(int i=0;i<no_min;i++){
        int temp = minTerm[i];  
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(array[j][k]==temp){
                    array[j][k]=1;
                }

                if(temp==1){
                    flag=true;
                }
            }
        }
    }
    if(flag==true){
        array[0][1]=1;
    }
    else{
        array[0][1]=0;
    }

    // Mark all the element '0' that are not equal to 1
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(array[j][k]!=1){
                array[j][k]=0;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    bool x=false;
    cout << "K-map expression : ";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(array[i][j]==1){
                if(x==true){
                    cout<<" + ";
                }
                if(no==2){

                    if(i==0) cout<<"A'";
                    else cout<<"A";

                    if(j==0) cout<<"B'";
                    else cout<<"B";
                }
                else if(no==3){

                    if (i == 0) cout << "A'";
                    else cout << "A";

                    if (j == 0) cout << "B'C'";
                    else if (j == 1) cout << "B'C";
                    else if (j == 2) cout << "BC";
                    else if (j == 3) cout << "BC'";
                }
                else if(no==4){

                    if(i==0) cout<<"A'B'";
                    else if(i==1) cout<<"A'B";
                    else if(i==2) cout<<"AB";
                    else if(i==3) cout<<"AB'";

                    if (j == 0) cout << "B'C'";
                    else if (j == 1) cout << "B'C";
                    else if (j == 2) cout << "BC";
                    else if (j == 3) cout << "BC'";
                }
                else if(no == 5){
                    if(i==0) cout<<"A'B'";
                    else if (i == 1) cout << "A'B";
                    else if (i == 2) cout << "AB";
                    else if (i == 3) cout << "AB'";

                    if (j == 0) cout << "C'D'E'";
                    else if (j == 1) cout << "C'D'E";
                    else if (j == 2) cout << "C'DE";
                    else if (j == 3) cout << "C'DE'";
                    else if (j == 4) cout << "CDE'";
                    else if (j == 5) cout << "CDE";
                    else if (j == 6) cout << "CD'E";
                    else if (j == 7) cout << "CD'E'";                    
                }
                x=true;
            }
        }
    }
    return 0;
}