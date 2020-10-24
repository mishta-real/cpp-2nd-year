#include "strings.hpp"

#include <stack> // std::stack
#include <string> // std::string
#include <queue> // std::queue

namespace Strings {

const bool is_palindrome( const char *string )
{
    std::stack<char> char_stack; // LIFO
    std::queue<char> char_queue; // FIFO

    for ( const char *elem = string; *elem != '\0'; ++elem ) {
        char_stack.push( *elem );
        char_queue.push( *elem );
    }

    while ( !char_stack.empty() && !char_queue.empty() ) {
        if ( char_stack.top() == char_queue.front() ) {
            char_stack.pop();
            char_queue.pop();
        }
        else {
            break;
        }
    }

    return char_stack.empty() && char_queue.empty();
}

const bool is_palindrome( const std::string &string )
{
    std::stack<char> char_stack; // LIFO
    std::queue<char> char_queue; // FIFO

    for ( const auto& elem : string ) {
        char_stack.push( elem );
        char_queue.push( elem );
    }

    while ( !char_stack.empty() && !char_queue.empty() ) {
        if ( char_stack.top() == char_queue.front() ) {
            char_stack.pop();
            char_queue.pop();
        }
        else {
            break;
        }
    }

    return char_stack.empty() && char_queue.empty();
}


const bool braces_valid( const char *string )
{
    std::stack<char> brace_stack;

    for ( const char *elem = string; *elem != '\0'; ++elem ) {
        if ( *elem != '(' && *elem != '{' && *elem != '[' ) {
            if ( *elem != ')' && *elem != '}' && *elem != ']' ) {
                continue;
            }
            else if ( (*elem == ')' && brace_stack.top() == '(') ||
                    (*elem == '}' && brace_stack.top() == '{') ||
                    (*elem == ']' && brace_stack.top() == '[') ) {
                // Pop the valid opening brace:
                brace_stack.pop();
            }
            // Closing brace goes before the opening one or they do not match:
            else {
                return false;
            }
        }
        else {
            // This will only push opening braces:
            brace_stack.push( *elem );
        }
    }
    // Check if there are no unclosed braces left:
    return brace_stack.empty();
}

const bool braces_valid( const std::string &string )
{
    std::stack<char> brace_stack;

    for ( const auto &elem : string ) {
        if ( elem != '(' && elem != '{' && elem != '[' ) {
            if ( elem != ')' && elem != '}' && elem != ']' ) {
                continue;
            }
            else if ( (elem == ')' && brace_stack.top() == '(') ||
                    (elem == '}' && brace_stack.top() == '{') ||
                    (elem == ']' && brace_stack.top() == '[') ) {
                // Pop the valid opening brace:
                brace_stack.pop();
            }
            // Closing brace goes before the opening one or they do not match:
            else {
                return false;
            }
        }
        else {
            // This will only push opening braces:
            brace_stack.push( elem );
        }
    }
    // Check if there are no unclosed braces left:
    return brace_stack.empty();
}


} // namespace Strings
