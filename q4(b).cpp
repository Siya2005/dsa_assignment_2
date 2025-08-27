#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str[100];
    cout<<"Enter a string: ";
    cin.getline(str,100);
    int len=strlen(str);
    for(int i=0,j=len-1;i<j;i++,j--){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    cout<<"Reversed String: "<<str;
    return 0;
}
