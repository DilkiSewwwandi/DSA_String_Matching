**KMP String Matching Algorithm and Regular Expressions**

1. **How to Run the Program:**
    - Create the text file inside the foldr where main.c is placed( inside 21001855 folder) 
    - Open main.c in a text editor.
    - Replace "text1.txt" by the file name
    - Replace "pattern.txt" with the pattern file
    - To compile the program, use a C compiler (e.g., gcc) and run the below command in the terminal:
            gcc main.c -o a
            ./a
    
2. **Output:**
    - Code will output line numbers and the starting indexes of all possible strings thath match to the pattern
    - Output will write to the "output.txt" file.
    - Clear the output.txt before try for another pattern(Otherwise all the time outputs will append to the previous output).

3. **Test Data:**
    - There are two text files as "text1.txt" and "text2.txt" to test the program. 
    - In "pattern1.txt","pattern2.txt" there are some sample patterns which included in "text1.txt", "text2.txt"

4. **Pattern Characters and Operations:**
- '.' : Matches any single character.
- '*' : Matches zero or more occurrences of the preceding character.
- '+' : Matches one or more occurrences of the preceding character.
- '?' : Matches zero or one occurrence of the preceding character.

