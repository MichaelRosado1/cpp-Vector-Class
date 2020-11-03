//
//  main.cpp
//  cpp-vector-class
//
//  Created by Michael Rosado on 11/1/20.
//

#include <iostream>

class MyVector {
    //pointer to the address where the array data will be stored
    int* array;
    //size of the array
    int capacity;
    //index where the next inputted value will be stored
    int current;
    
public:
    MyVector() {
        array = new int[1];
        //vector capacity is set to 1
        capacity = 1;
        //keeps track of position of data to be added
        //pushing any number -> current++
        current = 0;
    }
    void push(int data) {
        /*if the position where the data needs to be added is = capacity
         then increase the size of the array, copy the array and add new value to the original value.
        */
        if (current == capacity) {
            //Not optimized for large arrays!
            //increases vector size to fit added data
            int* temp = new int[capacity * 2];
            //sets new temp array equal to the original array
            for (int i = 0; i < capacity; i++) {
                temp[i] = array[i];
            }
            //removes array data
            delete[] array;
            //increases the size of the array to fit new data
            capacity *= 2;
            //sets the array equal to the new array of size capacity * 2
            array = temp;
        }
        //if the current position isn't equal to the size of the array, set the new data to the position of the current index
        array[current] = data;
        //current++ to move along the array
        current++;
    }
    //returns the size of the array
    int size() {
        //since current is the next value's position in the vector, we can just return current
        return current;
    }
    //prints out every element in the vector
    void print() {
        //loop through array
        for (int i = 0; i < current; i++) {
            //print all elements in vector to the console seperated by a space
            std::cout<<array[i]<<" ";
        }
    }
    //sorts the array in acending order
    void sort() {
        if (size() == 1) {
            //an array of length 1 is already sorted!
            return;
        }
        /*
         Loops from the beginning of the array to the end of the array using the
         size() method created previously
         
            size() returns the current index of the array, which would also be equal to the current size of the vector.
         */
        int temp;
        //want to compare values to i
        for (int i = 0; i < size(); i++) {
            //loops through array again to compare all numbers to i
            for (int j =0; j < size(); j++) {
                // if any value in the array is smaller than array[i], swap them
                
                /*
                 it is also very interesting to see how switching the > sign to
                 < changes the way the data is sorted.
                 comparing > causes it to be sorted in acending order, while comparing < causes it to be sorted in decending order.
                 
                 */
                if (array[j] > array[i]) {
                    //keeps track of array[i] since it will change in value
                    temp = array[i];
                    array[i] = array[j];
                    //sets array[j] equal to original value of array[i]
                    array[j] = temp;
                }
            }
        }
        
    }
    //deletes all the data in the array
    void clear() {
        //sets array equal to same array created in the constructor
        delete[] array;
        capacity = 1;
        current = 0;
    }
    //replaces the value at the index containing num with the replacement value
    void replaceVal(int num, int replacementVal) {
        for (int i = 0; i < current; i++) {
            if (array[i] == num) {
                array[i] = replacementVal;
                return;
            }
        }
        std::cout<<"value not found in array"<<std::endl;
    }
};




int main() {
    //create new vector
    MyVector vect;
    
    vect.push(3);
    vect.push(20);
    vect.push(1);
    vect.push(4);
    vect.push(50);
    vect.push(23);
    /*
     vect should look like:
        [3,20,1,4,50,23]
    */
    vect.replaceVal(4, 400);
    
    vect.sort();
    vect.print();
    
    /*output looks like:
     1 3 4 20 23 50
     */
}
