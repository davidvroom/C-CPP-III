#ifndef INCLUDED_PROCESS_H_
#define INCLUDED_PROCESS_H_

#include <iomanip>

class ABC;

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

inline void Process::execute()
{}

#endif