# SPL-Compiler
The aim of this project is to construct a fully working compiler for a small simple programming language, SPL. 
The compiler will read in SPL source code and produce ANSI C as output.

# SPL Language Description
The SPL source resides in a single file. The following diagrams illustrate the complete structure of a SPL program. Identifiers follow the same rules as for PASCAL and other common languages. They must start with a letter and can only contain alphanumeric characters. Identifiers cannot be reserved words in the language.
Three data types are supported in the language, characters, integers and reals. Characters are always enclosed inside single quotes, 'a'. Integers and reals can both be either positive or negative. Reals contain a decimal point and must have at least one digit after the decimal point i.e. 3.0 is a valid real, 3. is not.
Programs are labelled with a program name, which must be a valid identifier. The identifier must be present both at the start and end of the program, and may not be used elsewhere in the program as a variable.

# Files included:
- BNF.txt - BNF file
- spl.l - Lexical Analyser
- spl.c - Main method with yydebug code
- spl.y - Parse Tree + code generation
- compile_NO_DEBUG - creates spl.exe
- My test folders - contains 8 spl file which was used to test the compiler
- Files from RunCompiler.bat

# Semantic checks:
Gives a warning if the program identifiers at the beginning and the end are not the same.
Does not compile if a variable is used without being declared.
Does not compile if a variable is declared twice.
Does not compile if the expression in the for loop are not integer.
Gives a warning if the value assigned to an INTEGER is greater than INT_MAX or less than INT_MIN.

# Type coercion:
Integers can be assigned to chars, but it gives a warning.
Cannot assign char to integer or float.
Cannot assign float to a integer.
Cannot assign integer to a float.
Arithmetic can be done between integers.

# Code optimisation:
If adding a value of 0 (e.g. 1 + 0) the 0 is removed.
If subtracting a value of 0 (e.g. 5 - 0) the 0 is removed.
If multiplying by 0 (e.g. 10 * 0) the expression is resolved to 0.
If multiplying by 1 (e.g. 10 * 1) the 1 is removed.
If dividing by 1 (e.g. 6 / 1) the 1 is removed.
If dividing with a numerator of 0 (e.g. 0 / 3) the expression is resolved to 0.

# Extra feature:
Rename the variable by adding _ at the beginning if it is a reserved keyword in C, for example volatile will be _volatile.
Does not compile if we divide by 0 (e.g. 5 / 0).
