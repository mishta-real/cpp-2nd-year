#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <algorithm> // std::any_of
#include <cctype> // std::isalpha(), std::tolower()
#include <stack> // std::stack
#include <string> // std::string
#include <queue> // std::queue

namespace Strings {

const bool is_palindrome(
        const char *string
) {
    std::stack<char> char_stack;
    std::queue<char> char_queue;

    for ( const char *elem = string; *elem != '\0'; ++elem ) {
        // Only add letters and digits to stack and queue
        if ( std::isalnum( *elem ) ) {
            if ( std::isupper( *elem ) ) {
                char_stack.push( std::tolower( *elem ) );
                char_queue.push( std::tolower( *elem ) );
            }
            else {
                char_stack.push( *elem );
                char_queue.push( *elem );
            }
        }
        else {
            continue;
        }
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

const bool is_palindrome(
        const std::string &string
) {
    std::stack<char> char_stack;
    std::queue<char> char_queue;

    for ( const auto& elem : string ) {
        // Only add letters and digits to stack and queue
        if ( std::isalnum( elem ) ) {
            if ( std::isupper( elem ) ) {
                char_stack.push( std::tolower( elem ) );
                char_queue.push( std::tolower( elem ) );
            }
            else {
                char_stack.push( elem );
                char_queue.push( elem );
            }
        }
        else {
            continue;
        }
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

const bool brackets_valid(
        const char *string
) {
    std::stack<char> bracket_stack;

    for ( const char *elem = string; *elem != '\0'; ++elem ) {
        if ( *elem != '(' && *elem != '{' && *elem != '[' ) {
            // Normal character
            if ( *elem != ')' && *elem != '}' && *elem != ']' ) {
                continue;
            }
            // Closing bracket goes before the opening one
            else if ( bracket_stack.empty() ) {
                return false;
            }
            // Correct pair
            else if ( (*elem == ')' && bracket_stack.top() == '(') ||
                    (*elem == '}' && bracket_stack.top() == '{') ||
                    (*elem == ']' && bracket_stack.top() == '[') ) {
                // Pop the valid opening brace:
                bracket_stack.pop();
            }
            // Brackets do not match or closing bracket goes before the opening one
            else {
                return false;
            }
        }
        else {
            // This will only push opening braces:
            bracket_stack.push( *elem );
        }
    }
    // Check if there are no unclosed braces left:
    return bracket_stack.empty();
}

const bool brackets_valid(
        const std::string &string
) {
    std::stack<char> bracket_stack;

    for ( const auto &elem : string ) {
        if ( elem != '(' && elem != '{' && elem != '[' ) {
            // Normal character
            if ( elem != ')' && elem != '}' && elem != ']' ) {
                continue;
            }
            // Closing bracket goes before the opening one
            else if ( bracket_stack.empty() ) {
                return false;
            }
            // Correct pair
            else if ( (elem == ')' && bracket_stack.top() == '(') ||
                    (elem == '}' && bracket_stack.top() == '{') ||
                    (elem == ']' && bracket_stack.top() == '[') ) {
                // Pop the valid opening brace:
                bracket_stack.pop();
            }
            // Brackets do not match or closing bracket goes before the opening one
            else {
                return false;
            }
        }
        else {
            // This will only push opening braces:
            bracket_stack.push( elem );
        }
    }
    // Check if there are no unclosed braces left:
    return bracket_stack.empty();
}

const bool has_brackets( const char *string )
{
    for ( const char *elem = string; *elem != '\0'; ++elem ) {
        if ( *elem == '(' || *elem == '{' || *elem == '[' ||
            *elem == ')' || *elem == '}' || *elem == ']' ) {
            return true;
        }
    }
    return false;
}

const bool has_brackets( const std::string &string )
{
    return std::any_of( string.begin(), string.end(), []( const auto &elem ){
        return
            elem == '(' || elem == '{' || elem == '[' ||
            elem == ')' || elem == '}' || elem == ']';
        }
    );
}

} // namespace Strings

#endif
