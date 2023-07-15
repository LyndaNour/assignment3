#ifndef INFOX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_

#include"Syntax_Error.h"
#include<string>


#ifdef USEKW
#include "stack.h" //for kw::stack
#else
#include<stack>
#endif 

/** Class to convert infix expressions to postfix expressions */

class Infix_To_Postfix {
public:

/**extracts and processes each token in infix and returns the equivalent postfix string 
*@param expression The infix expression
*@return the equivalent postfix expression
* @throws syntax_error
*/
	std::string convert(const std::string& expression);

private:
/**function to process operators
@param op the operator
@throws syntax_error
*/
	void process_operator(char op);

/**determine whether a character is an operator
@param ch The character to be tested
@return true if the character is an operator
*/

	bool is_operator(char ch) const
	{
		return OPERATORS.find(ch) != std::string::npos;
	}

/**Determines the precedence of an operator
@param op The operator
@return The precedence
*/

	int precedence(char op) const
	{
		return PRECEDENCE[OPERATORS.find(op)];
	}

	//data fields
	static const std::string OPERATORS;
	static const int PRECEDENCE[];
#ifdef USEKW
	kw::stack<char> operator_stack;
#else
	std::stack<char>operator_stack;
#endif
	std::string postfix;

};

#endif
