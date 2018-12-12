balance = float(input("Enter balance: "))
payment = float(input("Enter payment: "))
apr = float(input("Enter APR: "))
month = 0

heading = ['Month Interest Payment Balance']

print(heading)

while month < 12 and balance > 0:
  interest = balance * ((apr/100)/12)
  newBalance = balance + interest - payment
  print (month, '{:.2f}'.format(interest), '{:.2f}'.format(payment), '{:.2f}'.format(newBalance))
  if newBalance > payment:
    balance = newBalance
  else:
    payment = newBalance + (newBalance * ((apr/100)/12))
    balance = newBalance 
  month += 1