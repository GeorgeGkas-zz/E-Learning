# Read the brackets that have form open-close relationship.
isOpen = "("
isClose = ")"

open_brackets = list()

str_message = raw_input("Please the required text:\n")
lst_symbols = list() # Get the required symbols in a list

if str_message[0] is isClose:
	print "Close vracket in the beginning found"
elif str_message[0] is isOpen:
	open_brackets.append(str_message[0])

for i in str_message[1:]:
		if i is isOpen:
			open_brackets.append(i)
		
		elif i is isClose:
			if len(open_brackets) == 0:
				print "No open brackets found "
				exit(1)
			else:
				open_brackets.pop()
			
if open_brackets:
	print "You have forgot to close brackets"
else:
	print 'Programm terminated successfuly'

