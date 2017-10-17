#include "vector.h"
template <class T>
Vector<T>::Vector( int input ) {
    if ( input < 1 ) {
        size = 0;
        vectors = NULL;
        return;
    }
    size = input;
    vectors = new T[ input ];
    for ( int i = 0; i < input; i++ ) {
        vectors[i] = 0;
    }
}

template <class T>
Vector<T>::Vector( const Vector & v ) {
    size = v.size;
    vectors = new T[ v.size ];
    for ( int i = 0; i < v.size; i++ )
        vectors[i] = v.vectors[i];
}

template <class T>
Vector<T>::~Vector() {
    delete [] vectors;
}

template <class T>
Vector<T> Vector<T>::operator+( const Vector<T> & v ) const {
    if ( size == v.size ) {
        Vector<T> new_v( v.size );
        for ( int i = 0; i < size; i++ )
            new_v.vectors[i] = vectors[i] + v.vectors[i];
        return new_v;
    }
    else {
        cout << "向量长度不相等无法相加!"  << endl;
        exit(-1);
    }
}

template <class T>
Vector<T> Vector<T>::operator-( const Vector<T> & v ) const {
    if ( size == v.size ) {
        Vector<T> temp( v.size );
        for ( int i = 0; i < v.size; i++ )
            *(temp.vectors + i) = *(vectors + i) - *(v.vectors + i);
        return temp;
    }
    else {
        cout << "向量长度不想等无法相减。" << endl;
        exit(-1);
    }
}

template <class T>
Vector<T> Vector<T>::operator*( const int & n ) const {
    Vector<T> temp( size );
    for ( int i = 0; i < size; i++ )
        temp.vectors[i] = vectors[i] * n;
    return temp;
}

template <class T>
Vector<T> operator*( const int & n, const Vector<T> & v ) {
    Vector<T> temp( v.size );
        for ( int i = 0; i < v.size; i++ )
            temp.vectors[i] = v.vectors[i] * n;
    return temp;
}

template <class T>
T Vector<T>::operator*( const Vector<T> & v ) const  {
    if ( size < 1 || vectors == NULL || v.size < 1 || v.vectors == NULL )
        return 0;
    if ( size == v.size ) {
        int result = 0;
        for ( int i = 0; i < size; i++ )
            result += v.vectors[i] * vectors[i];
    return result;
    } else
    {
        cout << "两个向量大小不等，不能相乘。" << endl;
        exit(-1);
    }
}

template <class T>
Vector<T> & Vector<T>::operator=( const Vector<T> & src ) {
    if ( this == &src )
        return *this;
    else if ( size == src.size ) {
            delete [] vectors;
            vectors = new int[ size ];
            for ( int i = 0; i < size; i++ )
                vectors[i] = src.vectors[i];
            return *this;
        }
    else {
        delete [] vectors;
        vectors = new int[src.size];
        size = src.size;
        for ( int i = 0; i < size; i++ )
            vectors[i] = src.vectors[i];
    }

    return *this;
}

template <class T>
std::ostream & operator<<( std::ostream & out, const Vector<T> & v_out ) {
    //cout << endl;
    for ( int i = 0; i < v_out.size; i++ ) {
        out << v_out.vectors[i] << " ";
    }
    return out;
}

template <class T>
std::istream & operator>>( std::istream & in, const Vector<T> & v_in ) {

    if ( v_in.size >= 1 && v_in.vectors != NULL ) {
        for ( int i = 0; i < v_in.size; i++ ) {
            in >> v_in.vectors[i];
        }
    }
    return in;
}

template <class T>
void Vector<T>::operator+=( const Vector<T> & v ) {
    *this = *this + v;
}

template <class T>
void Vector<T>::operator*=( const double & n ) {
    (*this) = (*this) * n;
}

template <class T>
void Vector<T>::operator-=( const Vector<T> & v ) {
    *this = *this - v;
}

template <class T>
T Vector<T>::operator[]( const int i ) const {
    if ( i >= size || i < 0 )
    {
        cout << "数组的大小不正确。" << endl;
        exit(-1);
    }
    return *(*this).vectors[i];
}

template <class T>
bool Vector<T>::modify(int pos, T num) {
    if(pos >= size || pos < 0) {
        cout << "输入的位置不合法。" << endl;
        return false;
    }
    else
        (*this).vectors[pos] = num;
    return true;
}
