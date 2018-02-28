#ifndef INCLUDED_STORAGE_H_
#define INCLUDED_STORAGE_H_

#include <vector>
#include <iterator>

template <typename Data>
class Storage
{
	std::vector<Data *> d_storage;

	public:
		class iterator: public 
				std::iterator<std::random_access_iterator_tag, Data>
		{
			friend class Storage;

			typename std::vector<Data *>::iterator d_current;

			iterator(typename std::vector<Data *>::iterator const &current);

			public:
				iterator &operator++();
				iterator operator++(int);
				iterator &operator--();
				iterator operator--(int);

				iterator operator+(int step) const;
				iterator operator-(int step) const;
				int operator-(iterator const &rhs) const;
				
				bool operator==(iterator const &other) const;
				bool operator!=(iterator const &other) const;
				bool operator<(iterator const &other) const;
				
				Data &operator*() const;
				Data *operator->() const;
		};

		typedef std::reverse_iterator<iterator> reverse_iterator;

		Storage<Data>::iterator begin();
		Storage<Data>::iterator end();

		Storage<Data>::reverse_iterator rbegin();
		Storage<Data>::reverse_iterator rend();
};

	// implementations of member functions of Storage<Data>::iterator
template <typename Data>
inline Storage<Data>::iterator::iterator(
		 typename std::vector<Data *>::iterator const &current)
:
	d_current(current)
{}

template <typename Data>
inline typename Storage<Data>::iterator &
					Storage<Data>::iterator::operator++()
{
	++d_current;
	return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator 
					Storage<Data>::iterator::operator++(int)
{
	return iterator(d_current++);
}

template <typename Data>
inline typename Storage<Data>::iterator &
					Storage<Data>::iterator::operator--()
{
	--d_current;
	return *this;
}

template <typename Data>
inline typename Storage<Data>::iterator 
					Storage<Data>::iterator::operator--(int)
{
	return iterator(d_current--);
}

template <typename Data>
inline typename Storage<Data>::iterator 
					Storage<Data>::iterator::operator+(int step) const
{
	return iterator(d_current + step);
}

template <typename Data>
inline typename Storage<Data>::iterator 
					Storage<Data>::iterator::operator-(int step) const
{
	return iterator(d_current - step);
}

template <typename Data>
inline int Storage<Data>::iterator::operator-(iterator const &rhs) const
{
	return d_current - rhs.d_current;
}

template <typename Data>
inline bool Storage<Data>::iterator::operator==(iterator const &other) const
{
	return d_current == other.d_current;
}

template <typename Data>
inline bool Storage<Data>::iterator::operator!=(iterator const &other) const
{
	return d_current != other.d_current;
}

template <typename Data>
inline bool Storage<Data>::iterator::operator<(iterator const &other) const
{
	return d_current < other.d_current;
}

template <typename Data>
inline Data &Storage<Data>::iterator::operator*() const
{
	return **d_current;
}

template <typename Data>
inline Data *Storage<Data>::iterator::operator->() const
{
	return *d_current;
}

	// implementations of member functions of Storage<Data>
template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::begin()
{
	return iterator(d_storage.begin());
}

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::end()
{
	return iterator(d_storage.end());
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
	return reverse_iterator(d_storage.end());
}

template <typename Data>
inline typename Storage<Data>::reverse_iterator Storage<Data>::rend()
{
	return reverse_iterator(d_storage.begin());
}

#endif