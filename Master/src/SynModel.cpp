#include "SynModel.h"
semaphore mutex = 1;
semaphore empty = n;
semaphore full = 0;

void producer() {
    while (true) {
        p(empty);
        p(mutex);
        // Critical Area
        v(mutex);
        v(full);
    }
}

void consumer() {
    while (true) {
        p(full);
        p(mutex);
        // Critical Area
        v(mutex);
        v(empty);
    }
}

int count = 0;
semaphore mutex = 1;
semaphore rw = 1;
// semaphore w = 1;

void writer() {
    while (true) {
        // p(w);
        p(rw);
        // Writing
        v(rw);
        // v(w);
    }
}

void reader() {
    p(mutex);
    if (count == 0) {
        p(rw);
    }
    ++count;
    v(mutex);

    // Reading

    p(mutex);
    --count;
    if (count == 0) {
        v(rw);
    }
    v(mutex);
}

semaphore chopstick[] = {1, 1, 1, 1, 1};
semaphore mutex = 1;
void philosopher(const int index) {
    while (true) {
        p(mutex);
        p(chopstick[index]);
        p(chopstick[(index + 1) % 5]);
        v(mutex);
        //Eat
        v(chopstick[index]);
        v(chopstick[(index + 1) % 5]);
        //Thinking
    }
}

int random;
semaphore offer1 = 0;
semaphore offer2 = 0;
semaphore offer3 = 0;
semaphore finish = 0;

void p1() {
    while (true) {
        random = std::random() % 3;
        switch(random) {
            case 0 : {
                v(offer1);
                break;
            }
            case 2 : {
                v(offer2);
                break;
            }
            case 3 : {
                v(offer3);
                break;
            }
        }
        p(finish);
    }
}
void p2() {
    while (true) {
        p(offer3);
        v(finish);
    }
}
void p3() {
    while (true) {
        p(offer2);
        v(finish);
    }
}
void p4() {
    while (true) {
        p(offer1);
        v(finish);
    }
}
