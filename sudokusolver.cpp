#include<bits/stdc++.h>
using namespace std;
bool grid(int arr[][9],int row,int col,int n){
    row=row-row%3;
    col=col-col%3;
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            if(arr[row+r][col+c]==n){
                return false;
            }
        }
    }
    return true;
}
bool rowcheck(int arr[][9],int r,int n){
    for(int col=0;col<9;col++){
        if(arr[r][col]==n){
            return false;
        }
    }
    return true;
}
bool columncheck(int arr[][9],int col,int n){
    for(int r=0;r<9;r++){
        if(arr[r][col]==n){
            return false;
        }
    }
    return true;
}
void display(int arr[][9]){
    cout<<"The result:"<<endl;
    for(int p=0;p<9;p++){
        for(int q=0;q<9;q++){
            cout<<arr[p][q]<<" ";
        }
        cout<<endl;
    }
}
bool sudokusolve(int arr[][9],int r,int c){
    if(r>8){
        display(arr);
        return true;
    }
    if(arr[r][c]==0){
        int num;
        for( num=1;num<=9;num++){
            if(rowcheck(arr,r,num) && columncheck(arr,c,num) && grid(arr,r,c,num)){
                arr[r][c]=num;
                bool a;
                if(c<8){
                    a=sudokusolve(arr,r,c+1);
                }
                else{
                    a=sudokusolve(arr,r+1,0);
                }
                if(a){
                    return true;
                }
                arr[r][c]=0;  //backtracking
            }
        }
        return false;
    }
    else{
        if(c<8){
            return sudokusolve(arr,r,c+1);
        }
        else{
            return sudokusolve(arr,r+1,0);
        }
    }
}
int main(){
    int arr[9][9];
    cout<<"Enter the sudoku puzzle , enter 0 for unknown entries:"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }
    sudokusolve(arr,0,0);
    return 0;
}