#include <iostream>
#include <string>
#include <stack>

using namespace std;


// MY APPROACH:
bool isValid(const string& code)
{
    // determine if the input code is valid
    
    stack<char> charStack;
    
    for (size_t i = 0; i < code.length(); i++)
    {
        switch (code[i])
        {
            case '(':
                charStack.push('(');
                break;
            case '[':
                charStack.push('[');
                break;
            case '{':
                charStack.push('{');
                break;
            case ')':
                if (charStack.empty() || charStack.top() != '(')
                {
                    return false;
                }
                else
                {
                    charStack.pop();
                }
                break;
            case ']':
                if (charStack.empty() || charStack.top() != '[')
                {
                    return false;
                }
                else
                {
                    charStack.pop();    
                }
                break;
            case '}':
                if (charStack.empty() || charStack.top() != '{')
                {
                    return false;
                }
                else
                {
                    charStack.pop();
                }
                break;
        }
    }
    
    if (charStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }

}


// CAKE APPROACH:
bool isValid(const string& code)
{
    unordered_map<char, char> openersToClosers {
        make_pair('(', ')'),
        make_pair('[', ']'),
        make_pair('{', '}')
    };

    unordered_set<char> closers {
        ')', ']', '}'
    };

    stack<char> openersStack;

    for (char c : code) {
        if (openersToClosers.find(c) != openersToClosers.end()) {
            openersStack.push(c);
        }
        else if (closers.find(c) != closers.end()) {
            if (openersStack.empty()) {
                return false;
            }
            else {
                char lastUnclosedOpener = openersStack.top();
                openersStack.pop();

                // if this closer doesn't correspond to the most recently
                // seen unclosed opener, short-circuit, returning false
                if (openersToClosers[lastUnclosedOpener] != c) {
                    return false;
                }
            }
        }
    }

    return openersStack.empty();
}