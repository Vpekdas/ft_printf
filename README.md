# ft_printf

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Contributing](#contributing)
5. [License](#license)

## Description

ft_printf is a project from the 42 Common Core curriculum. It involves reimplementing the basic functionality of the standard C printf function. It will be very usefull since we are not allowed to use C library on common core project.

As part of the 42 curriculum, this project comes with strict coding guidelines:
- The standard C library is forbidden, requiring the use of custom code for all tasks.
- A strict rule of 5 functions per file and 25 lines per function is enforced.
- There are restrictions such as no assignments on the same line and a focus on clean, maintainable code.

### Purpose

The ft_printf function replicates the behavior of the standard C printf, enabling formatted output to the standard output. It supports a selection of commonly used format specifiers.

| **Flags** | **Purpose** |
|:------------:|-------------|
| %s | Prints a string (null-terminated character array) |
| %u | Prints an unsigned decimal integer |
| %d %i| Prints a signed decimal integer |
| %x | Prints an unsigned integer in hexadecimal (lowercase) |
| %X | Prints an unsigned integer in hexadecimal (uppercase) |
| %p | Prints a memory address (pointer) in hexadecimal format |
| %# | Adds a prefix (0x, 0X, or 0) for %x, %X, and %o formats |
| %  | Adds a space before positive numbers (only for %d or %i) |
| %+ | Forces a sign (+ or -) in front of numeric values (%d or %i)|

### Technologies used

- C language.
- Make.

### Challenges and Future Features

One of the main challenges in this project was understanding how va_arg works and how to properly handle variadic functions in C. Another important lesson—one I realized later while working with C++—was that the project also aims to teach the use of function pointers.

Instead of writing a long chain of `if` statements to detect format specifiers, a cleaner and more scalable approach would be to map each specifier to a function pointer. This technique improves readability and makes it easier to add new flags or behaviors in the future.

I’m not planning to add any new features at this time.

## Installation

- Ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/)
```bash
clang --version
gcc --version
```
- Ensure you have installed [Make](https://www.gnu.org/software/make/) to build the project
```bash
make --version
```

## Run

The files ending with bonus.c are identical to those that do not end with it. I have uploaded the same file under two different names to meet the requirements of 'Moulinette', an algorithm that automatically grades our projects

1. **Build the library**: Compile the project using the provided `Makefile`:
```c
make
```
This will generate the `libftprintf.a` static library, which you can then include in your own C projects.

2. **Include the library in your project**: Add the following line at the top of your source code files:
```c
#include "../includes/ft_printf.h"
```

3. **Compile your own project with the library**: Link the ft_printf library when compiling your project:
```bash
clang your_source.c -L/path/to/library -lftprintf -o your_project_name
```

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/ft_printf/issues).

To contribute, follow these steps:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/ft_printf
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on.
```bash
git checkout -b your-branch-name
```

4. **Commit your changes**: Commit your changes.
```bash
git commit -m "Your commit message"
```

5. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

6. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.

## License

This project is licensed under the [MIT License](LICENSE).
