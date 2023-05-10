# **Simple Shell**
A simple command-line interpreter program written in C language.

# **Usage**
To use the simple shell program, execute the compiled binary file with the following command:

shell
Copy code
$ ./shell
This will start the program and display a prompt for the user to enter a command.

# **Functionality**
The simple shell program supports the following features:

Displays a prompt for the user to enter a command.
Executes a command entered by the user.
Displays the prompt again after executing a command.
Handles errors when an executable cannot be found.
Handles the "end of file" condition (Ctrl+D).
The following features are not supported by the simple shell program:

Commands with arguments.
Built-in commands.
Special characters.
Cursor movement.
Example Usage
Here is an example of how to use the simple shell program:

shell
Copy code
$ ./shell
\#cisfun$ ls
\#cisfun$shell
\#cisfun$ /bin/ls
README.md  shell.c  shell.h
\#cisfun$ /bin/ls -l
total 20
-rw-r--r-- 1 user user  826 Jun  4 14:55 README.md
-rw-r--r-- 1 user user  574 Jun  4 14:52 shell.c
-rw-r--r-- 1 user user 1023 Jun  4 14:52 shell.h
\#cisfun$ exit
# **Requirements**
The simple shell program follows the Betty style guide for C programming. It has been checked using betty-style.pl and betty-doc.pl scripts.

The program uses the execve() system call to execute commands, and passes the environ variable to it.

# **Authors**
This simple shell program was created by Sospeter Nyabuto and Janet Oluoch
