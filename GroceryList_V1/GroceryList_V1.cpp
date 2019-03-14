/* GroceryList_V1 : This file contains the 'main' function. Program execution begins and ends there.
*
*Author: Shaqueir Tardif
*Date: 03/14/2019
*Name: GroceryList_V1
*IDE: Visual Studio Community 2017
*
*This program has been created in an effor to educate viewers within some of the techniques
*that can be enabled to execute a type of list from user input along with some other basic
*refreshers within the C++ language.
*/

#include "pch.h" // default header file for Visual Studio Community 2017
// used for pre-compiled headers

#include <iostream> //input/output stream
#include <string> //string header
#include <fstream> // Stream class to both read and write from/to files
#include <vector>

/* Will need these types to write and read to/from files */
//<ofstream> //Stream class to write to files
//<ifstream> //Stream class to read from files

using namespace std; //need this line to use cout and endl w/o "std::"

int main()
{

	string name;
	cout << "What is your first name?" << endl;
	cin >> name; //if user inputs 2 words, the second work will execute the next cin command
	cout << "Hello " << name << endl;

	char food[50]; //allows user to enter a max of 50 characters for an input
	string grpfoods;
	cout << "What is your favorite food?\n";
	cin.ignore(); //cin identifies newlines after execution.. so getline would determine the user is hitting enter when they actually aren't
				  //cin.ignore() tells getline to ignore the previous empty lines
	cin.getline(food, sizeof(food)); /* works to copy whole line (includes spaces)
										disabled as soon as user hits [Enter] */
	cout << "You've entered: " << food << endl;


	/*Save previous response to the proper text file*/
	ofstream file1;
	file1.open("myGroceryList.txt");
	if (file1.is_open()) { //if file is opened (error check)
		file1 << name << "'s Grocery List\n" << endl;
		file1 << "You're favorite food is " << food << endl;
		//file1 << "Here is a list of your groceries: \n\n";
		file1.close(); // always close a file after you've opened it (rule of thumb)
	}


	cout << "You're response has been saved to a text file entitled 'myGroceryList.txt'\n\n";
	cout << "Interesting, my favorite food is pancakes!!\n\n";

	/*Start Grocery List*/
	cout << "List the food you need to shop for: Press [Enter] to complete an entry;  Enter '*' to stop entering.\n";
	//cin.ignore();

	vector<string> foodList;
	while (grpfoods != "*")
	{
		cin >> grpfoods;
		foodList.push_back(grpfoods);
	}

	cout << "Here is your list: \n" << endl;

	file1.open("myGroceryList.txt", fstream::app); /*open file in append mode (add to file
															without overwriting what's already there)*/
	if (file1.is_open()) { //if file is opened (error check)
		file1 << "\nHere is a list of your groceries: \n\n";
		file1.close();
	}

	if (grpfoods == "*") //once user has decided to no longer add to the list
	{
		//for (int i = 0; i < (foodList.size() + 1); i++) { //outputted an error since adding +1 to foodList.size()
															//will have made the vector out of bounds

															//ALSO, use size_t instead of using int in order to
															//to prevent "signed/unsigned mismatch warnings"
		for (size_t i = 0; i < (foodList.size() - 1); i++) {
			cout << "\t" << foodList[i] << endl;

			file1.open("myGroceryList.txt", fstream::app); /*open file in append mode (add to file
															without overwriting what's already there)*/
			if (file1.is_open()) { //if file is opened (error check)
				file1 << "\t\t" << foodList[i] << endl;
				file1.close(); // always close a file after you've opened it (rule of thumb)
			}
		}
	}

	cout << "\n\nYou're list has also been saved to the text file 'myGroceryList.txt'\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
