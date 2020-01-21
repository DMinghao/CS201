#ifndef CDA_H
#define CDA_H

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
        CDA();
        CDA(int s);
        T& operator[](int i);
        void AddEnd(T v);
        void AddFront(T v);
        void DelEnd();
        void DelFront();
        int Length();
        int Capacity();
        int Clear();
        bool Ordered();
        int SetOrdered();
        T Select(int k);
        Void InsertionSort();
        void QuickSort();
        void CountingSort(int m);
        int Search(T e);
        ~CDA();
};

#endif CDA_H