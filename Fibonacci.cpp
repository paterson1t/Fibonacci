//Program designed to find the fibonnaci number at
//a given position, n, provided by the user
//Author:Peter Paterson
//Date:4-10-2017

#include "stdafx.h"
#include <iostream>      //includes cout, cin and other standerd c++ values
#include <stack>        //includes functions for stack operations


using namespace std;



int main()
{
	std::stack <int> f1, f2, f3, output, output2, result; //creates four stacks for nessecarry addition with large numbers

	int n;
	cout << "Please enter the position number in the fibonacci sequence " << endl; //take input to find which position number user wants in fibonacci sequence
	cin >> n;


	f1.push(0);			 //set inital value for first stack to 0
	f2.push(1);          //set initial value for second stack to 1     
	int x, y, sum, c = 0;       //create four variables x, y, sum, and c
	x = 0;
	y = 0;
	sum = 0;
	if (n == 0 || n == 1)
		cout << "the fibonacci number at position " << n << " is " << 1 << endl;

	else

		for (int i = 2; i <= n; i++)        //for loop loops untill the number n is reached
		{




			while (!f1.empty() || !f2.empty())      // checks to see if stack f1 and stack f2 are empty
			{

				if (!f1.empty())
				{

					x = f1.top();      //sets x to the top value of stack f1
					f1.pop();           //pops the first value of stack f1

				}
				else
				{
					x = 0;            //if there is no value in stack f1, sets x to be 0
				}
				if (!f2.empty())
				{
					y = f2.top();          //sets the value y to be equal to the top value in stack f2
					f3.push(f2.top());        //pushes the top value of stack 2 into another stack f3
					f2.pop();                  //pops the value of stack f2
				}
				else
				{
					y = 0;
				}
				sum = x + y + c;               //adds the three integers x, y, and c and stores them in sum
				output.push(sum % 10);

				if (sum >= 10)           // if sum is greater than or equal to 10, c is set to 1
				{
					c = 1;
				}
				else
				{
					c = 0;           //if sum is less than 10, c is set to 0
				}

				if (f1.empty() && f2.empty())         //if there is no values left in stack f1 and stack f2, pushes c into output stack
				{
					output.push(c);
					break;
				}
			}

			while (!f3.empty())       // pushes the values from stack f3 into stack f1
			{
				f1.push(f3.top());
				f3.pop();

			}
			if (i < n)
				while (!output.empty())          //pushes the value of output stack into f2, if i is not equal to n
				{
					f2.push(output.top());
					output.pop();
				}
			else
				break;



		}

	while (output.top() == 0)      //pops out unessecarry 0's at beggining of stack that acted as placeholders
		output.pop();


	cout << "the fibonacci number at position " << n << " is " << endl;
	while (!output.empty())                   //while the ouput stack has integers in it, ouputs the top nuber then pops that number from the stack
	{
		cout << output.top();
		output.pop();
	}

	cout << endl;

	return 0;

}
