#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"
using namespace std;


template <typename T> 
class ListArray : public List<T> {

    private:


        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;


	void resize(int new_size){

    	T* new_array = new T[new_size];

	for (int i = 0 ; i < n ; i++) {

		new_array [i] = arr [i];
		}		
	
		delete[] arr;

		arr = new_array;

		max = new_size;
	}
	
	
     public:

	ListArray() {
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;

	}

	~ListArray(){
		delete[] arr;
	}

	
	void insert(int pos, T e) override{

		if(pos < 0 || pos > n){
			throw out_of_range("Posición fuera del rango establecido");
		}

		if(n == max){
			resize( max*2);
		}

		
		for (int i = n; i > pos; i--) {
			arr[i] = arr [i - 1];
		}
		
			arr[pos] = e;
			n++;
		}
	

	void append(T e)override{
		insert (n, e);

	}
	void prepend(T e)override{
		insert(0,e);
	}

	T remove(int pos) override {
		if (pos < 0 || pos >= n) {
			throw out_of_range("La posición esta fuera del rango");
		}
		T removed = arr[pos];

		for (int i = pos; i < n-1; i++) {
				arr[i] = arr[i + 1];
			}
			n--;

			return removed;
	}

	T get(int pos)const override{
		 if(pos < 0 || pos >= n){
                        throw out_of_range("La posición esta fuera del rango");
                }
		
		return arr[pos];
	}
	
	int search(T e)const override{
		for(int i= 0; i<n; i++){
			if( arr[i] == e){
				return i;
			}
			
		}
		return -1;
	}

	bool empty()const override{
		return n==0;
	}

	int size() const override{
		return n;
	}

	T operator[](int pos) {
		if(pos< 0 || pos >=n) {
			throw out_of_range("La posición esta fuera del rango");
		}
		return arr[pos];
	}

	friend ostream& operator<<(ostream &out, const ListArray<T> &list) {
			if (list.n == 0) {
				out << "List => []";
				return out;
			}

			out << "List => [\n";
			for (int i = 0; i < list.n; i++) {
				out << " " << list.arr[i] << "\n";
				
			}
			out << "]";
			return out;
		}
};


#endif
