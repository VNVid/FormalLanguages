# Earley Parser Practicum
***
## Asymptotics
This implementation uses std::set to find out whether the array D is changing. So the main operations Scan, Predict and Complete take O(|G|*|w|*log(|G|*|w|)), O(|G|*|w|\*log(|G|*|w|)) and O((|G|*|w|)^2\*log(|G|*|w|)) time respectively. 


## How to run the program
To run the program use:  
make run_main  
./run_main

To run tests use:  
make run_tests  
./run_tests

To clean files:
make clean


## Input format
Firstly, enter number of production rules. Then the rules themselves, each on a new line. Do not enter any dividers like arrows (S -> aS), just a non terminal (the left part) and the rest. Spaces do not matter. For empty word, which is usaully lettered as epsilon, write nothing.
Secondly, enter number of words you want to check. And then input the words.


Example of correct input: 
3 
S aSbS  
S bSaS  
S 
2 
abba  
bab 

Output: 
Yes 
No  
