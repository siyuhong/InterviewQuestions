#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int shared_data = 0;
std::mutex mtx;

void thread_function(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        shared_data += 1;
        std::cout << "Thread " << id << " incremented shared_data to " << shared_data << std::endl;
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(std::thread(thread_function, i));
    }

    for (auto &t : threads)
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    std::cout << "Final value of shared_data: " << shared_data << std::endl;

    return 0;
}