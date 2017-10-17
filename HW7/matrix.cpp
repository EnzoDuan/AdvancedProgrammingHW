#include "matrix.h"

template <class T>
Matrix<T>::Matrix( int c, int r ) {
    rows = r;
    cols = c;
    if ( c < 1 || r < 1 ) {
        cols = 0;
        rows = 0;
        vectors = NULL;
    }
    vectors = new Vector<T> * [ rows ];
    for ( int i = 0; i < rows; i++ ) {
        *(vectors + i) = new Vector<T>( cols );
    }
}

template <class T>
Matrix<T>::Matrix( const Matrix<T> & m ) {
    if ( m.rows < 1 || m.cols < 1 || m.vectors == NULL ) {
        rows = cols = 0;
        vectors = NULL;

    }
    rows = m.rows;
    cols = m.cols;
    vectors = new Vector<T> * [ m.rows ];
    for ( int i = 0; i < rows; i++ ) {
        vectors[i] = new Vector<T>( cols );
        *(*(vectors + i)) = *(*(m.vectors + i));
    }
}

template <class T>
Matrix<T>::~Matrix() {
    for ( int i = 0; i < rows; i++ )
        delete vectors[i];
    delete [] vectors;
}

template <class T>
Matrix<T> Matrix<T>::operator+( const Matrix<T> & m ) const {
    Matrix temp( cols, rows );
    if ( (rows == m.rows) && (cols == m.cols) ) {
        for ( int i = 0; i < rows; i++ )
            *(*(temp.vectors + i)) = *(*(vectors + i)) + *(*(m.vectors + i));
    }
    else {
        cout << "矩阵大小不同，无法相加！" << endl;
        exit(-1);
    }

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator-( const Matrix<T> & m ) const {
    Matrix temp( cols, rows );
    if ( (rows == m.rows) && (cols == m.cols) ) {

        for ( int i = 0; i < rows; i++ )
            *(*(temp.vectors + i)) = *(*(vectors + i)) - *(*(m.vectors + i));

    }
    else
    {
        cout << "矩阵的大小不相等，无法相减" << endl;
        exit(-1);
    }
    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator*( const int & n ) const {
    if ( rows < 1 || cols < 1 || vectors == NULL )
        throw "Cannot to this!";
    Matrix temp( cols, rows );
    for ( int i = 0; i < rows; i++ )
        *(*(temp.vectors + i)) = *(*(vectors + i)) * n;
    return temp;
}

template <class T>
Matrix<T> operator*( const int & n, const Matrix<T> & m ) {
    return (m * n);
}

template <class T>
Matrix<T> & Matrix<T>::operator+=( const Matrix<T> & m ) {
    if ( rows == m.rows && cols == m.cols ) {
        for ( int i = 0; i < rows; i++ ) {
            *(*(vectors + i)) += *(*(m.vectors + i));
        }
    } else
    return *this;
}

template <class T>
Matrix<T> & Matrix<T>::operator-=( const Matrix<T> & m ) {
    if ( rows == m.rows && cols == m.cols ) {
        for ( int i = 0; i < rows; i++ ) {
            *(*(vectors + i)) -= *(*(m.vectors + i));
        }
    }
    else {
        cout << "矩阵大小不相等。" << endl;
        exit(-1);
    }
    return *this;
}

template <class T>
Matrix<T> & Matrix<T>::operator*=( const int & n ) {
    for ( int i = 0; i < rows; i++ )
        *(*(vectors + i)) *= n;
    return *this;
}

template <class T>
T* Matrix<T>::operator[]( const int r) const {
    if (r < 0 || r > rows )
    {
        cout << "输入的位置不合法。" << endl;
        exit(-1);
    }
    return (vectors + r);
}

template <class T>
Matrix<T> & Matrix<T>::operator=( const Matrix<T> & m ) {
    if ( this == &m )
        return *this;

    if ( m.cols < 1 || m.rows < 1 || m.vectors == NULL )
    {
        cout << "输入的矩阵大小不合法。" << endl;
        exit(-1);
    }
    for ( int i = 0; i < rows; i++ )
        delete vectors[i];
    delete [] vectors;
    vectors = new Vector<T> * [ m.rows ];
    rows = m.rows;
    cols = m.cols;
    for ( int i = 0; i < rows; i++ ) {
        *(vectors + i) = new Vector<T>( m.cols );
    }
    for ( int j = 0; j < rows; j++ ) {
        *(*(vectors + j)) = *(*(m.vectors + j));
    }
    return *this;
}

template <class T>
std::istream & operator>>( std::istream & in, const Matrix<T> & m ) {
    if ( m.cols >= 1 && m.rows >= 1 && m.vectors != NULL ) {
        for ( int i = 0; i < m.rows; i++ )
            in >> *(*(m.vectors + i));
    }
    return in;
}

template <class T>
std::ostream & operator<<( std::ostream & out, const Matrix<T> & m ) {
    if ( m.cols >= 1 && m.rows >= 1 && m.vectors != NULL ) {
        for ( int i = 0; i < m.rows; i++ ) {
             out << (*(*(m.vectors + i)));
             std::cout << std::endl;
        }
    }
    return out;
}

template <class T>
bool Matrix<T>::operator==( const Matrix <T>& m ) const {
    if ( m.rows == rows ) {
        for ( int i = 0; i < rows; i++ ) {
            if ( (*(*(vectors + i)) == *(*(m.vectors + i))) == 0 )
                return false;
            else
                return true;
        }
    }
    return false;
}

template <class T>
bool Matrix<T>::operator!=( const Matrix<T> & m ) const {
    return !( (*this) == m );
}

template<class T>
bool Matrix<T>::modify(int c, int r, T num){
    if(c >= cols || r >= rows|| c < 0 || r < 0) {
        cout << "输入的位置不合法。" << endl;
        return false;
    }
    else
        (*this).vectors[c][r] = num;
    return true;
}
