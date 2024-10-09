#include <iostream>
#include <climits>
#include <unistd.h>
using namespace std;

int main()
{
    /* Create an array of 20 elements*/
    int arraySize = 20;
    int array[arraySize];

    /*Fill the array elements using the random number generator*/
    for(int i = 0; i < arraySize; i++) {
        int randomValue = rand() % arraySize + 1;
        array[i] = randomValue;
        cout << array[i];
        cout << " ";
    }
    cout << endl;
    
    /*Create a child process and find the minimum number in the second half of the array*/
    pid_t c_pid = fork();
    if(c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    /*Child process == 0*/
    else if(c_pid == 0) {
        cout << "printed from child process " << getpid() 
             << endl;
        cout << "the min value for the second half of the array is ";
        int smallest = INT_MAX;
        for(int i = arraySize / 2; i < arraySize; i++) {
            if (array[i] < smallest) {
                smallest = array[i];
            }
        }
        cout << smallest;
        cout << endl;
    }
    /*Parent process is > 0*/
    /*The parent process will find the minimum number in the first half of the array*/
    else {
        cout << "printed from parent process " << getpid() 
             << endl;
        cout << "the min value for the first half of the array is ";
        int smallest = INT_MAX;
        for(int i = 0; i < arraySize / 2; i++) {
            if(array[i] < smallest) {
                smallest = array[i];
            }
        }
        cout << smallest;
        cout << endl;
    }
    return 0;
}