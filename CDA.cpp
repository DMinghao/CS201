#include "CDA.h"
#include <iostream> 
using namespace std; 
  
template <typename T> 
class CDA{
    private:
        T * front; 
        T * end;
        T[] array; 
        int length; 
        int capacity; 
        bool sorted; 
    public: 
        CDA::CDA(){
            CDA(4); 
        }

        CDA::CDA(int s){
            array = new T[s]; 
            capacity = s; 
            length = 0; 
            sorted = false; 
        }

        T& CDA::operator[](int i){
            
        }

        void CDA::AddEnd(T v){

        }

        void CDA::AddFront(T v){

        }

        void CDA::DelEnd(){

        }

        void CDA::DelFront(){

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

        }

        CDA::~CDA(){

        }
};