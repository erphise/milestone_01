*This project has been created as part of the 42 curriculum by berhugue.*

# get_next_line

## Description

This project consists in creating a function that returns a line read from a file descriptor. It's prototype will be the following: `char   *get_next_line(int fd);`.

The parameter is fd: The file descriptor to read from and it's return value will be Read line: correct behaviour or NULL: there is nothing else to read, or an error ocurred. The external functions allowed are read, malloc and free.

The project must be delivered with these three files:

 - get_next_line.c
 - get_next_line_utils.c
 - get_next_line.h:

### Explanation

The `get_next_line` implementation uses a static string buffer per file descriptor and reads data in fixed-size chunks. It appends data until a newline is found, then returns the line while keeping the leftover for the next call. This design reduces system calls and preserves state between calls, ensuring correct handling of partial reads. The data structure is justified because it efficiently maintains continuity in a stream-like reading process.


## Instructions

In order to be able to test this function, since it's not a program, you will need to add a main function to run it. Either in the form of a `main.c` file on it's own, or attaching it at the end of the `get_next_line.c` file. Make sure to add the propper libraries on each case.

Here is an example:
```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
Once you got the main function you can proceed to compile the program. To do so we will use this command on our terminal: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`

In case you used a separate `main.c` file it would look like this: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c`, of course adjusting the `BUFFER_SIZE` to whatever you deem necessary for each test.

Now you got your little program `a.out`, you only need to add a `test.txt` file alongside it with anything inside it you would like to test and run it with `./a.out`.

## Resources

For this project I have used a few resources such as youtube videos, a lot of stackoverflow posts and help from my peers in 42. Here are a few of those resources: [This gitbook guide](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line), [this youtube video](https://www.youtube.com/watch?v=-Mt2FdJjVno) or [this Medium article](https://medium.com/@lannur-s/gnl-c3cff1ee552b).

Related to AI, I made use of when I couldn't understand an explanation or example I saw on a page, stackoverflow comment or YouTube video, so the AI could rephrase it in another way easier for beginners or give me a visual example to better understand that topic. I used it as a tool to help me learn and better visualize what is the exercise asking from me, not to do it for me.
