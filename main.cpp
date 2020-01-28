
#include <iostream>
#include "CDA.cpp"
using namespace std; 


int main(){
    
    CDA<int> a = CDA<int>(); 

    for(int i = 0; i < 10; i++){
        a.addEnd(i);
    }
    for(int i = 0; i < 10; i++){
        a.addFront(i);
    }
    
    for(int i = 0; i < 20; i++){
        a.delFront();
    }
    
    a.printArray();
    
    
    return 0; 
}