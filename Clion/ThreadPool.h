//
// Created by maples on 8/30/16.
//

#ifndef MAPLESLIB_THREADPOOL_H
#define MAPLESLIB_THREADPOOL_H

#include <mutex>
#include <future>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>

namespace Maples {
    class ThreadPool {
        public:
            ThreadPool(size_t threadNumber);
            ~ThreadPool();

            template <typename F, typename... Args>
            auto enqueue(F && func, Args && ... args) -> std::future<typename std::result_of<F(Args...)>::type>;

        private:
            std::vector<std::thread> workers;
            std::queue<std::function<void()>> tasks;
            std::mutex queueMutex;
            std::condition_variable condition;

            bool stop;

    };


}



#endif //MAPLESLIB_THREADPOOL_H
