# Lexical analyzer

import sys

reservedWords = ["cin>>", "for", "int", "cout<<"  ]
operator      = ["+", "-", "*", "/", "++", "--"   ]
special       = [">", "=", ";","(", ")", ">=", ","]

def tokenize(tokentype : list) -> str:
    pass

def OperatorToken(tokentype : list, operator : str) -> str:
    if operator in tokentype:
        return operator

def SpecialToken(tokentype : list , special : str) -> str:
    if special in tokentype:
        return special

def ReservedWord(tokentype : list, reserved : str) -> str:
    if reserved in tokentype:
        return reserved

def Identifier(word : str) -> str:
    if word.isalpha():
        if word not in reservedWords:
            return word


def main():

    while(True):

        statement = str(input("Enter a statement: ")).casefold()

        for word in statement.split():

            if ReservedWord(reservedWords, word):
                print(f'{word} \t reserved word')

            if word.isnumeric(): 
                print(f'{word} \t number')

            if OperatorToken(operator, word):    
                print(f'{word} \t operator')

            if SpecialToken(special, word):
                print(f'{word} \t special symbol')

            if Identifier(word):
                print(f'{word} \t identifier')

        repeat_input = str(input("CONTINUE (y/n)?")).casefold()

        if repeat_input == "y":
                statement

        elif repeat_input == "n":
                sys.exit()

        else: raise ValueError("Invalid input: ")

if __name__ == "__main__":
    main()
