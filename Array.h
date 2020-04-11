#ifndef ARRRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template<class T>
class Array
{
    public:
    //Constructor/Destructor
    Array(int=25,int=5);
    ~Array();

    //Others
    T get(int,int);
    T set(T, int, int);

    //getters
    int getX();
    int getY();

    private:
    T** arr;
    const int x;
    const int y;
};

template<class T>
Array<T>::Array(int xDim, int yDim):x(xDim),y(yDim)
{
    arr = new T*[y];

    for(int i = 0; i < y; i++)
    {
        arr[i] = new T[x];
    }   

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            arr[j][i] = 'x';
        }
    }

}

template<class T>
Array<T>::~Array()
{
    for(int i = 0; i<y; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

template<class T>
T Array<T>::get(int xCor, int yCor)
{
    if( (xCor < 0 || xCor>x) || (yCor < 0 || yCor>y))
        throw "Out of bounds";

    return arr[yCor][xCor];
}

template<class T>
T Array<T>::set(T data, int xCor, int yCor)
{
    if( (xCor < 0 || xCor>x) || (yCor < 0 || yCor>y))
        throw "Out of bounds";

    T oldData = arr[yCor][xCor];

    arr[yCor][xCor] = data;

    return oldData;
}

template<class T>
int Array<T>::getX()
{
    return x;
}

template<class T>
int Array<T>::getY()
{
    return y;
}



#endif