# Account Management System With C

This is a CRUD (Create, Read, Update, Delete) system developed entirely in C. The project simulates bank account management, using data persistence through direct manipulation of random-access binary files.

## Main Features

The system operates through an interactive terminal menu with the following operations:

1. **Register Client:** Allows the creation of a new account in a specific physical position of the file, with protection against accidental overwriting of active accounts.
2. **Consult Account:** Searches and displays a specific client's data using their account number.
3. **Update Balance:** Allows deposits and withdrawals by locating the record in the file, updating the balance in memory, and overwriting only the necessary block.
4. **Remove Client (Logical Deletion):** "Empties" the client's account by overwriting the record with zeros and a null character, maintaining the structural integrity of the binary file.
5. **List All:** Iterates through the file sequentially, listing only active accounts and ignoring logically deleted records or empty memory positions.
6. **Restore Reading:** Resets the file reading pointer (`rewind`) for new complete listings.

## Applied Technical Concepts

This project solves several classic C language and computer architecture challenges:
- **File Pointers:** Extensive use of `fseek`, `fread`, and `fwrite` for navigation and surgical byte alteration on the hard drive without needing to rewrite the entire file.
- **Keyboard Buffer Handling:** Implementation of buffer clearing (using `%*c` and `getchar()`) to prevent infinite loops in case of invalid inputs or leftover `\n` (Enter) characters.
- **String Manipulation:** Safe use of `fgets` combined with `strcspn` to read composite names with spaces and remove automatic line breaks.
- **Data Structures:** Use of `struct` to standardize the size of data blocks (167 bytes per record).

## Record Structure (Struct)

Each block saved in the `.dat` file follows this structure:
- `id` (int): Logical account identifier.
- `nome` (char[155]): Account holder's name.
- `numeroConta` (int): Account number (based on the insertion position).
- `saldo` (float): Current balance.

## How to Compile and Run

Make sure you have a C compiler (like GCC) installed on your machine.

1. Clone this repository or download the source file.
2. Open the terminal and navigate to the project folder.
3. Compile the code with the command:
   ```bash
   gcc main.c -o bank

Run the generated program:

        On Linux/Mac: ./bank

        On Windows: bank.exe