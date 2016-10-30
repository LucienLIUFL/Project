//
// Created by maples on 8/30/16.
//

#ifndef MAPLESLIB_THREADPOOL_H
#define MAPLESLIB_THREADPOOL_H

#include <stdexcept>
#include <utility>
#include <memory>
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
            std::future<typename std::result_of<F(Args...)>::type>
            enqueue(F && func, Args && ... args);

        private:
            std::vector<std::thread> workers;
            std::queue<std::function<void()>> tasks;
            std::mutex queueMutex;
            std::condition_variable condition;

            bool stop;

    };

    template<typename F, typename... Args>
    auto ThreadPool::enqueue(F && func, Args && ... args)
    ->std::future<typename std::result_of<F(Args...)>::type> {

        using ReturnType = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<ReturnType()>>(
                std::bind(std::forward<F>(func), std::forward<Args>(args)...)
        );

        std::future<ReturnType> res = task->get_future();

        {
            std::unique_lock<std::mutex> lock(this->queueMutex);
            if (this->stop) {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }
            this->tasks.emplace([task]{(*task)();});
        }

        condition.notify_one();
        return res;
    }

    inline ThreadPool::ThreadPool(size_t threadNumber) : stop(false) {
        for (size_t i = 0; i < threadNumber; ++i) {
            this->workers.emplace_back(
                    [this] {
                        for(;;) {
                            std::function<void()> task;
                            {
                                std::unique_lock<std::mutex> lock(this->queueMutex);
                                this->condition.wait(lock, [this]{
                                    return this->stop || this->tasks.empty();
                                });
                                if (this->stop && this->tasks.empty()) {
                                    return;
                                }

                                task = std::move(this->tasks.front());
                                this->tasks.pop();
                            }

                            task();
                        }
                    }
            );
        }
    }

    inline ThreadPool::~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(this->queueMutex);
            this->stop = true;
        }

        this->condition.notify_all();

        for (std::thread & worker : this->workers) {
            worker.join();
        }
    }

}



#endif //MAPLESLIB_THREADPOOL_H
