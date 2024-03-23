//---------------------------------------------------------------------------------------------------------------------
// a1.c
//
// This program implements a word guessing game where the player has to guess a word letter by letter.
// The player has a limited number of attempts to guess the word correctly. After each guess, the program
// provides feedback to the player, indicating if the guessed letters are correct or not. The game
// continues until the player either guesses the word correctly or runs out of attempts. The program
// tracks the game state and displays appropriate messages throughout the game.
//
// Group:
//
// Author: 12039183
//---------------------------------------------------------------------------------------------------------------------
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTEMPTS_NUMBER 5
#define INTIAL_WORD_MESSAGE "Word to look for:\n > "
#define LETTER_MESSAGE "Enter a letter:\n > "
#define ATTEMPTS_MESSAGE "Attempts left: %d\n"
#define DUBLICATED_MESSAGE "Letter %c was used already!\n"
#define CONGRATULATING_MESSAGE "Congratulations, you won!\n"
#define LOOSING_MESSAGE "LOST! The Word was %s\n"

//---------------------------------------------------------------------------------------------------------------------
///
/// Counts the number of words in the input string.
///
/// @param input The input string to count words from.
///
/// @return The number of words in the input string.
//
int countWords(const char *input)
{
    char copy[20];
    strcpy(copy, input);
    int word_counter = 0;
    char *token = strtok(copy, " \t\n"); // Tokenize using space, tab, and newline
    while (token != NULL)
    {
        word_counter++;
        token = strtok(NULL, " \t\n");
    }
    return word_counter;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// Checks if a character has been repeated in the letters array and removes it.
///
/// @param check The character to check.
/// @param letters Pointer to the string containing letters.
///
/// @return 1 if the character is found and removed, 0 otherwise.
//
int checkRepeatedChar(char check, char **letters)
{
    size_t word_length = strlen(*letters);
    for (int i = 0; (*letters)[i]; i++)
    {
        if (toupper((*letters)[i]) == toupper(check))
        {
            memmove(&((*letters)[i]), &((*letters)[i + 1]), word_length - i);
            (*letters)[word_length - 1] = '\0'; // Null-terminate the string
            return 1;
        }
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// Prints the guessed letters.
///
/// @param guessed_letters The string containing guessed letters.
//
void printGuessedLetters(const char *guessed_letters)
{
    for (size_t i = 0; i < strlen(guessed_letters); i++)
    {
        printf("%c ", toupper(guessed_letters[i]));
    }
    printf("\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// Initializes the game with the initial word and guessed letters.
///
/// @param initial_word The initial word to be guessed.
/// @param guessed_letters The array containing guessed letters.
///
/// @return 0 if initialization succeeds, 1 otherwise.
//
int initializeGame(char *intial_word, char *guessed_letters)
{
    printf(INTIAL_WORD_MESSAGE);
    fgets(intial_word, 20, stdin);
    if (!countWords(intial_word))
    {
        return 1;
    }
    intial_word[strcspn(intial_word, "\n")] = '\0'; // Remove newline character
    for (size_t i = 0; i < strlen(intial_word); i++)
    {
        intial_word[i] = toupper(intial_word[i]);
        guessed_letters[i] = '_';
    }
    guessed_letters[strlen(intial_word)] = '\0'; // Null-terminate the string
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// Runs the main game loop.
///
/// @param initial_word The initial word to be guessed.
/// @param guessed_letters The array containing guessed letters.
/// @param letters The array containing available letters.
///
/// @return 1 if the game is won, 0 if the game is lost.
//
int mainGame(char *intial_word, char *guessed_letters, char *letters)
{
    int attempts_left = MAX_ATTEMPTS_NUMBER;
    char letter[20];
    int found_flag;
    int all_guessed_flag;

    printf(ATTEMPTS_MESSAGE, attempts_left);
    printf(LETTER_MESSAGE);
    while (attempts_left > 0)
    {
        fgets(letter, sizeof(letter), stdin);
        if (!countWords(letter))
        {
            return 1;
        }
        letter[strcspn(letter, "\n")] = '\0'; // Remove newline character
        int repeated_flag = 0;
        // if (!checkRepeatedChar(letter, &letters))
        // {
        //     printf(DUBLICATED_MESSAGE, toupper(letter[0]));
        //     repeated_flag = 1;
        // }
        found_flag = 0;
        for (size_t j = 0; j < strlen(letter); j++)
        {
            if (!checkRepeatedChar(letter[j], &letters))
            {
                printf(DUBLICATED_MESSAGE, toupper(letter[j]));
                repeated_flag = 1;
            }
            for (size_t i = 0; i < strlen(intial_word); i++)
            {
                if (intial_word[i] == toupper(letter[j]))
                {
                    guessed_letters[i] = letter[j];
                    found_flag = 1;
                }
            }
            if (!repeated_flag)
            {
                printGuessedLetters(guessed_letters);
                if (!found_flag)
                {
                    attempts_left--;
                }
            }
            all_guessed_flag = 1;
            for (size_t i = 0; i < strlen(intial_word); i++)
            {
                if (guessed_letters[i] == '_')
                {
                    all_guessed_flag = 0;
                    break;
                }
            }
            if (!all_guessed_flag && attempts_left != 0)
            {
                printf(ATTEMPTS_MESSAGE, attempts_left);
                printf(LETTER_MESSAGE);
            }
        }
        if (all_guessed_flag)
        {
            printf(CONGRATULATING_MESSAGE);
            return 1; // Won
        }
    }
    printf(LOOSING_MESSAGE, intial_word);
    return 0; // Lost
}

//---------------------------------------------------------------------------------------------------------------------
///
/// The main function and the entry point of the program.
/// If the intializeGame function returns 1 it means the user entered 0 words then terminate the programm.
/// @return 0 if the program execution completes successfully.
//
int main()
{
    char intial_word[20];
    char guessed_letters[20];
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (initializeGame(intial_word, guessed_letters))
    {
        return 0;
    }
    if (mainGame(intial_word, guessed_letters, letters))
    {
        return 0;
    }
    return 0;
}
