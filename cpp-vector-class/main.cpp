//
//  main.cpp
//  cpp-vector-class
//
//  Created by Michael Rosado on 11/1/20.
//

#include <iostream>
class MyVector {
    int* array;
    
    int capacity;
    
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
            //sets the array equal to the
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
};




int main() {
    //create new vector
    MyVector vect;
    
    vect.push(3);
    vect.push(20);
    vect.push(1);
    vect.push(4);
    /*
     vect should look like:
        [3,20,1,4]
    */
    vect.print();
    /*output should look like:
        3 20 1 4
     */
}
