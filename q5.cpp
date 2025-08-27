#include<iostream>
using namespace std;

void diagonalMatrix(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)cout<<a[i]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}

void tridiagonalMatrix(){
    int n;
    cin>>n;
    int a[3*n-2];
    for(int i=0;i<3*n-2;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j==1)cout<<a[i-1]<<" ";
            else if(i==j)cout<<a[n-1+i]<<" ";
            else if(j-i==1)cout<<a[2*n-1+i]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}

void lowerTriangular(){
    int n;
    cin>>n;
    int a[n*(n+1)/2];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)cin>>a[k++];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j)cout<<a[i*(i+1)/2+j]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}

void upperTriangular(){
    int n;
    cin>>n;
    int a[n*(n+1)/2];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)cin>>a[k++];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j)cout<<a[i*n-(i*(i-1))/2+j-i]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}

void symmetricMatrix(){
    int n;
    cin>>n;
    int a[n*(n+1)/2];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)cin>>a[i*(i+1)/2+j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j)cout<<a[i*(i+1)/2+j]<<" ";
            else cout<<a[j*(j+1)/2+i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int choice;
    cout<<"1.Diagonal\n2.Tri-diagonal\n3.Lower Triangular\n4.Upper Triangular\n5.Symmetric\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:diagonalMatrix();break;
        case 2:tridiagonalMatrix();break;
        case 3:lowerTriangular();break;
        case 4:upperTriangular();break;
        case 5:symmetricMatrix();break;
        default:cout<<"Invalid choice";
    }
    return 0;
}
