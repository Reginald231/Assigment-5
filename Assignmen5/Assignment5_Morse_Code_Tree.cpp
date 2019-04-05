#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <array>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include <vector>


using namespace std;


//The array is filled with the alphabet in the format of the morse code tree, so the characters do not go in alphabetical order.
static string tree[31] = {"", "e", "t", "i", "a", "n", "m", "s", "u", "r", "w", "d", "k", "g", "o", "h", "v", "f",
                "", "l", "", "p", "j", "b", "x", "c", "y", "z", "q", "", ""};


 //The full array of morse code characters from a to z.
 //The array was built in the format of the morse code tree, so the characters do not go in alphabetical order.
static string morse[31] = {"", ".", "-", ". .", ". -", "- .", "- -", ". . .", ". . -", ". - .", ". - -",  "- . .",
                           "- . -", "- - .", "- - -", ". . . .", ". . . -", ". . - .", "", ". - . .", "", ". - - .", ". - - -",
                           "- . . .", "- . . -", "- . - .", "- . - -", "- - . .", "- - . -", "",""};


static void to_lowercase(string &message) {//Converting a string to lowercase.

    int i = 0;
    char c;
    {
        while (message[i]) {//In C++, you can parse a string as an array.
             c = message[i];
            tolower(c);//Built in function for converting a character to a lowercase letter.
            i++;
        }
    }
}



string morseString(string message){//Need to remember. The morse code tree contains left nodes which equal dots, and right nodes equal dashes.

    string translation;

    for(char &c: message){

        for(int i = 0; i < 31;i++){

//            if(c == (tree[(i-1)/2])[0]){
//            translation += tree[(i-1)/2];
//            }

            if (c == (tree [(2*i)+1])[0]){//Left
                translation += morse[(2*i)+1] + "   ";
            }

            else if (c == (tree[(2 * i)+2])[0]){//Right
                translation += morse[(2 * i) + 2] + "   " ;
            }
            else{
                continue;
            }
        }
    }

    return translation;

}


string englishString(vector<string> message){//Need to remember. The morse code tree contains left nodes which equal dots, and right nodes equal dashes.

    string translation;

    for(int k = 0; k < message.size(); k++){

        if (message[k] == "/"){
            translation += " ";
            continue;
        }

        for(int i = 0; i < 31;i++){


            if (message[k].compare((morse[(2*i)+1])) == 0){//Left
                translation += tree[(2*i)+1]; //Traversing a tree, moving to the right node is (2i)+1
            }

            else if (message[k].compare((morse[(2*i)+2])) == 0){//Right
                translation += tree[((2 * i) + 2)];//Traversing a tree, moving to the left node is (2i)+2
            }


            else{
                continue;
            }
        }
    }

    return translation;

}

int main() {


    //Initial prompt to the user when the code is run.
    cout << "This program can translate morse code to english or english to morse code." << endl;
    cout << "Enter E if you want to translate from morse code to English." << endl;
    cout << "Enter M if you want to translate from English to morse code." << endl;


    char c;

    cin >> c;

    //Converting english to morse code.
    if(c == 'M' || c == 'm'){

        string message;
        cin >> message;
        to_lowercase(message);
        cout << "Here is your message in morse code: " << endl;
        cout <<  "''" << morseString(message) << "''" << endl;
    }

    //Converting from morse code to english.
    if(c == 'E' || c == 'e'){
        vector<string> morse;
        string input;

        cout << "Begin entering the morse code message. " << endl;
        cout <<  "When you complete a morse character, press enter then begin the next." << endl;
        cout << "If you want to add a space between words, enter a \"/\" on a new line to enter a space." << endl;
        cout << "When you are done writing your message, enter \"done\" to complete the message." << endl;

        to_lowercase(input);//Function to convert a string to all lowercase letters

        while(input != "done"){
            getline(cin,input);//Pulls the entire line of input from the user.

            if(input != "done")//done is our sentinel value. "done" indicates the end of the message.
                morse.push_back(input);//Adds a value to the vector, a dynamic sized array.

            else
                continue;//Continue adding user input until they type "done."
        }

        string morseToEnglish = englishString(morse);//Translating from morse code to english.
        cout << "Here is your message in  english:\n" << morseToEnglish << endl;

    }
    return 0;

}