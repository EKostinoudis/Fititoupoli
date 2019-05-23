#include<iostream>

using namespace std;

template <class X> void shuffle(X** myArray, int myArraySize){
    for(int i=myArraySize-1; i >= 1; i--) {
        // random number in [0, i]
        int j = rand() % i;

        // swap i-th and j-th elements
        X *temp = myArray[i];
        myArray[i] = myArray[j];
        myArray[j] = temp;
    }
}
