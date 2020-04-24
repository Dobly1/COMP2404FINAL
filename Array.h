#ifndef ARRAY2D_H
#define ARRAY2D_H

/*
Class: Array
Author: Callum M

Purpose:
    -Array implements a 2D-Array of dynamically allocated T elements, as well as complimentary functions to use and work with the array

Data Members:
    -T** arr
        -This is the main array behind the array class, it's size is specified when the list is construced, as well the memory for it is
         allocated when the list is created
    -const int x
        -This is the X dimmension of the array,
    -const int y
        -This is the Y dimmension of the array

Member Functions:
    -Array(int,int)
        -This is the default constructor that creates an array of the dimmensions specified in the parameters
    -~Array()
        -This is the destructor that frees all the dynamically allocated memory
    -T get(int,int)
        -This is a getter to return the value at the specified index of the array
    -T set(T, int, int)
        -This is a setter to set a value at the array at the index specified, it returns the old value that occupied it
    -void fill(T)
        -Sets every index of the array equal to the value of T, useful for initalizing array with value that you want
*/


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

        void fill(T);    

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
void Array<T>::fill(T t)
{
    //Init 
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            arr[j][i] = t;
        }
    }
}

template<class T>
T Array<T>::get(int xCor, int yCor)
{
    if( (xCor < 0 || xCor>x) || (yCor < 0 || yCor>y))
        throw "Out of bounds";

    T data = arr[yCor][xCor];   
    return data;
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