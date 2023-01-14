# SPL-Compiler
The aim of this project is to construct a fully working compiler for a small simple programming language, SPL. 
The compiler will read in SPL source code and produce ANSI C as output.

SPL Language Description
The SPL source resides in a single file. The following diagrams illustrate the complete structure of a SPL program. Identifiers follow the same rules as for PASCAL and other common languages. They must start with a letter and can only contain alphanumeric characters. Identifiers cannot be reserved words in the language.

Three data types are supported in the language, characters, integers and reals. Characters are always enclosed inside single quotes, 'a'. Integers and reals can both be either positive or negative. Reals contain a decimal point and must have at least one digit after the decimal point i.e. 3.0 is a valid real, 3. is not.

Programs are labelled with a program name, which must be a valid identifier. The identifier must be present both at the start and end of the program, and may not be used elsewhere in the program as a variable.
