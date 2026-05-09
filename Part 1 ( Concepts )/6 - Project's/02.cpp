/*



String Library



*/

#include <iostream>
#include "clsString.h"
using namespace std;

int main()

{
    clsString String1;

    clsString String2("Islam");

    String1.SetValue("Raad");

    cout << "String1 = " << String1.GetValue() << endl;
    cout << "String2 = " << String2.GetValue() << endl;

    cout << "Number of words: " << String1.CountWords() << endl;

    cout << "Number of words: " << String1.CountWords("Im Student At University Of Mosul") << endl;

    cout << "Number of words: " << clsString::CountWords("Islam Raad Fahad Ali") << endl;

    //----------------
    clsString String3("Hi How Are You");

    cout << "String 3 = " << String3.GetValue() << endl;

    cout << "String Length = " << String3.Length() << endl;

    String3.UpperFirstLetterOfEachWord();
    cout << String3.GetValue() << endl;

    //----------------

    String3.LowerFirstLetterOfEachWord();
    cout << String3.GetValue() << endl;

    //----------------

    String3.UpperAllString();
    cout << String3.GetValue() << endl;

    //----------------

    String3.LowerAllString();
    cout << String3.GetValue() << endl;

    //----------------

    cout << "After inverting a : "
         << clsString::InvertLetterCase('a') << endl;

    //----------------

    String3.SetValue("AbCdEfg");

    String3.InvertAllLettersCase();
    cout << String3.GetValue() << endl;

    String3.InvertAllLettersCase();
    cout << String3.GetValue() << endl;

    //----------------

    cout << "Capital Letters count : "
         << clsString::CountLetters("Islam Abu-Hadhoud", clsString::CapitalLetters)
         << endl
         << endl;

    //----------------

    String3.SetValue("Welcome to Jordan");
    cout << String3.GetValue() << endl;

    cout << "Capital Letters count :" << String3.CountCapitalLetters() << endl;

    //----------------

    cout << "Small Letters count :" << String3.CountSmallLetters() << endl;

    //----------------

    cout << "vowels count :" << String3.CountVowels() << endl;

    //----------------

    cout << "letter E count :" << String3.CountSpecificLetter('E', false) << endl;

    //----------------

    cout << "is letter u vowel? " << clsString::IsVowel('a')
         << endl;

    //----------------

    cout << "Words Count" << String3.CountWords()
         << endl;

    //----------------

    vector<string> vString;

    vString = String3.Split(" ");

    cout << "\nTokens = " << vString.size() << endl;

    for (string &s : vString)
    {
        cout << s << endl;
    }

    //----------------

    // Tirms
    String3.SetValue("    Islam Raad Fathi     ");
    cout << "\nString     = " << String3.GetValue();

    String3.SetValue("    Islam Raad Fathi     ");
    String3.TrimLeft();
    cout << "\n\nTrim Left  = " << String3.GetValue();

    //----------------

    String3.SetValue("    Islam Raad Fathi     ");
    String3.TrimRight();
    cout << "\nTrim Right = " << String3.GetValue();

    //----------------

    String3.SetValue("    Islam Raad Fathi     ");
    String3.Trim();
    cout << "\nTrim       = " << String3.GetValue();

    //----------------

    // Joins
    vector<string> vString1 = {"Islam", "Faid", "Ali", "Maher"};

    cout << "\n\nJoin String From Vector: \n";
    cout << clsString::JoinString(vString1, " ");

    string arrString[] = {"Islam", "Faid", "Ali", "Maher"};

    cout << "\n\nJoin String From array: \n";
    cout << clsString::JoinString(arrString, 4, " ");

    //----------------

    String3.SetValue("Islam Raad Fathi");
    cout << "\n\nString     = " << String3.GetValue();

    String3.ReverseWordsInString();
    cout << "\nReverse Words : " << String3.GetValue()
         << endl;

    //---------------

    String3.SetValue("Islam Raad Fathi");
    cout << "\nReplace : " << String3.ReplaceWord("Islam", "Sari")
         << endl;

    //---------------

    String3.SetValue("This is: a sample text, with punctuations.");
    cout << "\n\nString     = " << String3.GetValue();

    String3.RemovePunctuations();
    cout << "\nRemove Punctuations : " << String3.GetValue()
         << endl;

    //---------------

    return 0;
};
