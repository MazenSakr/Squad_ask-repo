import random

def stage(key): #  function has the drawings of hangman stored in dict
    stage8="""
     +---+
     |   |
     O   |
     |   |
    /|\  |
     |   |
    / \  |
         |"""
    stage7="""
     +---+
     |   |
     O   |
     |   |
    /|\  |
     |   |
    /    |
         |"""
    stage6="""
     +---+
     |   |
     O   |
     |   |
    /|\  |
     |   |
         |
         |"""
    stage5="""
     +---+
     |   |
     O   |
     |   |
    /|\  |
         |
         |
         |"""
    stage4="""
     +---+
     |   |
     O   |
     |   |
    /|   |
         |
         |
         |"""
    stage3="""
     +---+
     |   |
     O   |
     |   |
     |   |
         |
         |
         |"""
    stage2="""
     +---+
     |   |
     O   |
     |   |
         |
         |
         |
         |"""
    stage1="""
     +---+
     |   |
     O   |
         |
         |
         |
         |
         |"""
    stage0="""
     +---+
     |   |
         |
         |
         |
         |
         |
         |"""
    game_stages={0:stage0,1 : stage1,2: stage2,3:stage3,4:stage4,
    5:stage5,6:stage6,7:stage7,8:stage8} # games stages dict
    return game_stages[key]


# random  words stored in string and called by split
words = 'banana fly baboon robot machine chemistry killer slippers bad bed potato tea coffee money smart mango tomato water beach star galaxy '.split()

def getRandomWord(wordList):  # function that choose random word
    wordIndex = random.randint(0, len(wordList) - 1)
    return wordList[wordIndex]

def displayBoard(missedLetters, correctLetters, secretWord): #function that dispaly the game
    print(stage(len(missedLetters))) # call the drawing of hangman depending on the stage
    print('Missed letters:', end=' ')  # printing no of missed letters
    for letter in missedLetters: # if i is 
        print(letter, end=' ')
    print("\n Attempts remaining :" +str(8-len(missedLetters))) # printing remaining attempts

    blanks = '_' * len(secretWord) # printing dashes == random word
    
    for i in range(len(secretWord)):  # enter the loop (number of secret word )times
        if secretWord[i] in correctLetters:  #check if sec
             blanks = blanks[:i] + secretWord[i] + blanks[i+1:]

    for letter in blanks: 
        print(letter, end=' ')
    print()

def getGuess(alreadyGuessed): # take guess letter
     while True: 
         print('Guess a letter.')
         guess = input()
         guess = guess.lower() #make the guessed letter lower case
         if len(guess) != 1: # if the user entered more than one letter
             print('Please enter a single letter.')
         elif guess in alreadyGuessed: # if the user entered a previous guessed letter 
             print('You have already guessed that letter. Choose again.')
         elif guess not in 'abcdefghijklmnopqrstuvwxyz': # if user entered anything except letters as symbols and numbers
             print('Please enter a Letter.')
         else: # return the guessed letter
             return guess

def playAgain(): #ask the  user to play again 
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')
    
    
print('H A N G M A N')
missedLetters = ""
correctLetters = ""
secretWord = getRandomWord(words) # get random word from the words in the string
gameIsDone = False # make game done flag
foundAllLetters = False #make found letters flag
while True:
     displayBoard(missedLetters, correctLetters, secretWord) #display the board with update
     guess = getGuess(missedLetters + correctLetters) # take guess
     if guess in secretWord: # if guess found in secret word
         correctLetters = correctLetters + guess # add the guessed letter to correct letters string
         foundAllLetters = True # found all occurence of the guessed letter - turning on the flag
         for i in range(len(secretWord)): # check on all the letters of secret word found in correct letters 
             if secretWord[i] not in correctLetters:
                 foundAllLetters = False # turning off the flag 
                 break
     if foundAllLetters: #check flag
         print('Yes! The secret  is "' + secretWord +'"! You have won!') # if flag on 
         gameIsDone = True # turn game done flag on 
     else:
          missedLetters = missedLetters + guess # if flag off 
          if len(missedLetters) == 8: # check 
              displayBoard(missedLetters, correctLetters, secretWord)
              print('You have run out of guesses!\nAfter ' + str(len(missedLetters)) + ' missed guesses and ' + str(len(correctLetters)) + ' correct guesses,the word was "' + secretWord + '"')
              gameIsDone = True              #turn game is done's flag on 
     if gameIsDone:
                  if playAgain(): # play again 
                      missedLetters = ''
                      correctLetters = ''
                      gameIsDone = False # turn off game's done flag
                      secretWord = getRandomWord(words)  # produce another random word
                  else:
                      exit() #end program