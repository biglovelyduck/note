#ifndef BLOB_H
#define BLOB_H
#include <memory>
#include <vector>
using namespace std;
template<typename T>
class Blob{
public:
	typedef T value_type;
	typedef typename vector::size_type size_type;
	
	Blob();
	Blob(initializer_list<T> il);
	template<typename It>
	Blob(It b,It e); 
private:
    std::shared_ptr<std::vector<T>> data;
    //! throw msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

//!  default constructor
template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{}

//! constructor taking initializer_list
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il)){ }

//! constructor taking two iterators
template<typename T>    //for class
template<typename It>   //for this member
Blob<T>::Blob(It b, It e) :
    data(std::make_shared<std::vector<T>>(b,e))
{}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if(i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return data->back();
}

template<typename T>
const T& Blob<T>::back() const
{
    check(0,"back on empty Blob");
    return data->back();
}


template<typename T>
T& Blob<T>::operator [](size_type i)
{
    //! if i is too big, check function will throw,preventing access to a nonexistent element
    check(i,"subscript out of range");
    return (*data)[i];
}


template<typename T>
const T& Blob<T>::operator [](size_type i) const
{
    //! if i is too big, check function will throw,preventing access to a nonexistent element
    check(i,"subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob");
    data->pop_back();
}

#endif // BLOB_H
