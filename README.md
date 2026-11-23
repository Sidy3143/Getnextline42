# 42-project-template

*This activity has been created as part of the 42 curriculum by sindiaye.*

# Project Name

**GETNEXTLINE**

## Description

**GetNextLine** is a project developed as part of the 42 curriculum.

The goal of this project is to implement a function that reads a file descriptor line by line, returning one line at a time whenever it is called.

The function must handle multiple file descriptors, different buffer sizes, and memory management while reading files efficiently.

This project focuses on:

- Reading files using the `read()` system call.
- File descriptors and file I/O.
- Static variables and persistent data between function calls.
- Dynamic memory allocation and memory management.
- String manipulation and buffer handling.
- Handling newlines and end-of-file conditions.

## Instructions

### Requirements

- GCC or Clang compiler.
- GNU Make.
- Standard C library.
- Unix-like operating system.

### Compilation

Clone the repository:

```
git clone <repository-url>
cd <repository-name>
```

Compile the source files:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o get_next_line

BUFFER_SIZE defines the number of bytes read during each call to read(). You can change its value to test different buffer sizes.

### Execution

Run the executable:

`./get_next_line `

To use GetNextLine in your own program, include the header:

```
#include "get_next_line.h" 
```

The function takes a file descriptor as an argument and returns the next line read from that file.

```
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

## Algorithm and Data Structure

### Chosen Algorithm

GetNextLine uses an incremental reading approach to retrieve a file's content one line at a time.

Instead of reading the entire file into memory, the function reads a limited number of bytes at each call using the `read()` system call.

The algorithm follows these steps:

1. **Read:** Read up to `BUFFER_SIZE` bytes from the file descriptor.
2. **Store:** Append the newly read data to the previously stored content.
3. **Search:** Check whether the accumulated content contains a newline character (`\n`).
4. **Extract:** If a newline is found, extract and return the line up to and including the newline.
5. **Preserve:** Keep the remaining content for the next function call.
6. **Repeat:** Continue reading until a newline is found or the end of the file is reached.

This approach avoids loading the entire file into memory and allows the function to process files incrementally.

### Data Structures

The implementation relies on:

- **Static variable:** Preserves the remaining unread content between successive calls to `get_next_line()`.
- **Character buffers:** Temporarily store data returned by `read()`.
- **Dynamically allocated strings:** Store accumulated content and extracted lines.
- **File descriptors:** Identify the files or input streams being read.

## Resources

### Documentation and References

- get_next_line subject – 42
- read() – Linux Manual Page
- malloc() – Linux Manual Page
- free() – Linux Manual Page
- Static Variables in C

### AI Usage

AI tools were used as supplementary learning and development resources during this project.

The following tasks involved AI assistance:

- **Concept explanation:** Understanding file descriptors, the `read()` system call, static variables, buffer management, and dynamic memory allocation.
- **Debugging:** Understanding potential bugs related to memory leaks, buffer handling, newline detection, and end-of-file conditions.
- **Code review:** Exploring implementation choices, algorithm efficiency, and edge cases.
- **Documentation:** Assistance with README writing and technical explanations.

All AI-generated suggestions were reviewed, tested, and understood before being incorporated into the project.

## Project Structure

```
get_next_line/
│
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

## Author

**sindiaye**

- GitHub: [Sidy3143](https://github.com/Sidy3143)
