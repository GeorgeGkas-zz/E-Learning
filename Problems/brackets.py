# Read the brackets that have form open-close relationship.
def get_bracket():
    isOpen = "("
    isClose = ")"
    open_brackets = list()

    str_message = raw_input("Please the required text:\n")
    lst_symbols = list() # Get the required symbols in a list

    for i in str_message:
        if i is isOpen:
            open_brackets.append(i)
            
        elif i is isClose:
            if len(open_brackets) == 0:
                return False
            else:
                open_brackets.pop()
            
    if open_brackets:
        return False
    else:
        return True
    
is_bracket_correct = get_bracket()
