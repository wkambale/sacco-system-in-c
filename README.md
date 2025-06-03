# Sacco Management System in C

This is a simple Sacco (Savings and Credit Cooperative Society) Management System built in C. It allows users to manage client accounts, including opening new accounts, updating information, performing transactions, viewing details, and deleting accounts.

## Features

*   **Account Management:**
    *   Open new client accounts
    *   Update existing account information (address, phone number)
    *   View details of an existing account (by account number or name)
    *   Delete existing accounts
    *   View a list of all clients
*   **Transactions:**
    *   Deposit funds into accounts
    *   Withdraw funds from accounts (not applicable for fixed deposit accounts)
*   **Interest Calculation:**
    *   Calculates interest for 'Fixed1', 'Fixed2', 'Fixed3', and 'Saving' account types.
*   **Password Protection:**
    *   The system requires a password to log in. On the first run, it will prompt the user to set up a password.

## Getting Started

### Prerequisites

*   A C compiler (like GCC) is required to build the program.

### Compilation

1.  Clone the repository:
    ```bash
    git clone https://github.com/your-username/sacco-system-in-c.git
    cd sacco-system-in-c
    ```
2.  Compile the source code:
    ```bash
    gcc -o sacco sacco.c
    ```

### Running the Program

1.  Execute the compiled program:
    ```bash
    ./sacco
    ```
2.  On the first run, you will be prompted to set up a password for the system.
3.  On subsequent runs, you will need to enter the password you set up to access the main menu.

## Usage

Once logged in, the main menu provides the following options:

1.  **Open New Account:** Allows you to create a new client account by providing necessary details.
2.  **Update Info of Existing Account:** Modify the address or phone number for an existing account.
3.  **Make Transactions:** Deposit or withdraw funds for an account.
4.  **Details of Existing Account:** View comprehensive details of a specific client account.
5.  **Delete Existing Account:** Remove a client account from the system.
6.  **View Client List:** Display a summary list of all client accounts.
7.  **Exit:** Close the application.

Follow the on-screen prompts for each option.

## Data Files

The system uses the following data files, which are created in the same directory as the executable:

*   `record.dat`: Stores the client account records.
*   `password.dat`: Stores the encrypted system password.

**Important:** Do not manually edit these files, as it may corrupt the data or prevent the program from running correctly.

## Contributing

Contributions are welcome! If you'd like to improve the system, please follow these steps:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/your-feature-name`).
3.  Make your changes.
4.  Commit your changes (`git commit -am 'Add some feature'`).
5.  Push to the branch (`git push origin feature/your-feature-name`).
6.  Create a new Pull Request.

Please make sure to update tests as appropriate.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
