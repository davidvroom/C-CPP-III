#ifndef INCLUDED_PROCESS_H_
#define INCLUDED_PROCESS_H_

#include "../abc/abc.h"
#include <iomanip> // std::move()

class Process
{
	ABC &&d_abc;

    public:
        Process(ABC &&abc);
        void execute();        
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