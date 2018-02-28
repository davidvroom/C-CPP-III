#ifndef INCLUDED_SEMAPHORE_H_
#define INCLUDED_SEMAPHORE_H_

#include <mutex>
#include <condition_variable>
#include <utility>

class Semaphore
{
	mutable std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;
    // possibly other members

	public:
		template <typename Function, typename ...Params>
		bool wait(Function &&fun, Params &&...params);
		// other members
};

template <typename Function, typename ...Params>
bool Semaphore::wait(Function &&fun, Params &&...params)
{
	std::unique_lock<std::mutex> lk(d_mutex);
	while (d_nAvailable == 0)
		d_condition.wait(lk);

	bool ret = fun(std::forward<Params>(params)...);

	if (!ret || d_nAvailable == 0)
		return false;
	
	--d_nAvailable;
	return true;
}

#endif