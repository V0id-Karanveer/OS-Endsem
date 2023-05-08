#include <bits/stdc++.h>
using namespace std;

void fcfs(int process[20],int head,int n){
    int dist=0;
    cout << head << " ";
    for(int i=0;i<n;i++){
        cout<< process[i] << " ";
    }
    dist += abs(head-process[0]);
    for(int i=1;i<n;i++){
        dist += abs(process[i]-process[i-1]);
    }
    cout<<endl;
    cout<<"Distance travelled is  "<<dist<<endl;
}

void sstf(int process[20],int head,int n){
    int dist=0;
    int visited[20];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    int min;
    int index;
    cout<< head<< " ";
    for(int i=0;i<n;i++){
        min = 1e7;
        for(int j=0;j<n;j++){
            if(abs(process[j]-head)<min && visited[j] ==0 && head!=process[j] ){
                min = abs(process[j]-head);
                
                index = j;
        
            }
        }
        dist+=min;
        cout<< process[index] << " ";
        visited[index] =1;
        head = process[index];

    }
    cout<<endl;
    cout << "Distance travelled" << dist << endl;


}

void scan(int process[20],int head,int n){
    int dist=0;
    sort(process,process+n);
    cout << head << " ";
    for(int i=0;i<n;i++){
        if(process[i]>head){
            cout << process[i] << " ";
        }
    }
    dist+= 199-head;
    cout<<"199"<< " ";
    for(int i=n-1;i>=0;i--){
        if(process[i]<head){
            cout << process[i] << " ";
        }
    }
    dist+=199-process[0];
    cout<<endl;
    cout<<dist;
}

void cscan(int process[20],int head,int n){
    int dist;
    sort(process,process+n);
    cout << head << " ";
    for(int i=0;i<n;i++){
        if(process[i]>head){
            cout << process[i] << " ";
        }
    }
    dist = 199-head;
    dist+=199;
    cout<<"199"<< " ";
    cout<<"0"<<" ";
    int store;
    for(int i=0;i<n;i++){
        if(process[i]<head){
            cout << process[i] << " ";
            store = process[i];
        }


}
dist+=store;
cout<<dist;

}

void look(int process[20],int head,int n){
    int dist;
    sort(process,process+n);
    cout << head << " ";
    for(int i=0;i<n;i++){
        if(process[i]>head){
            cout << process[i] << " ";
        }
    }
    dist = process[n-1]-head;
    int store;
    for(int i=n-1;i>=0;i--){
        if(process[i]<head){
            cout << process[i] << " ";
            store = process[i];
        }
    }
    dist+=process[n-1]-process[0];
    cout<<dist;

}

void clook(int process[20],int head,int n){
    int dist;
    sort(process,process+n);
    cout << head << " ";
    for(int i=0;i<n;i++){
        if(process[i]>head){
            cout << process[i] << " ";
        }
    }
    dist = process[n-1]-head;
    dist+=process[n-1]-process[0];
    int store;
    for(int i=0;i<n;i++){
        if(process[i]<head){
            cout << process[i] << " ";
            store = process[i];
        }
    }
    dist+=store-process[0];
    cout<<dist;

}

int main(){
    int head;
    cout<<"Enter the no. of processes"<<endl;
    int n=7;
    cout<<"Enter head position"<<endl;
    head = 50;
    cout<<"Input the processes"<<endl;
    int process[20] = {82,170,43,140,24,16,190};
    sstf(process,head,n);

}