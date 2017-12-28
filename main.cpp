/***************************************
* Alex Phomthavong
* Programming Project 2 - Hangman
* Create a Hangman game to showcase what we learned
* Input = User guesses, ints and chars
* Output = Game answers, strings and chars
***************************************/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int GUESSES = 8;

int letterGuessed(char, string, string &);
int bomb(int);

int main()
{
    int wrongLetterTally = 0;
    int userAnswer;
    char letter;
    vector<char> wrongLetter(GUESSES);
    int wrongGuesses = 0;
    string word;

    srand( (unsigned)time(NULL) );

    /********************************
     *       Start of game
     *******************************/


    cout << "   ************************************************************\n"
         << "  ************************************************************\n"
         << " ************************************************************\n"
         << "************************************************************\n"
         << "*                                                  ********\n"
         << "*  ####  ####  #   #  #####  #     #  ####  #   #  *******\n"
         << "*  #  #  #  #  # # #  #      ##   ##  #  #  # # #  ******\n"
         << "*  ###   ####  #  ##  #  ##  #  #  #  ####  #  ##  *****\n"
         << "*  #  #  #  #  #   #  #   #  #     #  #  #  #   #  ****\n"
         << "*  ####  #  #  #   #  #####  #     #  #  #  #   #  ***\n"
         << "*                                                  **\n"
         << "****************************************************" << endl;

    ifstream infile;
    int SIZE = 20;
    vector<string> wordList(SIZE);
    infile.open("words.txt");


    if ( infile )
    {
        for ( int i = 0; i < SIZE; i++ )
        {
            infile >> wordList[i];
        }
    }

    cout << "\n\nWelcome to BANGMAN!\n"
         << "This game is a little different...\n"
         << "DO NOT LET THE FUSE REACH THE BOMB!!\n"
         << "\nEach #hashtag represents a letter.\n"
         << "You have " << GUESSES << " tries to guess the word.\n"
         << "Good Luck!\n"
         << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    do
    {
        int randomNumber = rand() % 20 + 1;
        word = wordList[randomNumber];

        string mysteryWord( word.length(), '#' );

        while ( wrongGuesses < GUESSES )
        {
            bomb(wrongGuesses);

            cout << "\n\n" << "Word: " << mysteryWord
                 << "\n\nGuess a letter: " << endl;

            cin  >> letter;

            wrongLetter[wrongLetterTally] = letter;

            if ( letterGuessed( letter, word, mysteryWord ) == 0 )
            {
                cout << "\n404 letter not found, try again"
                     << "\nIncorrect Guesses: " << letter << endl;

                for ( int i = 0; i < wrongLetterTally; i ++ )
                {
                    cout << wrongLetter[i] << " ";
                }
                wrongGuesses++;
                wrongLetterTally++;

                cout << "\nYou have " << GUESSES - wrongGuesses
                     << " guesses left." << endl;
            }
            else if ( letterGuessed( letter, word, mysteryWord ) != 0 && word == mysteryWord )
            {
                cout << "\nGood guess! Keep going!\n"
                     << "\nYou have " << GUESSES - wrongGuesses
                     << " guesses left." << endl;
            }
            if (word == mysteryWord)
            {
                cout << "Correct!\n"
                     << word << endl;
                break;
            }
            if ( wrongGuesses == GUESSES )
            {
                bomb(wrongGuesses);

                cout << "\nBetter luck next time!\n"
                << "The word was : " << word << endl;

                wrongGuesses = 0;
                break;
            }
        }

        cin.ignore();
        cin.get();

        cout << "Do you want to play again?\n"
             << "1. Yes\n"
             << "2. No";

        cin >> userAnswer;

        wrongLetter.clear();

    } while ( userAnswer == 1);
}


int letterGuessed( char guess, string wordFromFile, string &guessword )
{
    int matches = 0;

    for ( int i = 0; i < wordFromFile.length(); i++ )
    {
        if ( guess == guessword[i] )
        {
            return 0;
        }

        if ( guess == wordFromFile[i] )
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

int bomb(int wrongGuesses )
{
    switch(wrongGuesses)
    {
        case 0:
            cout << "______ \n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 1:
            cout << "*_____\n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 2:
            cout << "**____\n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 3:
            cout << "***___\n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 4:
            cout << "****__\n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 5:
            cout << "*****_\n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 6:
            cout << "*******\n"
                    "        \\\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 7:
            cout << "********\n"
                    "        *\n"
                    "         \\\n"
                    "       #####\n"
                    "       #####\n"
                    "       #TNT#\n"
                    "       #####\n"
                    "       #####\n"
                    "       #####" << endl;
            break;
        case 8:
            cout << "                            *\n"
                    "                           * *\n"
                    "              *           *   *\n"
                    "             * *         *     *\n"
                    "     *      *   *       *       *       *\n"
                    "    * *    *     *     *         *     * *\n"
                    "   *   *  *       *   *           *   *   *\n"
                    "  *     *          * *             * *     *\n"
                    " *                  *               *       *\n"
                    "*                                            *\n"
                    "*         ####   ####   ####   #     #  ##     *\n"
                    " *       #  #   #  #   #  #   ##  # #  ##     *\n"
                    "  *     ###    #  #   #  #   #  #  #  ##     *\n"
                    "   *   #  #   #  #   #  #   #     #        *\n"
                    "  *   ####   ####   ####   #     #  ##   *\n"
                    " *                                     *\n"
                    "  *                    *             *\n"
                    "    *     *     *     * *           *\n"
                    "     *   * *   * *   *   *     *     *\n"
                    "      * *   * *   * *     *   * *     *\n"
                    "       *     *     *       * *   *   *\n"
                    "                            *     * *\n"
                    "                                   *" << endl;
            break;
        default:
            break;
    }
}