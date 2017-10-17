#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <new>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

template <class T>
class Vector {
private:
    T * vectors;
    int size;
public:
    /* Constructor. */
    Vector( int input);
    Vector( const Vector & v );
    /* Destructor */
    ~Vector();
    /* Fundamental operators overload. */
    Vector operator+( const Vector & v ) const;
    Vector operator-( const Vector & v ) const;
    Vector operator*( const int & n ) const;
    /* Special operators overload. */
    T  operator*( const Vector & v ) const;
    friend Vector operator*( const int & n, const Vector & v );
    /* Assignment functions' overload. */
    Vector & operator=( const Vector & src );
    void     operator*=( const double & n );
    void     operator+=( const Vector & v );
    void     operator-=( const Vector & v );
    /* Access operator [] overload. */
    T      operator[]( const int i ) const;
    /* IO stream operators pverload.They must be global function. */
    friend std::ostream & operator<<( std::ostream & out, const Vector & v_out );
    friend std::istream & operator>>( std::istream & in, const Vector & v_in );
    /* Compare functions overload. */
    bool operator==( const Vector & v );
    bool operator!=( const Vector & v );
    bool modify(int pos, T num);
    /*
     new and delete operators overload.
    T* operator new(const int size);
    bool operator delete();
    */
};

#endif // VECTOR_H
