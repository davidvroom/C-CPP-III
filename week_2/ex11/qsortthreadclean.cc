#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <stack>
#include <mutex>
#include <chrono>
#include <atomic>

#include <bobcat/semaphore>

using namespace std;
using namespace FBB;
using namespace chrono;

int ia[] = {
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
        4, 1, 3, 5, 7, 9, 10, 2, 8, 6,
            };

size_t const iaSize = sizeof(ia) / sizeof(int);

struct Pair
{
    int *beg;
    int *end;
    Pair() = default;
    Pair(int *b, int *e)
    :
        beg(b),
        end(e)
    {}
};

Semaphore   availableRanges(1);     // available ranges to sort
stack<Pair> nextRange;
mutex       nextMutex;

mutex outMutex;

int *partition(Pair pair)
{
    int lhs = *pair.beg;
    int *mid = partition(pair.beg + 1, pair.end, 
        [&](int arg)
        {
//            this_thread::sleep_for(nanoseconds(1000));
            return arg < lhs;
        }
    );
    swap(*pair.beg, *(mid - 1));

    return mid;
}

mutex waitingMutex;
int waiting = 0;

void testDone()
{
    lock_guard<mutex> lg(waitingMutex);
    ++waiting;

    if (nextRange.size() == 0 && waiting == 3)
    {
        waiting = 100;
        availableRanges.notify_all();
     }
}

Pair getNextPair(thread::id id)      // if pair's beg member == 0 then done
{
    testDone();

    availableRanges.wait();
    {
        lock_guard<mutex> lg(waitingMutex);
        --waiting;
    }

    Pair pair;

    {
        lock_guard<mutex> lg(nextMutex);

        if (nextRange.empty())
        {
            {
                lock_guard<mutex> lg(outMutex);            
                cerr << id << " ends\n";
            }

            availableRanges.notify_all();
            pair.beg = 0;
        }
        else
        {
            pair = nextRange.top();
            nextRange.pop();
        }
    }
    return pair;
}

void tryRange(int *beg, int *end)
{
    if (end - beg > 1)
    {
        nextRange.push(Pair{beg, end});
        availableRanges.notify_all();
    }
}

void sortJobs(Pair const &pair)
{
    lock_guard<mutex> lg(nextMutex);

    int *mid = partition(pair);

    tryRange(pair.beg, mid);
    tryRange(mid, pair.end);
}

void tsort()
{
    auto id = this_thread::get_id();

    while (true)
    {
        Pair pair = getNextPair(id);

        if (pair.beg == 0)
            return;

        {
            lock_guard<mutex> lg(outMutex);            
            cerr << id << '\n';
        }

        sortJobs(pair);
    }
}

int main()
{
    nextRange.push(Pair{ia, ia + iaSize});

    thread t1(tsort);
    thread t2(tsort);
    thread t3(tsort);


    t1.join();
    t2.join();       
    t3.join();       

    for (int val: ia)
        cout << val << ' ';
    cout << '\n';
}








