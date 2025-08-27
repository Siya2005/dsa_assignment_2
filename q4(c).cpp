#include<iostream>
using namespace std;
bool isVowel(char c){
    if(c>='A'&&c<='Z')c=c+('a'-'A');
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
    else return false;
}
int main(){
    char str[100];
    cout<<"Enter a string: ";
    cin.getline(str,100);
    int k=0;
    for(int i=0;str[i]!='\0';i++){
        if(!isVowel(str[i])){
            str[k]=str[i];
            k++;
        }
    }
    str[k]='\0';
    cout<<"String without vowels: "<<str<<endl;
    return 0;
}
