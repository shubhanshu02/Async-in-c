#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Parameters to be passed into the
 * thread runner function
 * */

typedef struct parameters
{
    pthread_t thread;             // threadId
    int value;                    // some value (one of the parameters we need)
    int (*callback)(void *param); // completion callback
} threadParam;

/**
 * Completion Callback for the thread function
 * */
int completionCallback(void *param)
{
    printf("CALLBACK INITIAL STAGE\n");
    // Some callback stuff
    printf("CALLBACK ENDS\n");
}

/**
 * Runner for the thread
 * */
void *runner(void *arg)
{
    printf("Process Start\n");
    sleep(2);
    threadParam *para = (threadParam *)arg;

    printf("Calling Callback\n");
    para->callback(para);
}

/**
 * Synchronised Execution using Threads
 * */
void syncExecutor(int value)
{

    pthread_t thread;

    threadParam *tp = (threadParam *)malloc(sizeof(threadParam));
    tp->thread = thread;
    tp->value = value;
    tp->callback = &completionCallback;

    int returnValue = pthread_create(&thread, NULL, runner, tp);
    if (returnValue != 0)
    {
        printf("Error In Threads");
        exit(0);
    }
    pthread_join(thread, NULL);
}

/**
 * Asynchronised Execution using Threads
 * */
void asyncExecutor(int value)
{

    pthread_t thread;
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_DETACHED);

    threadParam *tp = (threadParam *)malloc(sizeof(threadParam));
    tp->thread = thread;
    tp->value = value;
    tp->callback = &completionCallback;

    int returnValue = pthread_create(&thread, &attributes, runner, tp);
    if (returnValue != 0)
    {
        printf("Error In Threads");
        exit(0);
    }
    pthread_detach(thread);
}

int main()
{
    // 5 is just a value taken for example
    syncExecutor(5);
    syncExecutor(5);

    // Uncomment the below part to run asynchronised tasks
    // asyncExecutor(5);
    // asyncExecutor(5);

    pthread_exit(NULL);
}