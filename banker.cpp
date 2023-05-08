#include <iostream>
using namespace std;



int main(){
    int max[10][10] , alloc[10][10] , need[10][10] , av[10] , w[10] , f[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, fin[10]={0,0,0,0,0,0,0,0,0,0};
    int scount = 0;
    cout << "enter the no. of process" << endl;
    int n;
    cin >> n;
    cout << "Enter the no. of resources" << endl;
    int m;
    cin >> m;
    cout<< "Enter the max matrix" << endl;
    for(int i=0;i<n;i++){
        cout<<"enter for process  "<<i<<endl;
        for(int j=0;j<m;j++){
            cout<< "enter for resource  " << j<<endl;
            cin>>max[i][j];
        }
    }
    cout<< "Enter the aloocated matrix" << endl;
    for(int i=0;i<n;i++){
        cout<<"enter for process  "<<i<<endl;
        for(int j=0;j<m;j++){
            cout<< "enter for resource  " << j<<endl;
            cin>>alloc[i][j];
        }
    }

    cout<< "Enter the total no. of resources avbaliable matrix" << endl;
    for(int i=0;i<m;i++){
        cout<<"enter for resource  "<<i<<endl;
        cin>>av[i];
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for(int i=0;i<m;i++){
        w[i] = av[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            w[j] -= alloc[i][j];
        }
    }
    for(int k=0;k<100;k++){
        for(int i=0;i<n;i++){
        int flag = 1;
        for(int j=0;j<m;j++){
            if(w[j]<need[i][j]){
                flag = 0;
            }
        }
        if(flag == 1 && fin[i]==0){
            f[scount] = i;
            scount++;
            fin[i] = 1;
            for(int j=0;j<m;j++){
                w[j] += alloc[i][j];
                

            }
        }
    }
    }
    
    if(scount == n){
        cout << "There is no deadlock , safestate is below" << endl;
        for(int i=0;i<n;i++){
            cout<< f[i] << endl;
        }
        cout<< "do you want resource request?" << endl;
        int ch;
        cin >> ch;
        if(ch==1){ 
            cout<<"Enter what process do u want to reques for?"<< endl;
            int p;
            cin >>p;
            for(int j=0;j<m;j++){
                cout<< "enter for resource  " << j<<endl;
                cin>>alloc[p][j];
            }

        }
    }
    else{
        cout << "no" << endl;
    }


}