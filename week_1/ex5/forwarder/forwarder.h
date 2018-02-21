#ifndef INCLUDED_FORWARDER_
#define INCLUDED_FORWARDER_

template <typename Function, typename ...Params>
void forwarder(Function fun, Params &&...params)
{
	fun(std::forward<Params>(params)...);
}

#endif