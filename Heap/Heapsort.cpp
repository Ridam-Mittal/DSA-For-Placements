#include<iostream>
using namespace std;


void heapify(int a[], int size, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < size && a[left] > a[largest]){
        largest = left;
    }
    if(right < size && a[right] > a[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(a[largest], a[i]);
        heapify(a, size, largest);
    }
    else{
        return;
    }
}


void heapsort(int a[], int n){
    for(int i = n-1; i >= 1; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}


int main(){
    int a[100] = {54, 53, 55, 52, 50};
    int size = 5;
    for(int i = size/2-1; i >= 0; i--){
        heapify(a, size, i);
    }
    
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }cout << endl;
    
    
    heapsort(a, size);
    
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }cout << endl;
}