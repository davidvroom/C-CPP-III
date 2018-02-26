#ifndef INCLUDED_ABC_H_
#define INCLUDED_ABC_H_

class ABC
{
	public:
		virtual ~ABC();

		void interface();		//calls run

	private:
		virtual void run() = 0;
};

inline void ABC::interface()
{
	run();
}

#endif