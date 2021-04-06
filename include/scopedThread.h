#ifndef SCOPED_THREAD_H
#define SCOPED_THREAD_H

#include <thread>

class scopedThread
{
private:
    std::thread m_thread;

public:
    template <class Fn, class... Args>
    scopedThread(Fn &&fn, Args &&...args) : m_thread(fn, std::forward<Args>(args)...) {}

    scopedThread(scopedThread &&other)
    {
        m_thread = std::move(other.m_thread);
    }

    scopedThread &operator=(scopedThread &&other)
    {
        m_thread = std::move(other.m_thread);
        return *this;
    }

    std::thread &operator*()
    {
        return m_thread;
    }

    std::thread const &operator*() const
    {
        return m_thread;
    }

    std::thread *operator->()
    {
        return &operator*();
    }

    std::thread const *operator->() const
    {
        return &operator*();
    }

    ~scopedThread()
    {
        __join();
    }

private:
    void __join()
    {
        if (m_thread.joinable())
            m_thread.join();
    }
};

#endif