
#include <iostream>
#include "CDA.cpp"
using namespace std; 


int main(){
    
    CDA<int> a = CDA<int>(); 

    for(int i = 0; i < 10; i++){
        a.AddEnd(i);
    }
    for(int i = 0; i < 10; i++){
        a.AddFront(i);
    }
    
    for(int i = 0; i < 20; i++){
        a.DelFront();
        //a.DelEnd();
    }
    
    a.printArray();
    
    
    return 0; 
}