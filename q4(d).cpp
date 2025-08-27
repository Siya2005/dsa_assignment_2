#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of strings: ";
    cin>>n;
    cin.ignore();
    string str[50];
    cout<<"Enter "<<n<<" strings:\n";
    for(int i=0;i<n;i++)getline(cin,str[i]);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(str[j]>str[j+1]){
                string temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
    cout<<"\nStrings in alphabetical order:\n";
    for(int i=0;i<n;i++)cout<<str[i]<<" ";
    return 0;
}
