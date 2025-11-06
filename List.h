#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
        virtual ~List() {}

	virtual void insert(int pos, T e) = 0;





};

#endif
