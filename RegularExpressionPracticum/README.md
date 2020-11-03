# RegularExpressionPracticum
***
The task is to find out whether the input regular expression,given in inverted Polish notation in alphabet L = {a, b, c, 1, +, ., *}, specifies a word with prefix _letter_^n. 


## Algorithm 
Let's process the expression symbol by symbol. If we meet a letter (_a_, _b_ or _c_), we put it in the stack. If we meet an operation, then we take the necessary number of arguments out of the stack (2 for _+_ and _._, 1 for _*_), apply the operation to the arguments and put the result in the stack. 

But instead of expressions themselves we will keep pairs of integers in the stack. The first parameter is the maximum length of word _letter_ ^ m in the processed part of expression. The second - the maximum number of _letter_ in prefix _letter_ ^ m + _other_letter_. For example, for expression ***(aaa+ab+c)*** and _letter_=***a*** the pair is (3, 1), as ***aaa*** is the longest word consisting of ***a*** only and ***ab*** is the word with the longest ***a***^m prefix.

## Asymptotics
The algorithm is linear(O(len(expression))) , as processing of each symbol takes O(1) time.

## How to run the program
To run the program use:

make run_main

./run_main

To run tests use:

make run_tests

./run_tests
