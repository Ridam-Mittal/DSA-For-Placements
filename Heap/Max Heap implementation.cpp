#include<iostream>
using namespace std;

void insert(int val, int &size, int a[]){
    int index = size;
    a[index] = val;
    size = size + 1;
    
    while(index > 0){
        int parent = (index-1) / 2;
        
        if(a[parent] < a[index]){
            swap(a[parent], a[index]);
            index = parent;
        }
        else{
            return;
        }
    }
}


void deletion(int a[], int &size){
    if(size == 0){
        cout << "Nothing to delete" << endl;
        return;
    }
    a[0] = a[size-1];
    size = size-1;
    int index = 0;
    
    while(index < size){
        int left = 2*index+1;
        int right = 2*index+2;
        
        if(left < size && right < size){ 
            // If both children exist, swap with the larger one
            if(a[left] > a[right] && a[index] < a[left]){
                swap(a[index], a[left]);
                index = left;
            }
            else if(a[right] > a[left] && a[index] < a[right]){
                swap(a[index], a[right]);
                index = right;
            }
            else{
                return;
            }
        }
        else if(left < size && a[index] < a[left]){
            // If only left child exists
            swap(a[index], a[left]);
            index = left;
        }
        else{
            return;
        }
    }
}


int main(){
    int a[100];
    int size = 0;
    insert(50, size, a);
    insert(55, size, a);
    insert(53, size, a);
    insert(52, size, a);
    insert(54, size, a);
    
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
    deletion(a, size);
     for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    
}