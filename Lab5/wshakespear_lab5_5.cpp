#include <iostream>
#include <string>
#include <bits/stdc++.h>
using std::string;
using namespace std;

string ReverseSentence_WordsInPlace(string sentence);

int main()
{
    // Prompt the user for a string
    cout << "Please enter a sentence" << endl;
    cout << "  - The words will be reversed" << endl;
    cout << "  - The letters of the words will remain unchanged" << endl << endl;
    cout << "> ";

    string inputSentence;

    // Put the whole line into input sentence
    getline(cin, inputSentence);

    // Display the entered sentence
    cout << "You entered:    '" << inputSentence << "'" << endl;

    // Reverse the sentence with the function
    string reversed = ReverseSentence_WordsInPlace(inputSentence);

    cout << "Result:" << endl;

    cout << reversed << endl << endl;

    return 0;
}

string ReverseSentence_WordsInPlace(string sentence)
{
    // This will hold the current word
    char *buffer = new char(sentence.length());
    // This will hold the reversed word
    char *reversed = new char(sentence.length());
    // Current index for buffer array
    int buffer_index = 0;
    // Current index for reversed array
    int reversed_index = sentence.length();

    // Loop through the whole sentence
    for (int letter_i = 0; letter_i < sentence.length(); letter_i++)
    {
        // If the current char is not a space then add it to the buffer
        if (sentence[letter_i] != ' ')
        {
            // Add to the buffer and increment
            buffer[buffer_index++] = sentence[letter_i];
        
            // Unless it's the last character skip to the top of the loop
            if (letter_i + 1 != (int)sentence.length()) 
                continue;
        }

        // The current char is a space
        // If this is the first word in the buffer make the first char lower
        if (reversed_index == (int)sentence.length())
            buffer[0] = tolower(buffer[0]);

        // If this is that last word in the buffer make the first char upper
        if (letter_i == (int)sentence.length() - 1)
            buffer[0] = toupper(buffer[0]);

        // Loop through the buffer and fill out the reversed array
        for (int r = 0; r < buffer_index; r++)
            // Working from the reversed_index + r fill out the array
            reversed[reversed_index - buffer_index + r] = buffer[r];

        // Add the space into the reversed array
        reversed[reversed_index - buffer_index - 1] = ' ';
        // Update the reversed_index
        reversed_index -= buffer_index + 1;
        // Reset the buffer index
        buffer_index = 0; 
    }

    string return_string;
    return_string.assign(reversed, reversed + sentence.length());

    return return_string;

    
}
