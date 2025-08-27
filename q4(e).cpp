#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter a uppercase character: ";
    cin>>ch;
    if(ch>='A'&&ch<='Z')ch=ch+32;
    cout<<"Lowercase character: "<<ch;
    return 0;
}
