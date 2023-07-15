#ifndef _BALANCE_H_
#define _BALANCE_H_
#include<stack>
#include <string>
// the set of opening par

const std::string OPEN = "([{";
// the correspending set of closing par
const std::string CLOSE = ")]}";

/** function to determine whether a char is one of the opening parantheses defined in const OPEN
@param ch character to be tested
@return true if the character is an opening paranthesis
*/

bool is_open(char ch)
{
	return OPEN.find(ch) != std::string::npos;

}

/** function to determine whether a char is one of the closing parantheses defined in const OPEN
@param ch character to be tested
@return true if the character is a closing paranthesis
*/

bool is_close(char ch)
{
	return CLOSE.find(ch) != std::string::npos;
}

/**Test the input string to see that it contains balanced parantheses. This function tests an input string to see that each type of paranthesis is balanced
* @param expression is a string containing the expression to be examined
* @return true if all paranthesis match
 */

bool is_balanced(const std::string& expression)
{
	// A stack for the open parantheses that haven't been matched
	std::stack<char> s;
	bool balanced = true;
	std::string::const_iterator iter = expression.begin();
	while (balanced && (iter != expression.end()))
	{
		char next_ch = *iter;
		if (is_open(next_ch))
		{
			s.push(next_ch);
		}
		else if (is_close(next_ch))
		{
			if (s.empty())
			{
				balanced = false;
			}
			else
			{
				char top_ch = s.top();
				s.pop();
				balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		++iter;
	}
	return balanced && s.empty();
}



#endif
