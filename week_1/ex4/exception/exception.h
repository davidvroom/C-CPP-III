// Type should have defined an operator+= for a std::string and Type
// A specialization is made for Type == int 

#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <exception>

class Exception: public std::exception
{
    template <typename Type>
    friend Exception &&operator<<(Exception &&in, Type const &txt);

    std::string d_what;         

    public:
        Exception() = default;

        char const *what() const noexcept(true) override;   
};

template <typename Type>
inline Exception &&operator<<(Exception &&in, Type const &txt)
{
    in.d_what += txt;
    return std::move(in);
}

template <>
inline Exception &&operator<<<int>(Exception &&in, int const &integer)
{
    in.d_what += std::to_string(integer);
    return std::move(in);
}

#endif
