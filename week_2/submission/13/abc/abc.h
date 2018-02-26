#ifndef INCLUDED_ABC_H_
#define INCLUDED_ABC_H_

#include <utility> 	// std::forward

class ABC
{
	public:
		virtual ~ABC();

		void interface();		// calls run

		//template <typename Type, typename ...Params>
		//static ABC &&make(Params &&...params);		// for part 2 of ex13

	private:
		virtual void run() = 0;
};
 /*
template <typename Type, typename ...Params>
ABC &&ABC::make(Params &&...params)
{
	return Type{std::forward<Params>(params)...};
}
*/

#endif