-- ffsh (Fast and Flexible shell) -- 

The Fast and Flexible Shell (ffsh) is an experimental, minimal command line interpreter (CLI) for UNIX-like systems.

Features:
1. Parses user input and executes commands (e.g., `ls`, `cd`, `cat`, `exit`, etc.).
2. Forks a child process to execute external commands, keeping the shell responsive.
3. Features a built-in `exit` command to quit the shell.
4. Displays a welcome message on startup.
5. Handles empty input gracefully.
6. Uses simple whitespace tokenization for command parsing.


<img width="412" height="132" alt="Screen Shot 2025-07-27 at 3 53 11 PM" src="https://github.com/user-attachments/assets/58a9ee90-bae6-416d-8b35-90cccd69f28a" />
<img width="392" height="156" alt="Screen Shot 2025-07-27 at 3 53 25 PM" src="https://github.com/user-attachments/assets/197d4d2b-2e8d-4268-97eb-e70074ff3032" />

Usage:
- Compile with: `gcc ffsh.c -o ffsh` or `clang ffsh.c -o ffsh`
- Run: `./ffsh`
- Type commands at the `ff$h>:` prompt.
- Type `exit` to quit.

Note: This shell is for experimental purposes and does not support advanced features like piping, redirection, or advanced scripting. Its truly a bare-bone CLI written in a singular C file. 

Developed by Cesare Landi
