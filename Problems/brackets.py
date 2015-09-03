# Read the brackets that have form open-close relationship.

symbols_to_read = "()"

def get_symbols(symbols_str):
	str_message = raw_input("Please the required text:\n")
	lst_symbols = list() # Get the required symbols in a list
	for i in str_message:
		if i in symbols_str:
			lst_symbols.append(i)
	return lst_symbols



lst_symbols = get_symbols(symbols_to_read)

if not lst_symbols:
	print "No given symbols found in your text"
	exit(1)

if lst_symbols[0] is ")":
	print "Warning: Close bracket in start of the text is not accepted"
	exit(1)

# no Stack structure in Python but we can use lists
open_brackets = list()
close_brackets = list()

for i in lst_symbols:
	if i is "(":
		open_brackets.append(i)
	else:
		close_brackets.append(i)

print open_brackets
print close_brackets

for i in range(0, len(open_brackets)):
	if open_brackets and close_brackets:
		open_brackets.pop()
		close_brackets.pop()
		i += 1


if open_brackets or close_brackets:
	if open_brackets > close_brackets:
		print "You forgot close brackets"
	else:
		print "You forgot open brackets"
