# 📒 Address Book Management System (C)

## 📌 Project Overview
The Address Book Management System is a console-based application developed in C that allows users to store, manage, and maintain contact information efficiently.
It supports basic CRUD operations (Create, Read, Update, Delete) using file handling, ensuring data persistence across program executions.

This project demonstrates strong fundamentals of C programming, modular design, structures, and file I/O, making it suitable for academic and interview evaluation.

---

## 🚀 Features
- ➕ Add new contacts
- 🔍 Search contacts by name or mobile number
- ✏️ Edit existing contact details
- ❌ Delete contacts
- 📄 Display all saved contacts
- 💾 Persistent storage using file handling (CSV / text file)
- ✅ Input validation for reliable data entry

---

## 🛠️ Technologies Used
- Language: C
- Concepts:
  - Structures
  - Pointers
  - File Handling
  - Modular Programming
  - Input Validation

---

## 📂 Project Structure
AddressBook/
├── main.c
├── Header.h
├── Features.c
├── Validation.c
├── Contact_Book.csv
├── Contact_Diary.txt
└── README.md

---

## 🧱 Data Structure Used
struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

---

## ▶️ How to Compile and Run

### Compile
gcc main.c Features.c Validation.c -o addressbook

### Run
./addressbook

---

## 📋 Sample Menu
1. Add Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. Display All Contacts
6. Exit

---

## 📌 Key Learning Outcomes
- Practical use of file I/O
- Modular C program design
- Input validation techniques
- Handling real-world persistent data
- Improved code readability and maintainability

---

## 🔮 Future Enhancements
- Alphabetical sorting of contacts
- Duplicate contact detection
- Password protection
- Binary file support
- Import/export functionality

---

## 👨‍💻 Author
Siddharth Shashikant Gaikwad

---

## 📄 License
This project is intended for learning and educational purposes.
