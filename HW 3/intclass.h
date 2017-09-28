#ifndef INTCLASS_H
#define INTCLASS_H
#pragma once
#include <assert.h>
class IntClass {
private:
    int *myArr;
    int *temp;
    int size;
    int usedSize;

    int partition(int *arr, const int left, const int right, bool (*ptr)(int, int)) {
        const int mid = left + (right - left) / 2;
        const int pivot = arr[mid];
        // move the mid point value to the front.
        std::swap(arr[mid],arr[left]);
        int i = left + 1;
        int j = right;
        while (i <= j) {
#if ptr == NULL
            while(i <= j && arr[i]<= pivot) i++;
            while(i <= j && arr[j] > pivot) j--;
#endif
            while(i <= j && !ptr(arr[i], pivot)) i++;
            while(i <= j && ptr(arr[j], pivot)) j--;
            if (i < j) std::swap(arr[i], arr[j]);
        }
        std::swap(arr[i - 1],arr[left]);
        return i - 1;
    }

    void sort(int *arr, const int left, const int right, bool (*ptr)(int, int)) {
        if (left >= right) { return; }
        int part = partition(arr, left, right, ptr);
        sort(arr, left, part - 1, ptr);
        sort(arr, part + 1, right, ptr);
    }
public:
    /* default constructor. */
    IntClass() : myArr(NULL), temp(NULL), size(0), usedSize(0) { }
    /* fill constructor.*/
    IntClass(int len, int num): size(len), usedSize(len) {
        myArr = new int[len];

        for(int i = 0; i < len; i++)
            myArr[i] = num;
    }
    /* Use an array to initialize. */
    IntClass(int *arr) {
        size = sizeof(arr) / sizeof(int);
        usedSize = size;
        myArr = new int[size];
        for(int i = 0; i < size; i++)
            myArr[i] = arr[i];
    }
    /* Copy constructor. */
    IntClass(const IntClass &Int) {
        myArr = new int[Int.maxsize()];
        size = Int.maxsize();
        usedSize = Int.usedsize();
        for(int i = 0; i < usedSize; i++)
            myArr[i] = Int[i];
    }
    /* destructor. */
    ~IntClass() { delete[] myArr; }
    /* return whether this array is empty or not. */
    bool empty() { return (myArr == NULL) ;}
    /* Return size of array. */
    int maxsize() const { return size; }
    /*Return used size of array. */
    int usedsize() const { return usedSize; }
    /* If there is no enough memory, I will redistribute twice the memory. */
    bool push_back(int num) {
        if(usedSize == size) {
            temp = new int[size * 2];
            if(temp == NULL)
                return false;
            size *= 2;
            for(int i = 0; i < usedSize; i++)
                temp[i] = myArr[i];
            delete[] myArr;
            myArr = temp;
        }
        myArr[usedSize++] = num;
        return true;
    }
    /* Get the first element. */
    int getFront() { return myArr[0]; }
    /* Get the last element. */
    int getBack() { return myArr[usedSize - 1]; }
    /* Insert an element. */
    bool insert(int num, int position) {
        /*I use this function first, in order to ensure there is enough space to store added number. */
        bool ans = push_back(num);
        assert(ans == true);
        for(int i = usedSize - 1; i > position; i++)
        {
            myArr[i] = myArr[i - 1];
        }
        myArr[position] = num;
        return true;
    }
    /* Sort the array. */
    bool compare(int a, int b) { return a > b ? true : false; }
    void sort() { sort(myArr, 0, usedSize - 1, NULL); }
    void sort(int begin, int end) { sort(myArr, begin, end, NULL); }
    void sort(int begin, int end, bool (*fun)(int, int)) { sort(myArr, begin, end, fun); }

    /* Operator [] overload. */
    int& operator [](int i) const {
        if(i > usedSize || i < 0) {
            std::cout << "Over size." << std::endl;
            exit(-1);
        }
        return myArr[i];
    }
    /* Operator == overload. */
    bool operator ==(const IntClass &B) const {
        if(this->usedsize() != B.usedsize())
            return false;
        for(int i = 0; i < usedSize; i++)
            if(myArr[i] != B[i])
                return false;
        return true;
    }
};

#endif // INTCLASS_H
