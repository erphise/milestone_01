*This project has been created as part of the 42 curriculum by berhugue*

## Description

This activity will not only allow you to add a highly useful function to your collection,
but it will also teach you an important concept in C programming: static variables.

### Contents

The project must be delivered with three files:

 - get_next_line.c
 - get_next_line_utils.c
 - get_next_line.h:

---

## Explanation

The `get_next_line` implementation uses a static string buffer per file descriptor and reads data in fixed-size chunks. It appends data until a newline is found, then returns the line while keeping the leftover for the next call. This design reduces system calls and preserves state between calls, ensuring correct handling of partial reads. The data structure is justified because it efficiently maintains continuity in a stream-like reading process.

---

## Resources

For this project I have used a few resources such as youtube videos, a lot of stackoverflow posts and help from my peers in 42.

Related to AI, I made use of when I couldn't understand an explanation or example I saw on a page, stackoverflow comment or YouTube video, so the AI could rephrase it in another way easier for beginners or give me a visual example to better understand that topic. I used it as a tool to help me learn and better visualize what is the exercise asking from me, not to do it for me.