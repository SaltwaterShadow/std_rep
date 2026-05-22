//CaesarCypherProject.cpp
#include <iostream>
#include <string>
using namespace std;
char rotate(unsigned char ch, int n); //function for moving char to the right in alphabet
string encipher(string str, int n);   //function for encoding a string
string decipher(string str);		  //function for decoding a string
double letterScore(char ch);		  //function for deciding which string is most likely to be correct

int main() //function to call other functions
{
	int operation; //to decide whether to encode or decode
	string input;  //to take input for string which will be encoded or decoded
	string encoded;//holds returned enciphered string
	string decoded;//holds returned deciphered string
	int shift;	   //keeps track of how far user wants cipher shifter (encode)
	
	//below takes input for which operation to perform
	do
	{
		cout << "To encode input '1', to decode input '2', to exit code '3': ";
	cin >> operation;
	}while((operation != 1)&&(operation != 2)&& (operation != 3));//do while vailidates input
	
	cin.ignore(); //get rid of newline charachter to allow code to accept the string input	
	
	
	switch(operation) //to take input & call requested functions, give output
	{
		case 1:
			cout << "Please input the string you want encoded: ";
			getline(cin, input);
			do //do while necessary for obtaining proper input 
			{
			cout << "How many letters would you like it shifted by (0-26): "; //allows them to go between not shifting and rotating back around, no further
			cin >> shift;
			}while((shift < 0)||(shift > 26));//do while validates input
			encoded = encipher(input, shift);//call and save encipher(string input, rotate by)
			cout << "The encoded string is: " << encoded << endl;//show results
			break;//don't do the next cases too
		case 2:
			cout << "Please input the string you want decoded: ";
			getline(cin, input);//call functions and save input
			decoded = decipher(input);
			cout << "The most likely decoded string is: " << decoded <<endl;//show results
			break; //don't do the next cases too
		case 3:
			cout << "Goodbye!";//kill program (friendly)
			return 0;
		default:
			cout << "Wrong input, try again!" << endl; //fail safe
	}
	main();	
}

char rotate(unsigned char ch, int n)
{
	if(ch >= 'a' && ch <= 'z') //determines if lowercase
	{	
		if(ch == 'z') //z wraps around to a
		{
			ch = 'a';
			ch += (n - 1); //1 is subtracted because of jump from z->a
		}
		else if((ch + n) > 'z') //something that would add to > z must wrap around past a 
		{
			int extra = (ch + n-1) - 'z'; //determines how far past z it goes (minus 1 because z-> a jump?)
			ch = 'a' + extra;		  //moves to correct place in alphabet
		}
		else //normal lowercase gets increased
		{
			ch += n;
		}
	}	
	if(ch >= 'A' && ch <= 'Z') //determines if uppercase
	{	
		if(ch == 'Z') //z wraps around to a
		{
			ch = 'A';
			ch += (n - 1); //minus 1 because z->a
		}
		else if((ch + n) > 'Z') //something that adds to > z must wrap around past a
		{
			int extra = (ch + n-1) - 'Z';
			cout << "extra =" << extra << endl; //determines how far past z it goes (minus 1 because z->a)
			ch = 'A' + extra;		  //adds extra to reach proper character in alphabet
		}
		else //normal uppercase gets increased
		{
			ch += n;
		}
	}	
	
	//if not uppercase or lowercase ch remains the same
	return ch; //sends updated char back to where it was called from
}

string encipher(string str, int n)
{
	string encoded; //holds encoded string to be returned
	for(int sofar = 0; sofar < str.length(); sofar++) //loop to move through the string
	{
		encoded += rotate((str[sofar]), n); //adds each newly encoded charachter to the return string
	}	
	return encoded; //returns string to function call for usage
}

string decipher(string str)
{
	double maxScore = 0; //holds current maximum score
	string maxOption;	  //holds whichever decoded string corresponds to the current maximum score 
	for(int sofar = 0;sofar <= 25; sofar++)
	{
		double score = 0; //holds the score (re-initializes to zero each time to get a NEW score)
		string option = encipher(str, sofar); //stores a potential decoded string
		for(int counter = 0; counter < str.length(); counter++)
		{
			
			score += letterScore(option[counter]); //calculates score for potential decoded string
			
		}
		if(score > maxScore) //if current score is greater than all previous
		{
			maxScore = score; //sets a new max_score
			maxOption = option;	//saves corresponding decoding
		}	
	}
	return maxOption; //returns highest scoring/most likely decoded string
}

double letterScore(char ch) //holds all letter values and assigns as necessary (given by assignment prompt)
{
	if (ch == 'A' || ch == 'a') return .0684;
	if (ch == 'B' || ch == 'b') return .0139;
	if (ch == 'C' || ch == 'c') return .0146;
	if (ch == 'D' || ch == 'd') return .0456;
	if (ch == 'E' || ch == 'e') return .1267;
	if (ch == 'F' || ch == 'f') return .0234;
	if (ch == 'G' || ch == 'g') return .0180;
	if (ch == 'H' || ch == 'h') return .0701;
	if (ch == 'I' || ch == 'i') return .0640;
	if (ch == 'J' || ch == 'j') return .0033;
	if (ch == 'K' || ch == 'k') return .0093;
	if (ch == 'L' || ch == 'l') return .0450;
	if (ch == 'M' || ch == 'm') return .0305;
	if (ch == 'N' || ch == 'n') return .0631;
	if (ch == 'O' || ch == 'o') return .0852;
	if (ch == 'P' || ch == 'p') return .0136;
	if (ch == 'Q' || ch == 'q') return .0004;
	if (ch == 'R' || ch == 'r') return .0534;
	if (ch == 'S' || ch == 's') return .0659;
	if (ch == 'T' || ch == 't') return .0850;
	if (ch == 'U' || ch == 'u') return .0325;
	if (ch == 'V' || ch == 'v') return .0084;
	if (ch == 'W' || ch == 'w') return .0271;
	if (ch == 'X' || ch == 'x') return .0007;
	if (ch == 'Y' || ch == 'y') return .0315;
	if (ch == 'Z' || ch == 'z') return .0004;
	return 0.0;
}

