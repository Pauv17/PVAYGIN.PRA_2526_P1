
#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "List.h"
#include "ListArray.h"
#include "Node.h"
using namespace std;


template <typename T>
class ListLinked : public List<T> {

    private:
	Node<T>* first;
		int n; 
        
    public:

	ListLinked(){
		first = nullptr;
		n = 0;

	}

	~ListLinked() {
		Node<T>* aux;
		while (first != nullptr) {
			aux = first->next;
			delete first;
			first = aux;
		}
		
	}
	void insert(int pos, T e) override{

                if(pos < 0 || pos > n){
                        throw out_of_range("Posición fuera del rango establecido");
         	}
		if (pos == 0) {                     // insertar al principio
 		       first = new Node<T>(e, first);
   		 } else {
       	       
		 Node<T>* prev = first;
		 for (int i = 0; i < pos - 1; i++) {
            		prev = prev->next;
		}
        	prev->next = new Node<T>(e, prev->next);
    		}
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
                Node<T>* objetivo;
		T removed;
		if (pos == 0){
			objetivo = first;
			first = first->next;
		}else{
			Node<T>* prev = first;
			for(int i = 0; i < pos-1;i++){
				prev = prev->next;
			}
			objetivo = prev->next;
			prev->next = objetivo->next;
		}

		removed = objetivo->data;
		
		delete objetivo;
		
		n--;
        
		return removed;
	}


        T get(int pos)const override{
                 if(pos < 0 || pos >= n){
                        throw out_of_range("La posición esta fuera del rango");
                }
		 Node<T>* current = first;
		 for(int i =0; i<pos;i++){
			 current = current->next;
		 }

		 return current->data;
                
        }

        int search(T e)const override{
		Node<T>* current = first;
		int pos = 0;

		while(current != nullptr){
			if(current->data == e){
				return pos;
			}
			current = current->next;
			pos++;
                }
                return -1;
        }

        bool empty()const override{
                return n==0;
        }

        int size() const override{
                return n;
        }

	T operator[](int pos){
		return get(pos);

		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
			Node<T>* current = list.first;

			if (current == nullptr){
				out << "List => []";
				return out;
			}

			out << "List => [\n";

			while (current != nullptr) {
				out << " " << current->data<<"\n";
				current = current->next;
				}

			out << "]";
			return out;
		}
	
};

#endif
