# 🏧 ATM Machine Simulation (C Programming)

A **console-based ATM machine simulation** developed in **C**, implementing secure user authentication and basic banking operations with **file-based data persistence**.

This project demonstrates practical use of **structures, file handling, modular programming, and authentication logic** to simulate real-world ATM workflows.

---

## 📌 Features

- 🔐 **User Authentication**
  - PIN-based login system
  - Account locked after **3 incorrect PIN attempts**

- 💰 **Banking Operations**
  - Balance inquiry
  - Cash withdrawal with balance validation
  - Cash deposit functionality

- 💾 **Persistent Data Storage**
  - User account data stored in files
  - Account balance updated after every transaction

- 🧩 **Modular Architecture**
  - Separate source files for authentication, withdrawal, deposit, and structure definition
  - Clear separation of concerns for maintainability

---

## 🛠️ Tech Stack

- **Language:** C  
- **Concepts Used:**
  - Structures
  - File Handling (`fopen`, `fscanf`, `fprintf`)
  - Modular programming
  - Conditional logic & loops
  - Input validation

---

## 📂 Project Structure

```text
ATM-Machine-Simulation/
│
├── main.c               # Entry point, user flow & menu handling
├── structure.c          # User structure definition
├── authentication.c     # PIN and account verification logic
├── withdraw.c           # Cash withdrawal logic
├── deposit.c            # Cash deposit logic
├── find.c               # Utility to read and display stored user data
├── data.txt             # Persistent storage for user accounts
└── README.md
```

## 🧠 How It Works

 1. User enters Account Number
 2. System prompts for PIN authentication
 3. User gets 3 attempts before account lock
 4. Upon successful login, user can:
    - Check balance
    - Withdraw cash
    - Deposit cash
 5. Updated balance is written back to file, ensuring persistence

## ▶️ How to Run

Clone the repository
```
git clone https://github.com/your-username/atm-machine-simulation.git
```

Compile the program
```
gcc main.c -o atm
```
Run the executable
```
./atm
```

Ensure data.txt exists in the same directory with valid user data.

## 📄 Sample Data Format (data.txt)
```
1001 1234 5000 Rahul
1002 4321 7500 Ankit
```

### Format:
Account_Number PIN Balance Name

## 🚀 Future Enhancements

- Encrypt PINs instead of storing them in plain text
- Add transaction history logging
- Improve input validation and error handling
- Support dynamic number of users
- Convert to menu-driven loop for multiple transactions

## 🎯 What This Project Demonstrates

- Understanding of real-world system simulation
- Practical use of file handling for persistent storage
- Clean modular C programming
- Basic security and authentication logic

## 🧑‍💻 Author

 **Akhil Kotnala**
