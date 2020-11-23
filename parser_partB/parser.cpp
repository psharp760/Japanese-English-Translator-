#include<iostream>
#include<fstream>
#include<string>
#include "scanner.cpp"

using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: 8
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

string saved_lexeme;
tokentype saved_token;
bool token_available = false;
string choice;
ofstream errorfile;

enum parser_function {STORY, S, AFTER_SUBJECT, AFTER_NOUN, AFTER_OBJECT, VERB1, TENSE, NOUN, BE};
string parserName[30] = {"story", "s", "after_subject", "after_noun", "after_object", "verb1", "tense", "noun", "be"};

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: Match fails.
// Done by: Peter Sharp 
void syntaxerror1(tokentype expected){
    cout << "\nSYNTAX ERROR: expected " << tokenName[expected] << " but found " << saved_lexeme << endl;
}
// Type of error: switch default
// Done by: Peter Sharp 
void syntaxerror2(parser_function function) {
    cout << "\nSYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parserName[function] << endl;
    exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: Checks what token comes next from scanner.
// Done by: Peter Sharp
tokentype next_token() {
    if (!token_available) {
        scanner(saved_token, saved_lexeme);
        token_available = true;
    }
    return saved_token;
}

// Purpose: Checks if expected token is different from next_token()
// Done by: Peter Sharp
bool match(tokentype expected) {

    if (next_token() != expected) {
        syntaxerror1(expected);
        if (errorfile.is_open()) {
            errorfile << "\nSYNTAX ERROR: expected " << tokenName[expected] << " but found " << saved_lexeme << endl;
        }
        cout << "Skip or replace the token? (s or r)";
        cin >> choice;
        if (choice == "s") {
            token_available = false;
            match(expected);
        } else if (choice == "r") {
            token_available = false;
            cout << "Matched " << tokenName[expected] << endl;
        }
    } else {
        token_available = false;
        cout << "Matched " << tokenName[expected] << endl;
        return true;
    }
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

// Grammar: **
// Done by: **





//----------- Driver ---------------------------

string filename;

// The new test driver to start the parser
// Done by:  **
int main() {

    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());

    cout << "Do you want to trace error messages? (y or n)";
    cin >> choice;

    if (choice == "y") {
        errorfile.open("errors.txt", ios::app);
    }

    // story();
    errorfile.close();
    fin.close();

  //** calls the <story> to start parsing
  //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
