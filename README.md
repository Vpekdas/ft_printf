# ft_printf

# Table of Contents
1. [Description](#description)
2. [Installation Instructions](#installation-instructions)
3. [Usage Instructions](#usage-instructions)
4. [Key Features](#key-features)
5. [Contribution Guidelines](#contribution-guidelines)
6. [Acknowledgments](#acknowledgments)
7. [License Information](#license-information)
8. [Contact Information](#contact-information)
9. [Project Development](#project-development)

## Description

`ft_printf` sends formatted output to stdout (standard output, usually the terminal). In this project, we have implemented some of the most used format specifiers like `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`. 

Additionally, I have also implemented the `#`, ` ` (space), and `+` flags. These flags allow for additional formatting options, making `ft_printf` a versatile tool for formatted output in C.

The purpose of this project was to learn how to use va_arg and to code a function that can take multiple arguments. In most of the projects in the 42 curriculum, it's forbidden to use the actual printf, so this function is very helpful even though it doesn't have all the features of the actual printf.

## Installation Instructions

Before you begin, ensure you have met the following requirements:

1. **Download the library**: You can clone the library from GitHub using the following command in your terminal:
```bash
git clone https://github.com/Vpekdas/ft_printf.git
```

2. **Install a C compiler**: If you don't already have a C compiler installed, you will need one to build and use this library. You can install the [Clang compiler](https://clang.llvm.org).
   
- On a Mac, you should already have Clang installed as part of Xcode Command Line Tools. You can confirm this by running clang --version in your terminal. If it's not installed, you'll be prompted to install it.

- On a Linux machine, use the package manager for your distribution. For example, on Ubuntu:
  ```bash
  sudo apt install clang
  ```

## Usage Instructions

The files ending with bonus.c are identical to those that do not end with it. I have uploaded the same file under two different names to meet the requirements of 'Moulinette', an algorithm that automatically grades our projects

1. **Include the library in your project**: Add the following line at the top of your source code files:
```c
#include "../includes/ft_printf.h"
```

2. **Compile your project**: When compiling your project, you need to tell the compiler where to find libftprintf.a and to link against it. Here's an example:
```bash
clang your_program.c -LLibftprintf -lftprintf -o your_project_name
```

## Key Features

Here are some of the key features provided by `ft_printf`:

- **Basic Format Specifiers**: `ft_printf` supports the most commonly used format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

```c
ft_printf("String: %s, Character: %c, Pointer: %p, Decimal: %d, Integer: %i, Unsigned: %u, Hexadecimal: %x, Uppercase Hexadecimal: %X\n", 
"Hello", 'A', &num, 123, -123, 123, 255, 255);

ft_printf("Decimal: %+d, Octal: %#o, Hexadecimal: %#x\n", 123, 123, 123);
```

The core of this printf implementation is shown below. The function ft_handle_mandatory manages the different flags by using va_arg. va_arg takes the va_list pointer as its first argument, and the type of the variable to store as its second argument.

For strings and characters, I've used putchar or putstr. For 'u', 'd', or 'i', I've used putnbr. Handling 'p' was slightly more complex as it required a variable that can store a long number for an address, so I've used uintptr_t (integer types wide enough to hold pointers).

Each flag is handled by a specific function (ft_handle_s, ft_handle_c, ft_handle_u, ft_handle_d_i, ft_handle_x_x, ft_handle_p, ft_handle_percent). These functions output the corresponding values and return their lengths.

```c
int	ft_handle_s(const char *str)
{
	int	len;

	len = 0;
	if (str != NULL)
		ft_putstr(str);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	return (len);
}

int	ft_handle_u(unsigned int value)
{
	int	len;

	len = 0;
	len = ft_putnbr(value);
	return (len);
}

int	ft_handle_d_i(int value)
{
	int	len;

	len = 0;
	len = ft_putnbr(value);
	return (len);
}

int	ft_handle_x_x(const char c, long long value)
{
	int	len;

	len = 0;
	if (c == 'x')
	{
		len = ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		len = ft_putnbr_base(value, "0123456789ABCDEF");
	}
	return (len);
}

int	ft_handle_p(void*ptr)
{
	int	len;

	len = 0;
	if (ptr != NULL)
	{
		write(1, "0x", 2);
		len = ft_putnbr_base_p((uintptr_t)ptr, "0123456789abcdef") + 2;
	}
	else
	{
		len = write(1, "(nil)", 5);
	}
	return (len);
}

int	ft_handle_c(int fmt)
{
	int	len;

	len = 0;
	len = ft_putchar(fmt);
	return (len);
}

int	ft_handle_percent(const char **fmt)
{
	int	len;

	len = 0;
	len = ft_putchar('%');
		(*fmt)++;
	return (len);
}
```

For the bonus part, I chose to handle only the sharp (#), space, and plus (+) flags. As a novice, I didn't see the purpose of the other flags. The approach was quite similar to the mandatory part, with the only difference being the format that I'm printing.

Handling space and plus was quite straightforward. I suggest attempting at least these bonuses. The only difficulty is correctly incrementing the way you are "parsing". In the mandatory part, you can analyze character by character, but here multiple characters can be used for a flag. For example: %#x.

Each flag is handled by a specific function (ft_handle_sharp, ft_handle_space, ft_handle_plus). These functions output the corresponding values and return their lengths.
```c
int	ft_handle_sharp(long long value, const char *fmt)
{
	int	len;

	len = 0;
	if (*fmt == 'o')
	{
		len = write(1, "0", 1);
		len += ft_putnbr_base(value, "01234567");
	}
	else if (*fmt == 'x')
	{
		if (value != 0 && value != LONG_MIN)
				len = write(1, "0x", 2);
		len += ft_putnbr_base(value, "0123456789abcdef");
	}
	else if (*fmt == 'X')
	{
		if (value != 0 && value != LONG_MIN)
			len = write(1, "0X", 2);
		len += ft_putnbr_base(value, "0123456789ABCDEF");
	}
	return (len);
}

int	ft_handle_space(int value, const char **fmt)
{
	int	len;

	len = 0;
	if (**fmt == 'd' || **fmt == 'i')
	{
		if (value >= 0)
		{
			len = ft_putchar(' ');
			len += ft_putnbr(value);
		}
		else
			len = ft_putnbr(value);
	}
	return (len);
}

int	ft_handle_plus(int value, const char **fmt)
{
	int	len;

	len = 0;
	if (**fmt == 'd' || **fmt == 'i')
	{
		if (value >= 0)
		{
			len = ft_putchar('+');
			len += ft_putnbr(value);
		}
		else
			len = ft_putnbr(value);
	}
	return (len);
}
```

## Acknowledgments

I would like to express my deepest appreciation to all those who provided the possibility to complete this project. A special gratitude I give to the contributors of the following tester programs:

* [printfTester](https://github.com/Tripouille/printfTester)

These tester programs were instrumental in the development process. They not only helped me identify and correct errors quickly, but also introduced me to new testing methodologies and considerations I hadn't previously encountered. Their insights and expertise contributed significantly to the completion of this project.

## Contribution Guidelines

I welcome contributions from everyone. Here are some guidelines to follow:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/libft.git
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on. Do not make changes directly on the master branch
```bash
git checkout -b your-branch-name
```

4. **Make your changes**: Make your changes in the new branch. Ensure your code follows the [norminette](https://github.com/42School/norminette).

5. **Commit your changes**: Commit your changes regularly with clear, descriptive commit messages.
```bash
git commit -m "Your commit message"
```

6. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

7. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.
Please note that this project has a code of conduct, and contributors are expected to adhere to it. Any contributions you make are greatly appreciated.

## License Information

This project is licensed under the [MIT License](LICENSE).

The MIT License is a permissive license that is short and to the point. It lets people do anything they want with your code as long as they provide attribution back to you and don’t hold you liable.

For the full license text, see the [LICENSE](LICENSE) file.

## Contact Information

If you have any questions, issues, or if you want to contribute, feel free to reach out to me:

- GitHub: [@Vpekdas](https://github.com/Vpekdas)
- Discord: Captain-Plouf#7811

## Project Development

This project started as a simple tool for personal use and is evolving into a full-fledged library. While it has been a solo endeavor so far, contributions from the community are welcome and appreciated.

### Current Status

The project is currently complete and not in active development. However, maintenance and updates will be done as needed.

### Future Plans

Plans for future development include adding more functions, improving performance, and expanding the documentation.

### Known Issues

There are currently no known issues. If you find a bug, please report it in the [issue tracker](https://github.com/Vpekdas/libft/issues).

### Contributing

Contributions are always welcome! See the [Contribution Guidelines](#contribution-guidelines) for more information.


