#include <iostream>
using namespace std;

void firstfit(int b[20],int p[20],int n,int m){
    int alloc[10];
    for(int i=0;i<10;i++){
        alloc[i] = -1;
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[j]>=p[i]){
                b[j] = b[j] - p[i];
                alloc[i] = j;
                break;
                
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<(i+1)<<"\t"<<p[i]<<"\t"<<alloc[i]+1<<endl;
    }
    
}

void bestfit(int b[20],int p[20], int n,int m){
    int alloc[20];
    int done[20];
    int small;
    for(int i=0;i<n;i++){
        alloc[i] = -1;
        done[i] = 0;
    }

    for(int i=0;i<n;i++){
        small = -1;
        for(int j=0;j<m;j++){
            if(b[j]>=p[i] && done[j]==0){
                if(small==-1){
                    small = j;
                }
                else if(b[j]<b[small]){
                    small = j;
                }
            }
        }
        if(small!=-1){
            alloc[i] = small;
            done[small] = 1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<(i+1)<<"\t"<<p[i]<<"\t"<<alloc[i]+1<<endl;
    }

}

void worstfit(int b[20] , int p[20] , int n ,int m){
    int alloc[20];
    for(int i=0;i<n;i++){
        alloc[i] = -1;
    }
    for(int i=0;i<n;i++){
        int largest = -1;
        for(int j=0;j<m;j++){
            if(b[j]>=p[i]){
                if(largest==-1){
                largest = j;
            }
            else if(b[largest]<b[j]){
                largest = j;
            }
            }
            
        }
        if(largest!=-1){
            alloc[i] = largest;
            b[largest] = b[largest] - p[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<< (i+1) << "\t"<<p[i]<<"\t"<<alloc[i]+1<<endl;
    }
}

int main(){
    int blocks[20] = {50, 20, 100, 90}; 
    int processes[20] = {10, 300, 60, 30}; 
    
    worstfit(blocks,processes,4,4);
}