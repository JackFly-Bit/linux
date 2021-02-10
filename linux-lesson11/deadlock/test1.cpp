#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define THREADCOUNT 1

pthread_mutex_t lock_;
pthread_mutex_t lock2_;

void* ThreadLock1(void* arg)
{
    (void)arg;
    pthread_mutex_lock(&lock_);

    sleep(2);
    
    pthread_mutex_lock(&lock2_);

    pthread_mutex_unlock(&lock2_);
    pthread_mutex_unlock(&lock_);

    return NULL;
}

void* ThreadLock2(void* arg)
{
    (void)arg;
    pthread_mutex_lock(&lock2_);

    sleep(2);

    pthread_mutex_lock(&lock_);

    pthread_mutex_unlock(&lock_);
    pthread_mutex_unlock(&lock2_);
    return NULL;
}

int main()
{
    pthread_mutex_init(&lock_, NULL);
    pthread_mutex_init(&lock2_, NULL);
    pthread_t tid[THREADCOUNT], tid2[THREADCOUNT];
    for(int i = 0; i < THREADCOUNT; i++)
    {
        int ret = pthread_create(&tid[i], NULL, ThreadLock1, NULL);
        if(ret < 0)
        {
            perror("pthread_create");
            return -1;
        }

        ret = pthread_create(&tid2[i], NULL, ThreadLock2, NULL);
        if(ret < 0)
        {
            perror("pthread_create");
            return -1;
        }
        
    }

    sleep(3);

    for(int i = 0; i < THREADCOUNT; i++)
    {
        pthread_join(tid[i], NULL);
        pthread_join(tid2[i], NULL);
    }

    pthread_mutex_destroy(&lock_);
    pthread_mutex_destroy(&lock2_);
    return 0;
}
