# Hangman

## Learning Goals

Data types, Operators, Branches, Loops, Input/Output, Functions, Constants, Arrays, (a bit of) ASCII

---

## ESP Hangman

This is all about the little Game _Hangman_.
This is structured into these three main parts:

- Start of the Game
- Gameplay
- End of the Game

## Description

### Hangman

In Hangman there are at least two players where one thinks of a word and the other(s) try to guess it by suggesting letters. The player(s) only have a limited number of available guesses. When the player(s) do not have any guesses left, they loose the game and win if the word was found before that.

### Starting the Game

A round is initiated by having one of the players choose the secret word.
In the ESP Hangman the progam starts with the prompt `Word to look for: ` and waits for the user to input a word with a maximal length of 19 characters.

```
Word to look for:
>
```

### Gameplay

Now the Player starts to guess.
The player has 5 attempts to find the correct word. The remaining Attempts are shown at the beginning of every move.

If the guess was **correct**, the attempts remain the same and the letter gets inserted at the corresponding postion(s) of the word. If it was a **wrong** guess, you loose one attempt.

A simple example without wrong inputs would be this (mind the space before the input prompt _ > _):

```
Word to look for:
 > ESP
Attempts left: 5
Enter a letter:
 > E
E _ _
Attempts left: 5
Enter a letter:
 > S
E S _
Attempts left: 5
Enter a letter:
 > P
E S P
```

**Inputs**

- It is allowed to input upper-case and lower-case letters but the output should be in upper-case letters, therefore lower-case letters need to be converted to upper-case letters internally.

```
Word to look for:
 > aLle
Attempts left: 5
Enter a letter:
 > e
_ _ _ E
Attempts left: 5
Enter a letter:
 > A
A _ _ E
Attempts left: 5
Enter a letter:
 > l
A L L E
```

- When the player enters the same letter twice, an error message is displayed (e.g. `Letter S was used already!)`.
- It is not allowed to make the same guess twice. If an incorrect letter is entered twice, the player will not lose an attempt twice but the player will be informed that the letter was already used. **Note:** Save the letters somehow. And don't forget, **global variables are not allowed**

```
Word to look for:
 > alle
Attempts left: 5
Enter a letter:
 > l
_ L L _
Attempts left: 5
Enter a letter:
 > s
_ L L _
Attempts left: 4
Enter a letter:
 > e
_ L L E
Attempts left: 4
Enter a letter:
 > s
Letter S was used already!
Attempts left: 4
Enter a letter:
 > A
A L L E S
```

- It is also possible to enter e.g. a word as a guess. The individual letters should then be handled in succession. **Note:** getchar()
  Example: _ESP_ would be equivalent to the Inputs _E_ _S_ _P_

```
Word to look for:
 > ESP
Attempts left: 5
Enter a letter:
 > ESP
E _ _
Attempts left: 5
Enter a letter:
 > E S _
Attempts left: 5
Enter a letter:
 > E S P
```

**Note:** Input that cointains non-alphabetic characters is incorrect but not tested, so you do not have to worry about it.

### End of the Game

The player(s) won if the guessed the word and loose if there are no remaining attempts.
In case the player(s) win, the message `Congratulations, you won!` is displayed, in case the player(s) loose the given word is shown and `LOST!`.

```
Word to look for:
 > Tutors
Attempts left: 5
Enter a letter:
 > T
T _ T _ _ _
Attempts left: 5
Enter a letter:
 > a
T _ T _ _ _
Attempts left: 4
Enter a letter:
 > S
T _ T _ _ S
Attempts left: 4
Enter a letter:
 > U
T U T _ _ S
Attempts left: 4
Enter a letter:
 > o
T U T O _ S
Attempts left: 4
Enter a letter:
 > P
T U T O _ S
Attempts left: 3
Enter a letter:
 > r
T U T O R S
Congratulations, you won!
```

```
Word to look for:
 > blub
```

< in between the Gameplay is happening, until there is only one attempt left: >

```
Attempts left: 1
Enter a letter:
 > p
B L _ B
LOST! The Word was BLUB
```

---

### Error Messages

```
Letter <upper-case-letter> was used already!
```

---

### Summary

The program starts by asking the player to enter a word with a maximum length of 19 characters.
The other player(s) then start to guess the word. They have 5 attempts to guess the correct word.

The game is won if the word was guessed and lost if there are no remaining attempts.

In the sections above, examples for the gameplay can be found.
