*This project has been created as part of the 42 curriculum by berhugue*

## Description

This project, ft_printf, is a recreation of the famous C function printf. I have to recreate it's behaviour without using itself.

### Contents

The project must be delivered with a Makefile, and all it's respectives *.h and *.c.

I will be using the libft library to use some auxiliary functions from there on my printf functions:

 - ft_print_char.c
 - ft_print_int.c
 - ft_print_lower_hex.c
 - ft_print_upper_hex.c
 - ft_print_ptr.c
 - ft_print_str.c
 - ft_print_unsigned.c
 - ft_printf.c

---

## Explanation

The `ft_printf` implementation parses the format string character by character and writes output accordingly. When it encounters a `%`, it interprets the following character as a format specifier (like `d`, `s`, or `x`) and calls the appropriate helper function to handle that type. Each helper converts the given argument into its string representation and writes it to the output, typically using `write`.

The design separates parsing logic from conversion logic, making the code modular and easier to extend. Variadic arguments (`va_list`) are used to access the unknown number of inputs, allowing flexibility similar to the standard `printf`. This structure ensures efficient formatted output while keeping the implementation organized and maintainable.

---

## Resources

For this project I have used a few resources such as youtube videos, a lot of stackoverflow posts and help from my peers in 42.

Related to AI, I made use of when I couldn't understand an explanation or example I saw on a page, stackoverflow comment or YouTube video, so the AI could rephrase it in another way easier for beginners or give me a visual example to better understand that topic. I used it as a tool to help me learn and better visualize what is the exercise asking from me, not to do it for me.