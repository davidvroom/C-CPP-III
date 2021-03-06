#ifndef INCLUDED_ABC_H_
#define INCLUDED_ABC_H_

#include <utility> 				// std::forward

class ABC
{
	public:
		virtual ~ABC();

		void interface();		// calls run

		template <typename Type, typename ...Params>
		static ABC &&make(Params &&...params);		

	private:
		virtual void run() = 0;
};
 
template <typename Type, typename ...Params>
ABC &&ABC::make(Params &&...params)
{
	return std::move(Type{std::forward<Params>(params)...});
}

#endif