
# Password Strength Checker in C

## Overview
A simple password validation program written in C.
It checks password length, special characters, and
whether the password matches entries in a predefined
list of common passwords.

## Features
- Requires a password longer than 16 bytes.
- Checks for at least one special character.
- Rejects passwords found in a predefined blocklist.
- Uses `fgets()` to limit input to the size of the buffer.
- Rejects input that exceeds the supported buffer size.
- Uses a single `main()` function for all validation logic.

## Requirements
- A C compiler, such as GCC.
- A terminal or command prompt.

## How to Compile

```bash
gcc main.c -o password_checker
```

## How to Run

On Linux or macOS:

```bash
./password_checker
```

On Windows:

```powershell
.\password_checker.exe
```

## Security Notes
- The common-password list is for demonstration only
  and is not comprehensive.
- The input buffer supports up to 255 bytes, including
  the null terminator in the allocated buffer.
- Password length is measured in bytes, not Unicode
  characters.
- This project is an educational example and is not
  a complete password security solution.

## Project Purpose
This project was created as an introductory C programming
assignment to practice input handling, string operations,
conditional statements, loops, and basic memory safety.

## License
This project is available for educational use.
