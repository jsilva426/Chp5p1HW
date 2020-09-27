// Jacob Silva
// chapter5p1HW.cpp 
//  9/27/2020


#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;
#include<string>
using std::string;
using std::tolower;
using std::getline;

#include <algorithm>
using std::for_each;


int main()
{
	bool done = false;
	string a = "";
	//To count how many times a letter appears
	float freq[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	// To check against frequency table
	//						a	b	c	  d		e     f   g    h    i    j  k   l    m	   n	O	p	q	 r	 s	  t		u	  v	   w    x    y   z   
	float compare[26] = { 8.12,1.49,2.71,4.32,12.02,2.30,2.03,5.92,7.31,.1,.69,3.98,2.61,6.95,7.68,1.82,.11,6.02,6.28,9.10,2.88,1.11,2.09,.17,2.11,.07};
	
	
	//Takes in a string

	cout << "Input A String: \n";
	getline(cin, a);
	
	//Begins to sanitize

	int length = a.length();

	for (int i = 0; i < length; i++) {
		
		//Converts to lower case

		a.at(i) = ::tolower(a.at(i));
		
		//removes whitespace (spaces)

		if (a.at(i) == ' ') {
			
			a.erase(i,1);
			--length;
			
		}
		
		

		//calculates freq
		//Recived help from https://www.tutorialspoint.com/cplusplus-program-to-find-the-frequency-of-a-character-in-a-string

		int letter;

		if (a.at(i) >= 'a' && a.at(i) <= 'z') {
			letter = a.at(i) - 'a';
			++freq[letter];
		}



	}
	//removes punctuation
	for (int i = 0; i < length; i++) {
		if (ispunct(a.at(i)) > 0) {

			a.erase(i, 1);
			--length;


		}
	}

	cout << "Sanatized string: " << a << endl;
	//Compares freqs
	cout<<"Comparing frequency"<<endl;
	for (int i = 0; i < 26; i++) {
		float calcFreq = (freq[i] / a.length()) * 100;
		float temp = calcFreq - compare[i];
		


		if (temp>5 || temp < -5) {
			

			cout << ">5% difference= "<<char(i + 'a') << " : " << temp << " %" << endl;

		}
		
	}
	
	
	cout << "Frequency of all letters in the string is:" << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << (freq[i]/a.length())*100<< " %" << endl;




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

