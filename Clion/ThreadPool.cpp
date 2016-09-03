//
// Created by maples on 8/30/16.
//

#include "ThreadPool.h"

Maples::ThreadPool::ThreadPool(size_t threadNumber) : stop(false) {
    for (size_t i = 0; i < threadNumber; ++i) {
        this->workers.emplace_back(
            [this] {
                for(;;) {
                    std::function<void()> task;
                    {

                    }
                }
            }
        );
    }
}

Maples::ThreadPool::~ThreadPool() {

}

template<typename F, typename... Args>
auto Maples::ThreadPool::enqueue(F && func, Args && ... args)
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


