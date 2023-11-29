# ft_printf - Because ft_putnbr() and ft_putstr() aren’t enough

```
⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⡿⢿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀
⠀⣠⣤⣶⣶⣿⣿⣿⣿⣯⠀⠀⣽⣿⣿⣿⣿⣷⣶⣤⣄⠀
⢸⣿⣿⣿⣿⣿⣿⣿⣿⡅⠉⠉⢨⣿⣿⣿⣿⣿⣿⣿⣿⡇
⠈⠻⣿⣿⣿⣿⣿⣿⣿⣥⣴⣦⣬⣿⣿⣿⣿⣿⣿⣿⠟⠁
⠀⠀⢸⣿⡿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⠿⢿⣿⡇⠀⠀
⠀⣠⣾⣿⠂⠀⠀⣤⣄⠀⠀⢰⣿⣿⣿⣿⡆⠐⣿⣷⣄⠀
⠀⣿⣿⡀⠀⠀⠈⠿⠟⠀⠀⠈⠻⣿⣿⡿⠃⠀⢀⣿⣿⠀
⠀⠘⠻⢿⣷⡀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⢀⣾⡿⠟⠃⠀
⠀⠀⠀⠸⣿⣿⣷⣦⣾⣿⣿⣿⣿⣦⣴⣾⣿⣿⡇⠀⠀⠀
⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀
⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀
```


Ahoy, fellow coders! Welcome to `ft_printf`, the treasure trove of printf functionality crafted with care and cunning. In the vast seas of C programming, this project marks my second expedition at Ecole 42. Prepare to navigate the treacherous waters of format specifiers, flags, and precision with `ft_printf` as your trusty shipmate.

## Table of Contents
- [Overview](#overview)
- [Key Functionalities](#key-functionalities)
  - [Format Specifiers](#format-specifiers)
  - [Flags](#flags)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Overview
ft_printf is my second project at Ecole 42, an exploration into the world of formatted output in the C programming language. Inspired by the standard printf function, this custom implementation extends beyond the basics, offering a versatile and efficient toolset for formatting and displaying various data types.

Crafted with precision and attention to detail, ft_printf is designed to handle a range of format specifiers and flags, providing a flexible and powerful solution for displaying characters, strings, integers, pointers, and more. Whether you're a seasoned sailor navigating the seas of C programming or a novice coder setting sail for the first time, ft_printf is your reliable shipmate for conquering the challenges of formatted output.

Dive into the code, explore the intricacies of format strings, and let ft_printf be your guide as you embark on a coding journey filled with precision, efficiency, and a touch of pirate flair.

## Key Functionalities

### Format Specifiers

- `%c`: Display a character.
- `%s`: Display a string.
- `%p`: Display a pointer.
- `%d`, `%i`: Display a decimal integer.
- `%u`: Display an unsigned decimal integer.
- `%x`, `%X`: Display a hexadecimal integer.
- `%%`: Display a literal `%`.

### Flags

- `+`: Display the sign of a number (+ or -).
- ` ` (Space): If no sign is present, a space is displayed.
- `#`: Alternate form. For `%o`, it increases precision to force the first digit to be zero. For `%x` or `%X`, a non-zero result has the prefix '0x' or '0X' added.

## Getting Started
To use ft_printf, follow these instructions:

### Prerequisites

Before you begin, ensure you have the following prerequisites installed:

- [CC](#) (Your C Compiler, for example, [Clang](https://clang.llvm.org/))
- [Make](https://www.gnu.org/software/make/)

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/vopekdas/ft_printf
    ```

2. Navigate to the project directory:

    ```bash
    cd ft_printf
    ```

3. Compile the project:

    ```bash
    make
    ```

    This will compile the source files and create the `libftprintf.a` library.

## Usage

1. Include the `ft_printf.h` header file in your source files:

    ```c
    #include "ft_printf.h"
    ```

2. Link the `libftprintf.a` library when compiling your project:

    ```bash
    cc your_file.c -L/path/to/your-ft_printf-repo -lftprintf -o your_executable
    ```

    Replace `your_file.c` with your source file, `/path/to/your-ft_printf-repo` with the actual path to your `ft_printf` repository, and `your_executable` with the desired name for your executable.

3. Run your executable:

    ```bash
    ./your_executable
    ```


## Examples

Here are some examples demonstrating how to use different format specifiers and flags with `ft_printf`:

```c
#include "ft_printf.h"

int main() {
    // Example 1: Print a string
    ft_printf("String: %s\n", "Hello, world!");

    // Example 2: Print an integer
    ft_printf("Integer: %d\n", 42);

    // Example 3: Print a hexadecimal number with the '0x' prefix
    ft_printf("Hexadecimal: %#x\n", 255);

    // Example 4: Print a character
    ft_printf("Character: %c\n", 'A');

    // Example 5: Print a percentage sign
    ft_printf("Percentage: %%%%%\n");

    // Example 6: Print a pointer address
    int variable = 123;
    ft_printf("Pointer Address: %p\n", (void*)&variable);

    return 0;
}
```
## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
