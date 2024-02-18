#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[5] = {5,4,3,2,1};
    int iter = 0;
    for(int i = 0 ; i < 4; i++){
        int check=0;
        iter++;

        for(int j = 0 ; j < 4-i ; j++ ){

            if(arr[j] > arr[j+1]){
                swap( arr[j] , arr[j+1] );
                check=1;
                iter++;

            }

        }
        if(check==0){
            break;
        }
    }
    for(int k = 0 ; k < 5; k++){
    cout<<arr[k]<<endl;
    }   
    cout<<iter<<endl;
    return 0;
}