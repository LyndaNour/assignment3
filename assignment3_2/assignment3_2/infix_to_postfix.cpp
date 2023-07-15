/**implementation of infix_to_postfix */

#include"infix_to_postfix.h"
#include<sstream>
#include<cctype>
using std::string;
using std::istringstream;

const string Infix_To_Postfix::OPERATORS = "+-*/ ( )";  // add %
const int Infix_To_Postfix::PRECEDENCE[] = {1,1,2,2, -1, -1};

/**Extracts and processes each token in ifnix and returns the postfix string 
@param expression The infix expression
@return the equivalent postfix expression
@throws Syntax_Error
*/

string Infix_To_Postfix::convert(const string& expression)
{
	postfix = "";
	while (!operator_stack.empty())
		operator_stack.pop();
	istringstream infix_tokens(expression);
	string next_token;
	while (infix_tokens >> next_token) {
		if (isalnum(next_token[0]))
		{
			postfix += next_token;
			postfix += " ";
		}
		else if (is_operator(next_token[0]))
		{
			process_operator(next_token[0]);
		}
		else
		{
			throw Syntax_Error("unexpected character encountered ");
		}
	}//end while 
	//pop any remaining operators and append them to postfix

	while (!operator_stack.empty())
	{
		char op = operator_stack.top();
		operator_stack.pop();
		if (op == '(')
		{
			throw Syntax_Error("Unmatched open paranthesis");
		}
		postfix += op;
		postfix += " ";
	}
	return postfix;
}

/**function to process operators 
@param the operator
@throw syntax_error
*/

void Infix_To_Postfix::process_operator(char op)
{
	if (operator_stack.empty() || (op == '('))
	{
		if (op == ')')
			throw Syntax_Error("Unmatched close paranthesis");
		operator_stack.push(op);
	}
	
	else {
		if (precedence(op) > precedence(operator_stack.top())) 
		{
			operator_stack.push(op);
		}
		else {
			//pop all stack operators with equal or higher precedence than op
			while (!operator_stack.empty() && (operator_stack.top() !='(') 
				&& (precedence(op) <= precedence(operator_stack.top())))
			{
				postfix += operator_stack.top();
				postfix += " ";
				operator_stack.pop();
			}

			if (op == ')')
			{
				if (!operator_stack.empty() && (operator_stack.top() == '('))
				{
					operator_stack.pop();
				}
				else
				{
					throw Syntax_Error("Unmatched close parantheses");
				}
			}
			else
			{
				//assert: operator stack is empty or current operator precedence>top of the stack operaator
				operator_stack.push(op);
			}
		}
	}
}

