# getInput:
# Gets the input from the user
# ----------------------------
def getInput():
  card = input('Enter card number: ')
  return card
  
# reverse(number):
# Reverses the card number in string format
# -----------------------------------------
def reverse(num):
  lst = list(num)
  lst.reverse()
  num = "".join(lst)
  return num
  
# isValid(cardNumber):
# Validates if the total of added numbers
# is divisible by 10
# ---------------------------------------
def isValid(cardNumber):
  if sumOfDigits(cardNumber) % 10 == 0:
    return True
  else:
    return False

# sumOfDigits(cardNumber):
# Sums the digits of a credit card number 
# according to the Luhn algorithm
# ---------------------------------------
def sumOfDigits(cardNumber):
  cardNumber = reverse(cardNumber)
  digits = len(cardNumber)
  total = 0
  counter = 1
  
  for c in cardNumber:
    c = charToInt(c)
    if counter % 2 == 0:
      c = doubleDigitValue(c)
      total = total + c
    else:
      total = total + c
    counter = counter + 1
  
  return total
      
# doubleDigitValue(number):
# Processes a number to be doubled according 
# to the rule for a doubled digit in the Luhn algorithm.
# ------------------------------------------------------
def doubleDigitValue(number):
  number = number * 2
  if number < 10:
    return number
  else:
    numString = str(number)
    sum = 0
    for i in range(0, len(numString)):
        sum += int(numString[i])
    return sum

# charToInt(digit):
# Turns a charachter into the number it represents
# ------------------------------------------------
def charToInt(digit):
  number = int(digit)
  return number
  
# getCardType(cardNumber):
# Returns a string representing the type
# of credit card a number is: Visa, MasterCard, 
# American Express, or Unknown.
# ---------------------------------------------
def getCardType(cardNumber):
  if int(cardNumber[0]) == 4:
    return 'Visa'
  elif int(cardNumber[0]) == 5:
    return 'MasterCard'
  elif int(cardNumber[0]) == 3 and (int(cardNumber[1]) == 4 or int(cardNumber[1]) == 7):
    return 'American Express'
  else:
    return 'unknown issuer'
  
# main():
# The main function contains the main program
# that is going to be executed
# -------------------------------------------
def main():
  cardNumber = getInput()
  
  if isValid(cardNumber):
    print('Valid,', getCardType(cardNumber))
  elif not isValid(cardNumber):
    print('Not a valid number,', getCardType(cardNumber))
  
# Calls the main function
# -----------------------
main()