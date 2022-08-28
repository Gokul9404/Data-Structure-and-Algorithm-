#include <iostream>
using namespace std;

int main(){
    int ary[5] = {1,2,3,4,5};
    cout<<"By basic method\n"<<ary[0]<<endl;
    cout<<ary[1]<<endl;
    cout<<ary[2]<<endl;
    cout<<ary[3]<<endl;
    cout<<ary[4]<<endl<<"Now by pointers\n";
    cout<<*(ary)<<endl;
    cout<<*(ary+1)<<endl;
    cout<<*(ary+2)<<endl;
    cout<<*(ary+3)<<endl;
    cout<<*(ary+4)<<endl;
    return 0;
}