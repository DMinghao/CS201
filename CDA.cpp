#include "CDA.h"
#include <iostream> 
using namespace std; 
  
template <typename T> 
class CDA{
    private:
        T * front; 
        T * end;
        T * array; 
        int length; 
        int capacity; 
        bool sorted; 
    public: 
        CDA<T>::CDA(){
            CDA(1); 
        }

        CDA::CDA(int s){
            array = new T[s]; 
            capacity = s; 
            length = 0; 
            sorted = false; 
        }

        T& CDA::operator[](int i){
            if(i > length){
                cout << "Error: Index out of bound" << endl; 
                return NULL; 
            }
        }

        void CDA::AddEnd(T v){
            if(end != NULL){

            }else return; 
        }

        void CDA::AddFront(T v){
            if(front != NULL){

            }else return; 
        }

        void CDA::DelEnd(){
            if(end != NULL){

            }else return; 
        }

        void CDA::DelFront(){
            if(front != NULL){

            }else return; 
        }

        int CDA::Length(){
            return length; 
        }

        int CDA::Capacity(){
            return capacity; 
        }

        int CDA::Clear(){

        }

        bool CDA::Ordered(){
            return sorted; 
        }

        int CDA::SetOrdered(){

        }

        T CDA::Select(int k){

        }

        Void CDA::InsertionSort(){

        }

        void CDA::QuickSort(){

        }

        void CDA::CountingSort(int m){

        }

        int CDA::Search(T e){
            if(sorted){

            }else{

            }
        }

        CDA::~CDA(){

        }
};