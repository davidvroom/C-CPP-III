#ifndef INCLUDED_DATA_H_
#define INCLUDED_DATA_H_

#include <vector>
#include <memory>
#include <string>

class Data
{
	typedef std::vector<std::shared_ptr<std::string>> DataVector;

    DataVector d_data;

    public:
    	typedef std::string value_type;		// needed for back_inserter

        void push_back(std::string const &str);
};


#endif
