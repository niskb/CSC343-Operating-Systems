#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int shared_variable = 0;
pthread_mutex_t mutex;

// Thread_1 Writes information into Shared Variable
void* write(void* arg) {
    // Lock mutex before writing
    pthread_mutex_lock(&mutex);
        
    // Write to the shared variable
    printf("Thread_1: wrote %d\n", shared_variable);
        
    // Unlock mutex after writing
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

// Thread_2 Reads information from Shared Variable
void* read(void* arg) {
    // Lock mutex before reading
    pthread_mutex_lock(&mutex);
        
    // Read from the shared variable
    printf("Thread_2: read %d\n", shared_variable);
        
    // Unlock mutex after reading
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t thread_1, thread_2;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&thread_1, NULL, write, NULL);
    pthread_create(&thread_2, NULL, read, NULL);

    // Wait for threads to finish
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}