// The following exersice was taken from http://www.codewars.com/kata/546deb27018e9559470000b5/train/javascript
// See the link for instructions

/*
In this Kata you need to will need to write two methods.

Method 1

The first method takes in a valid int (positive or negative) and returns the following:

    for any multiple of 3 the string "THREE",
    for any multiple of 5 the string "FIVE",
    for any multiple of both the string "BOTH",
    for all other numbers the original int.

Method 2

The second method takes valid ints (positive or negative) and returns a list of the values that follow the above rules.
The first value may be greater than or less than the second and the list should increment/decrement appropriately
For example an input of 10,13 should generate a response of ['FIVE', 11, 'THREE', 13]. 

*/

//Start of code

function getNumber(number) {
    if (number % 3 === 0 && number % 5 === 0) return 'BOTH';
    else if (number % 3 === 0) return 'THREE';
    else if (number % 5 === 0) return 'FIVE';
    else return number;
}

function getNumberRange(first, last){
    var l = [];
    if (first + last >= 0) {
      for (var i = first; i <= last; ++i ) {
          l.push(getNumber(i));      
      }
    }
    else {
      for (var i = first; i >= last; --i ) {
          l.push(getNumber(i));      
      }
    }
    return l;
}
