#ifndef INCLUDED_PROCESS_H_
#define INCLUDED_PROCESS_H_

#include <iomanip>		// std::move()
#include "../abc/abc.h"

class Process
{
	ABC &&d_abc;

    public:
        Process(ABC &&abc);
        void execute();         // calls d_abc.interface()
};

Process::Process(ABC &&abc)
:
	d_abc(std::move(abc))
{}

void Process::execute()
{
	d_abc.interface();
}

#endif