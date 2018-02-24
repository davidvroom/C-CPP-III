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
    	typedef std::string value_type;
		//typedef value_type const &const_reference;

        void push_back(std::string const &str);
        std::string get(size_t idx) const;		// for testing
};

inline std::string Data::get(size_t idx) const
{
	return *d_data[idx];
}

#endif
