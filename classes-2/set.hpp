#ifndef SET_HPP
#define SET_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

namespace Set {

template <typename T>
class Set;

template <typename T>
std::ostream &operator<<(
        std::ostream &t_ostream,
        const Set<T> &t_set
);

template <typename T>
bool is_type_valid( const T t_value );

/*
 * Class Set, based on std::vector.
*/
template <typename T>
class Set {

public:
    Set();
    explicit Set( const std::vector<T> &list );
    Set( const Set<T> &t_set );
    Set<T> &operator=( const Set<T> &t_set );

    ~Set();

    // Union
    Set<T> operator+( const Set<T> &t_set ) const;
    Set<T> unite( const Set<T> &t_set ) const;

    // Intersection
    Set<T> intersect( const Set<T> &t_set ) const;

    // Insertion
    void insert( const T t_value );
    // Insertion (std::cin)
    void insert();

    // Deletion
    void remove( const T t_value );
    // Deletion (std::cin)
    void remove();

    // Size getter
    size_t size() const;

    // Check if this set intersects with another set
    bool intersects( const Set<T> &t_set ) const;

    // Check if this set is a proper subset of another set
    bool is_proper_subset( const Set<T> &t_set ) const;

    // Check if this set is equal to another subset
    bool is_equal( const Set<T> &t_set ) const;

    // Check whether value is unique for the set
    bool is_unique( const T t_value ) const;

    // Check whether value is already present in the set
    bool is_present( const T t_value ) const;

    // Candidate validation
    friend bool is_type_valid<T>( const T t_value );

    // Output operator
    friend std::ostream &operator<< <T>(
        std::ostream &t_ostream,
        const Set<T> &t_set
    );

    // Make set sorted
    void sort();

private:
    std::vector<T> m_set;
}; // class Set

template <typename T>
Set<T>::Set()
{
    m_set.clear();
}


template <typename T>
Set<T>::Set( const std::vector<T> &list )
    : m_set{ list }
{
    sort();
}


template <typename T>
Set<T>::Set( const Set<T> &t_set )
    : m_set{ t_set.m_set }
{
    sort();
}

template <typename T>
Set<T> &Set<T>::operator=( const Set<T> &t_set )
{
    if ( this != &t_set ) {
        m_set = t_set.m_set;

        sort();
    }
    return *this;
}

template <typename T>
Set<T>::~Set()
{
}

// Union
template <typename T>
Set<T> Set<T>::operator+( const Set<T> &t_set ) const
{
    return unite( t_set );
}

// Union
template <typename T>
Set<T> Set<T>::unite( const Set<T> &t_set ) const
{
    Set<T> new_set = size() > t_set.size() ? *this : t_set;

    if ( size() > t_set.size() ) {
        for ( const T &elem : t_set.m_set ) {
            if ( !new_set.is_present( elem ) ) {
                new_set.insert( elem );
            }
        }
    }
    else {
        for ( const T &elem : m_set ) {
            if ( !new_set.is_present( elem ) ) {
                new_set.insert( elem );
            }
        }
    }

    return new_set;
}

// Intersection
template <typename T>
Set<T> Set<T>::intersect( const Set<T> &t_set ) const
{
    Set<T> new_set;

    if ( size() <= t_set.size() ) {
        for ( const T &elem : m_set ) {
            if ( t_set.is_present( elem ) ) {
                new_set.insert( elem );
            }
        }
    }
    else {
        for ( const T &elem : t_set.m_set ) {
            if ( is_present( elem ) ) {
                new_set.insert( elem );
            }
        }
    }

    return new_set;
}

// Insertion
template <typename T>
void Set<T>::insert( const T t_value )
{
    if ( is_type_valid( t_value ) && is_unique( t_value ) ) {
        m_set.push_back( t_value );
    }

    sort();
}

// Insertion (std::cin)
template <typename T>
void Set<T>::insert()
{
    T buf;
    std::cin >> buf;

    if ( !std::cin.fail() ) {
        insert( buf );
    }
    else {
        std::cerr << "Error occured while reading value." << std::endl;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }
}

// Deletion
template <typename T>
void Set<T>::remove( const T t_value )
{
    try {
        if ( is_present( t_value ) ) {
            m_set.erase(
                    std::remove( m_set.begin(), m_set.end(), t_value ),
                    m_set.end()
            );
            sort();
        }
        else {
            throw "value not found in set.";
        }
    } catch ( const char* exception ) {
        std::cerr
            << "Could not remove value " << t_value << ": "
            << exception
            << std::endl;
    }
}

// Deletion (std::cin)
template <typename T>
void Set<T>::remove()
{
    T buf;
    std::cin >> buf;

    if ( !std::cin.fail() ) {
        remove( buf );
    }
    else {
        std::cerr << "Error occured while reading value." << std::endl;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }
}

// Size getter
template <typename T>
size_t Set<T>::size() const
{
    return m_set.size();
}

// Check if this set intersects with another set
template <typename T>
bool Set<T>::intersects( const Set<T> &t_set ) const
{
    return std::any_of( m_set.begin(), m_set.end(), [&]( const T value ) {
            return t_set.is_present( value );
        }
    );
}

// Check if this set is a proper subset of another set
template <typename T>
bool Set<T>::is_proper_subset( const Set<T> &t_set ) const
{
    return std::all_of( m_set.begin(), m_set.end(), [&]( const T value ) {
            return t_set.is_present( value );
        }
    );
}

// Check if this set is equal to another set
template <typename T>
bool Set<T>::is_equal( const Set<T> &t_set ) const
{
    return size() == t_set.size() && is_proper_subset( t_set );
}

// Check whether value is unique for the set
template <typename T>
bool Set<T>::is_unique( const T t_value ) const
{
    return std::find( m_set.begin(), m_set.end(), t_value ) == m_set.end();
}

// Check whether value is already present in the set
template <typename T>
bool Set<T>::is_present( const T t_value ) const
{
    return std::find( m_set.begin(), m_set.end(), t_value ) != m_set.end();
}

// Candidate validation
template <typename T>
bool is_type_valid( const T t_value )
{
    return t_value % 3;
}

// Output operator
template <typename T>
std::ostream &operator<<( std::ostream &t_ostream, const Set<T> &t_set )
{
    t_ostream << "{ ";

    for ( auto it = t_set.m_set.begin(); it < t_set.m_set.end() - 1; ++it ) {
        t_ostream << *it << ", ";
    }

    t_ostream << *(t_set.m_set.end() - 1) << " }";

    return t_ostream;
}

// Make set sorted
template <typename T>
void Set<T>::sort()
{
    if ( !std::is_sorted( m_set.begin(), m_set.end() ) ) {
        std::sort( m_set.begin(), m_set.end() );
    }
}

} // namespace Set
#endif
