//
// Created by maples on 8/30/16.
//

#include "ThreadPool.h"

Maples::ThreadPool::ThreadPool(size_t threadNumber) {

}

Maples::ThreadPool::~ThreadPool() {

}

template<typename F, typename... Args>
auto Maples::ThreadPool::enqueue(F && func, Args && ... args)
    ->std::future<typename std::result_of<F(Args...)>::type> {
    return std::future << unknown >> ();
}


