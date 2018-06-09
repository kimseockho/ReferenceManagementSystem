# Reference Management System
This program was developed as a group assignment for the COMP718 Advanced Programming Languages under the guidance of course instructor Jaeil Kim. The team members are: Shahzad Ali, SeokHo Kim, and Lamyanba Isharam

Aim of this Program
-------------------------
To facilate a user to import bibtext files, maintain a repository of imported references, and export them in a particular style like IEEE, APA, and MLA etc.


Description of the Files
-------------------------

1) main.cpp: 
It is the main file to be executed for parsing a given BibTeX file. The three text files (ref1, ref2, and ref3) are provided as a sample input.

2) bibparser.h: 
These files are the core of this program and are used to implement the functions like reading an input file line by line, parsing each line of string datatype, converting a string to uppercase, and deleting blank spaces in a string.

3) database.h:
All method for each entity type are defined in this file. These methods provide the following features:
+ Add article, book, or inproceeding
+ Display the table containing the imported references
+ Search by author, year, or title within the table
+ Export any particular reference in the APA reference style


What's New
-------------------------

v3.0: Simplified text based interface, read multiple files from a directory; creation of table through vectors; search any entity type by year, title, and author; export a reference in the APA style

v2.0: Object orientated approach is used to implement the string parsing module. Some bugs during the parsing are fixed; timestamping is implemented, output is generated in the form of (tag, content) pair e.g. (year, 2018)

v1.0: It reads a bibtex file and parse the strings
