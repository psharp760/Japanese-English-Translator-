#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=====================================================
// File scanner.cpp written by: Group Number: 8
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Howard Tep
// RE:   (([vowel] n | dwzyj | bmknhpr | t | c | s) 
bool word(string s)
{

    int state = 0;
    int charpos = 0;

    // replace the following todo the word dfa(vowel | vowel n | consonant vowel | etc......  **

       //where vowel = a,e,i,o,e,I, E    refer to Project-partA_w8A10A.doc for RE   
    while (s[charpos] != '\0')
    {
        if (state == 0) {
            char ch = s[charpos];//storing character
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;
            else if (ch == 'd' || ch == 'w' || ch == 'z' || ch == 'y' || ch == 'j')
                state = 5;
            else if (ch == 'b' || ch == 'm' || ch == 'k' || ch == 'n' || ch == 'h' || ch == 'p' || ch == 'r' || ch == 'g')
                state = 4;
            else if (ch == 't') state = 3;
            else if (ch == 'c') state = 2;
            else if (ch == 's') state = 1;
            else return false;
        }

        else if (state == 6) {
            char ch = s[charpos];//storing character
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;
            else if (ch == 'b' || ch == 'm' || ch == 'k' || ch == 'h' || ch == 'p' || ch == 'r' || ch == 'g')
                state = 4;
            else if (ch == 's')
                state = 1;
            else if (ch == 'c')
                state = 2;
            else if (ch == 'h')
                state = 4;
            else if (ch == 't')
                state = 3;
            else if (ch == 'n')
                state = 6;
            else if (ch == 'd' || ch == 'w' || ch == 'z' || ch == 'y' || ch == 'j')
                state = 5;
            else return false;
        }

        else if (state == 5) {
            char ch = s[charpos];//storing character
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;
            else return false;
        }

        else if (state == 4) {
            char ch = s[charpos];//storing character
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;
            else if (ch == 's') {
                state = 5;
            }

            else if (ch == 'y') {
                state = 5;
            }
            else return false;
        }

        else if (state == 3) {
            char ch = s[charpos];//storing character
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;
            else if (ch == 'y')
                state = 5;
            else if (ch == 's') {
                state = 6;
            }
            else return false;
        }

        else if (state == 2 && s[charpos] == 'h') {
            char ch = s[charpos];
            if (ch == 'h') {
                state = 5;
            }

            else return false;
        }

        else if (state == 1) {
            char ch = s[charpos];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;
            else if (ch == 'h')
                state = 5;
            else return false;
        }

        else if (state == 7) {
            char ch = s[charpos];//storing character
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'I' || ch == 'E')
                state = 6;

            else if (ch == 's') state = 1;
            else if (ch == 'c') state = 2;
            else if (ch == 't') state = 3;

            else if (ch == 'b' || ch == 'm' || ch == 'k' || ch == 'n' || ch == 'h' || ch == 'p' || ch == 'r' || ch == 'g')
                state = 4;

            else if (ch == 'd' || ch == 'w' || ch == 'z' || ch == 'y' || ch == 'j')
                state = 5;
            else return false;
        }

        charpos++;
    }//end of while

    // where did I end up????
    if (state == 0 || state == 7 || state == 6) return(true);  // end in a final state
    else return(false);

}

// PERIOD DFA 
// Done by: Peter Sharp
bool period(string s)
{
    if (s[0] == '.') {
        return true;
    }
    else {
        return false;
    }
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: Peter Sharp

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype { WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM, ERROR };
// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM", "ERROR" };

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
string reservedwords[20][2] = {
    "masu", "VERB",
    "masen", "VERBNEG",
    "mashita", "VERBPAST",
    "masendeshita", "VERBPASTNEG",
    "desu", "IS",
    "deshita", "WAS",
    "o", "OBJECT",
    "wa", "SUBJECT",
    "ni", "DESTINATION",
    "watashi", "PRONOUN",
    "anata", "PRONOUN",
    "kare", "PRONOUN",
    "kanojo", "PRONOUN",
    "sore", "PRONOUN",
    "mata", "CONNECTOR",
    "soshite", "CONNECTOR",
    "shikashi", "CONNECTOR",
    "dakara", "CONNECTOR",
    "eofm", "EOFM"
};

// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Peter Sharp & William Cerros 
int scanner(tokentype& tt, string& w)
{
    fin >> w;
    cout << "Scanner called using word: " << w << endl;

    //checking to see if we have a period first
    //checking to see if word is period first, since it is th easiest thing to check for
    if (period(w)) {
        tt = PERIOD;
    }

    else if (word(w)) {
        bool reserved = false;
        for (int i = 0; i < 20; i++) {
            if (w == reservedwords[i][0]) {
                if (reservedwords[i][1] == "VERB") {
                    tt = VERB;
                }
                else if (reservedwords[i][1] == "VERBNEG") {
                    tt = VERBNEG;
                }
                else if (reservedwords[i][1] == "VERBPAST") {
                    tt = VERBPAST;
                }
                else if (reservedwords[i][1] == "VERBPASTNEG") {
                    tt = VERBPASTNEG;
                }
                else if (reservedwords[i][1] == "IS") {
                    tt = IS;
                }
                else if (reservedwords[i][1] == "WAS") {
                    tt = WAS;
                }
                else if (reservedwords[i][1] == "OBJECT") {
                    tt = OBJECT;
                }
                else if (reservedwords[i][1] == "SUBJECT") {
                    tt = SUBJECT;
                }
                else if (reservedwords[i][1] == "DESTINATION") {
                    tt = DESTINATION;
                }
                else if (reservedwords[i][1] == "PRONOUN") {
                    tt = PRONOUN;
                }
                else if (reservedwords[i][1] == "CONNECTOR") {
                    tt = CONNECTOR;
                }
                else if (reservedwords[i][1] == "EOFM") {
                    tt = EOFM;
                }
                reserved = true;
                break;
            }
        }
        if (!reserved) {
            if (w[w.length() - 1] == 'I' || w[w.length() - 1] == 'E') {
                tt = WORD2;
            }
            else {
                tt = WORD1;
            }
        }
    }
    else if (w == "eofm") {
        tt = EOFM;
    }
    else {
        cout << "LEXICAL ERROR: " << w << " is not a valid token.\n";
        tt = ERROR;
    }
    return 0;

    // ** Grab the next word from the file via fin
    // 1. If it is eofm, return right now.   
    /*  **
    2. Call the token functions (word and period)
       one after another (if-then-else).
       Generate a lexical error message if both DFAs failed.
       Let the tokentype be ERROR in that case.
    3. If it was a word,
       check against the reservedwords list.
       If not reserved, tokentype is WORD1 or WORD2
       decided based on the last character.
    4. Return the token type & string  (pass by reference)
    */
}//the end of scanner

