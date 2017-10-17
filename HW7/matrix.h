#ifndef MATRIX_H_H
#define MATRIX_H_H
#include "vector.h"

template <class T>
class Matrix
{
private:
    Vector<T> ** vectors;
    int rows, cols;

public:
    Matrix(int c, int r);
    Matrix( const Matrix & m );
    ~Matrix();

    Matrix & operator=( const Matrix & m );
    Matrix   operator+( const Matrix & m ) const;
    Matrix   operator-( const Matrix & m ) const;
    Matrix & operator+=( const Matrix & m );
    Matrix & operator-=( const Matrix & m );
    Matrix & operator*=( const int & n );
    Matrix operator*( const int & m ) const;
    friend Matrix operator*( const int & n, const Matrix & m );
    T* operator[]( const int r ) const;

    friend std::ostream & operator<<( std::ostream & out, const Matrix & m );
    friend std::istream & operator>>( std::istream & in, const Matrix & m );

    bool operator==( const Matrix & m ) const;
    bool operator!=( const Matrix & m ) const;
    bool modify(int c, int r, T num);
};


#endif // MATRIX_H_H
