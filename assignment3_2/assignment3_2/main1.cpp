/**program to maintain a list */
#include<queue>
#include<string>
#include<iostream>
#include "balance.h"
#include "infix_to_postfix.h"
using namespace std;

/*perform the operations selected on the queue*/

int main()
{
	int part_choice;
	cout << " which program do you want to execute, enter 1 for program 1, 2 for program 2 and 3 for program 3: ";
	cin >> part_choice;

	if (part_choice == 1)
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
				cout << " is not balancedd\n ";
			}
			cout << "Enter another expression: ";
		}
	}
	else if (part_choice == 2)
	{
		Infix_To_Postfix infix_to_postfix;
		cout << "Enter an expression to be converted \n";
		string expression;
		while (getline(cin, expression))
		{
			if (expression == " ") break;

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
	}


	else if (part_choice == 3)
	{
		queue<string> customers;
		string name;
		int choice = 0;
		string choices[] = { "push", "front", "pop", "size", "quit" };
		const int NUM_CHOICES = 5;

		while (choice < NUM_CHOICES - 1)
		{
			//select the next operation

			cout << "Select an operation on costumer queue\n";
			for (int i = 0; i < NUM_CHOICES; i++)
			{
				cout << i << ": " << choices[i] << endl;
			}
			cin >> choice;
			switch (choice) {
			case 0:
				cout << "Enter new costumer name\n: ";
				cin >> name;
				customers.push(name);
				cout << " added to the line\n";
				break;

			case 1:
				cout << "customer" << customers.front() << " is next in line\n";
				break;

			case 2:
				cout << customers.front() << " removed from the line\n";
				customers.pop();
				break;


			case 3:
				cout << "Size of line is " << customers.size() << endl;
				break;

			case 4:
				cout << "leaving customer queue\n" << " number of customers in queue is " << customers.size() << endl;
				break;
			default:
				cout << "Invalid selection\n";
				break;
			}
		}//end while
	}
	return 0;

}