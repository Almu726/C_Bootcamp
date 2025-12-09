#ifndef PROGRAM_LINKING_H //stands for if not defined - checks for previous definition of program_linking_h
#define PROGRAM_LINKING_H //defines program_linking_h if not previously defined

int calculation(int x);
//  This is a function declaration (prototype).
// Says: “There’s a function called calculation that takes an int and returns an int.”
// No body  — the body lives in program_linking2.c.

#endif // Ends the #ifndef block.
// Ensures the header is only processed once.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//This is a header file which delcares functions and variables to be shared between multiple source files. 
//During compilation, the linker later connects the decleartions in the header file to their definitions in the source files.
//Prevents duplicate definitions (you don’t put the full function body in multiple files).
//Allows multiple .c files to share the same function signatures.
//Keeps your project organized and scalable — especially when you add more functions or libraries.