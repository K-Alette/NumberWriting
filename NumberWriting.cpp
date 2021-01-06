//This program converts integers in
//number format to worded format
//Kodi Lein
//SDEV340-81
#include <iostream>
using namespace std;

//**NUMBERS CLASS**//
class Numbers
{
private:
	int number;

public:
	Numbers(int num) { number = num; }; //constructor

	//static strings for arrays
	static string under20[];
	static string tens[];
	static string hundred[];
	static string thousand[];

	//function template
	void print();
};

//**ARRAYS**//
// "" marks empy slot in array to account for 0 values - i.e. 20 = "twenty" not "twenty zero"
string Numbers::under20[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight",
							"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
							"sixteen", "seventeen", "eighteen", "nineteen" };

string Numbers::tens[] = { "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string Numbers::hundred[] = { "hundred" };

string Numbers::thousand[] = { "thousand" };

//**PRINT FUNCTION**//
void Numbers::print()
{
	if (number >= 1 && number < 20) //for 1-19
	{
		cout << under20[number];
	}
	if (number >= 20 && number < 100) //for 20-99
	{
		cout << tens[(number/10)] << " " << under20[(number %10)];
	}
	if (number >= 100 && number < 1000) //for 100-999
	{
		cout << under20[(number / 100)] << " " << hundred[0] << " " << tens[((number %100)/10)-1] << " " << under20[(number %10)];
		number = number % 100;
	}
	if (number >= 1000 && number < 10000) //for 1000-9999
	{
		cout << under20[number / 1000] << " " << thousand[0] << " " << under20[((number %1000)/100)] << " " << hundred[0] << " " 
			<< tens[((number %100)/10)-1] << " " << under20[(number %10)];
	}
	else if (number == 0) //special case for zero, will not call to array. word "zero" not included in any other number but 0 alone
	{
		cout << "zero";
	}
};

 //**MAIN**//
int main()
{
	//define variable
	int number;

	//user enters number
	cout << "Enter an integer (no commas): ";
	cin >> number;

	//for numbers 0-9999 only
	if (number >= 0 && number < 10000)
	{
		Numbers n(number);
		n.print();
	}
	//program will terminate if invalid input is entered
	else
	{
		cout << "Only numbers 0-9999 accepted.";
	}

	return 0;
}