#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <vector>
#include <iostream>

//线程安全的队列
//   只要满足先进先出特性的数据结构都可以称之为队列
//   数组是否可以实现一个队列？？？
//   1.读写下标的计算： pos = (pos+1) % 数组大小
//   2.对读写数组实现线程安全的时候
//      互斥：sem_t lock; sem_init(&lock, 0, 1);
//      同步：
//          生产者信号量：sem_t prod; sem_init(&prod, 0, 数组大小)
//      由于一开始数组当中没有空间可以读， 则计数器的初始值为0
//          消费者信号量：sem_t cons; sem_init(&cons, 0, 0);
#define CAPACITY 4

class RingQueue
{
    public:
        RingQueue()
            :vec_(CAPACITY)
        {
            capacity_ = CAPACITY;

            sem_init(&lock_, 0, 1);

            sem_init(&prod_, 0, capacity_);
            sem_init(&cons_, 0, 0);

            pos_write_ = 0;
            pos_read_ = 0;
        }

        ~RingQueue()
        {
            sem_destroy(&lock_);
            sem_destroy(&prod_);
            sem_destroy(&cons_);
        }

        void Push(int data)
        {
            sem_wait(&prod_); //1

            sem_wait(&lock_);  //2
            vec_[pos_write_] = data;
            pos_write_ = (pos_write_ + 1) % capacity_;
            sem_post(&lock_);

            sem_post(&cons_);
        }

        void Pop(int* data)
        {

            sem_wait(&cons_); //1

            sem_wait(&lock_); //2
            *data = vec_[pos_read_];
            pos_read_ = (pos_read_ + 1) % capacity_;
            sem_post(&lock_);

            sem_post(&prod_);
        }
    private:
        std::vector<int> vec_; 
        int capacity_;

        sem_t lock_;
        sem_t prod_;
        sem_t cons_;

        //读写位置
        int pos_write_;
        int pos_read_;
};


int main()
{
    return 0;
}
