// Why doesn't flex have non-greedy operators like perl does?

// A DFA can do a non-greedy match by stopping the first time it 
// enters an accepting state, instead of consuming input until it 
// determines that no further matching is possible (a "jam" state). 
// This is actually easier to implement than longest leftmost match 
// (which flex does).

// But it's also much less useful than longest leftmost match. In 
// general, when you find yourself wishing for non-greedy matching, 
// that's usually a sign that you're trying to make the scanner do 
// some parsing. That's generally the wrong approach, since it lacks 
// the power to do a decent job. Better is to either introduce a 
// separate parser, or to split the scanner into multiple scanners 
// using (exclusive) start conditions.

// You might have a separate start state once you've seen the 
// `BEGIN'. In that state, you might then have a regex that will 
// match `END' (to kick you out of the state), and perhaps `(.|\n)' 
// to get a single character within the chunk ...

// This approach also has much better error-reporting properties. 

#include "main.ih"

int main()
try
{
	Scanner scanner;

	while (scanner.lex())
		;
}
catch (...)
{
	return 1;
}
