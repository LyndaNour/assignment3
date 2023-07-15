/**#include<stack>
#include<string>
#include<iostream>
//#include "balance.h"
#include "infix_to_postfix.h"
using namespace std;


/** main function to test is_balanced 
 int main()
{
	cout << "Enter an expression\n";
	string expression;
	while (getline(cin, expression) && (expression != " "))
	{
		cout << expression;
		if (is_balanced(expression))
		{
			cout << " is balanced\n";
		}
		else {
			cout << "is not balancedd\n ";
		}
		cout << "Enter another expression: ";
	}
	return 0;
}

int main()
{
	Infix_To_Postfix infix_to_postfix;
	cout << "Enter an expression to be converted \n";
	string expression;
	while (getline(cin, expression))
	{
		if (expression == "") break;

		try
		{
			string result = infix_to_postfix.convert(expression);
			cout << "== " << result << endl;
		}
		catch (Syntax_Error& ex)
		{
			cout << "Syntax error: " << ex.what() << endl;
		}
		cout << "Enter next expression: ";
	}

	return 0;
}*/