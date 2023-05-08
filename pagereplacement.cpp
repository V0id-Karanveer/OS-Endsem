#include <bits/stdc++.h>
using namespace std;

bool found(int ele,int arr[20],int n){
    for(int i=0;i<n;i++){
        if(ele==arr[i]){
            return true;
        }
    }
    return false;
}

void fifo(int seq[20], int m , int n){
    int frame[20];
    for(int i=0;i<m;i++){
        frame[i] = -1;
    }
    int hit=0;
    int mat[20][20];
    int index = 0;
    for(int i=0;i<n;i++){
        if(found(seq[i],frame,m)){
            hit++;
        }
        else{
            index = index%m;
            frame[index] = seq[i];
            index++;
        }
        for(int j=0;j<m;j++){
            mat[i][j] = frame[j];
        }
        
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[j][i]<<"\t";
        }
        cout<<endl;
        
    }

    cout << "No. of hits " << endl;
}

int optrep(int seq[20],int frame[20],int m,int n,int k){
    int count[20];
    int flag[20];
    for(int i=0;i<m;i++){
        count[i]=0;
        flag[i]=0;
    }
    int largest = 0;
    
    for(int i=0;i<m;i++){
        for(int j=k;j<n;j++){
            count[i]++;
            if(seq[j]==frame[i]){
                flag[i]=1;
                break;
            }
        }
    }
    int index = 0;
    for(int i=0;i<m;i++){
        if(count[i]>largest){
            largest = count[i];
            index = i;
        }
    }
    for(int i=0;i<m;i++){
        if(flag[i]==0){
            return i;
        }
    } 

    
    return index;
    
    
}

void optimal(int seq[20],int m,int n){
    int mat[20][20];
    int frame[20];
    int index;
    for(int i=0;i<n;i++){
        frame[i] = -1;
    }
    int hit=0;
    for(int i=0;i<n;i++){
        if(i<m){
            frame[i] = seq[i];
        }
        else if(found(seq[i],frame,m)){
            hit++;
        }
        else{
            index = optrep(seq,frame,m,n,i);
            frame[index] = seq[i];
        }
        for(int k=0;k<n;k++){
            mat[i][k] = frame[k];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << mat[j][i]<< "\t";
        }
        cout<<endl;
    }
}

int lrurep(int seq[20],int frame[20],int m,int n, int k){
    int count[10];
    int index;
    for(int i=0;i<m;i++){
        count[i] = 0;
    }
    for(int i=0;i<m;i++){
        for(int j=(k-1);j>=0;j--){
            count[i]++;
            if(frame[i]==seq[j]){
                break;
            }
        }
    }

    int large=-1;
    for(int i=0;i<m;i++){
        if(count[i]>large){
            large = count[i];
            index = i;
        }
    }
    return index;
}

void lru(int seq[20],int m,int n){
    int mat[20][20];
    int frame[20];
    for(int i=0;i<m;i++){
        frame[i]= -1;
    }
    int index;
    int hit=0;
    for(int i=0;i<n;i++){
        if(i<m){
            frame[i] = seq[i];
        }
        else if(found(seq[i],frame,n)){
            hit++;
        }
        else{
            index = lrurep(seq,frame,m,n,i);
            frame[index]=seq[i];
        }
        for(int j=0;j<m;j++){
            mat[i][j] = frame[j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<< mat[j][i] << "\t";
        }
        cout << endl;
    }
}

int main(){
    
    int process[20] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    lru(process,3,20);
}
