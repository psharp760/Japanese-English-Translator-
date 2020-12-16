#include<iostream>
#include<fstream>
#include<string>
#include <iterator> 
#include <map>
#include <sstream>


using namespace std;

/* INSTRUCTION:  copy your parser.cpp here
      cp ../ParserFiles/parser.cpp .
   Then, insert or append its contents into this file and edit.
   Complete all ** parts.
*/

//=================================================
// File translator.cpp written by Group Number: **
//=================================================

// ----- Additions to the parser.cpp ---------------------

// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt 
//  Done by: William Cerros

// Map will serve as our look up table
map<string, string> lexicon_dictionary;

void build_dictionary() {
    // input streamt to read from text file
    std::ifstream input_stream("lexicon.txt", std::ifstream::in);
    string word;
    
    int i;
    int j = 0;
    // for loop will iterate through each line in lexicon.txt
    for (string line; getline(input_stream, line); )
    {
         
        // istringstream object will help us parse the input
        istringstream ss(line);

        // This will be our dictionary pair
        string key;
        string value;

        // Counter to let us know if we are reading the fist or second word
        i = 0;

        // while a word exists in the line we are currently reading from text file
        while (ss >> word)
        {
            if (i == 0) {
                key = word;
            }

            if (i == 1) {
                value = word;

                // Once we have read in the value we can insert to our map
                lexicon_dictionary.insert(pair<string, string>(key, value));
            }

            i++;
        }
    }

    // printing out map to verify
    for (map<string, string>::const_iterator it = lexicon_dictionary.begin();
        it != lexicon_dictionary.end(); ++it)
    {
        std::cout << "Key: "<< it->first << " Value: " << it->second << " ""\n";
    }

}

// ** Additions to parser.cpp here:
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result   
//                 in saved_E_word
//  Done by: ** 
//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//  Done by: ** 

// ----- Changes to the parser.cpp content ---------------------

// ** Comment update: Be sure to put the corresponding grammar 
//    rule with semantic routine calls
//    above each non-terminal function 

// ** Each non-terminal function should be calling
//    getEword and/or gen now.


// ---------------- Driver ---------------------------

// The final test driver to start the translator
// Done by:  **
int main()
{
  //** opens the lexicon.txt file and reads it into Lexicon
  //** closes lexicon.txt 
  build_dictionary();

  //** opens the output file translated.txt

  cout << "Enter the input file name: ";
  //cin >> filename;
  //fin.open(filename.c_str());

  //** calls the <story> to start parsing

  //** closes the input file 
  //** closes traslated.txt
 
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions