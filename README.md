# 🚗 Car Management System

A comprehensive **CRUD-based Car Management System** built in **C++** using fundamental programming concepts. This project demonstrates core computer science principles including file I/O, data structures, pointers, and modular programming.

---

## 📋 Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
- [Data Format](#data-format)
- [Programming Concepts](#programming-concepts)
- [Code Examples](#code-examples)
- [Limitations](#limitations)
- [Future Enhancements](#future-enhancements)

---

## ⭐ Features

### Core CRUD Operations
- ✅ **Create**: Add new car records with complete details (ID, Brand, Model, Year, Color, Price)
- ✅ **Read**: Display all cars or search by car ID
- ✅ **Update**: Modify any existing car information
- ✅ **Delete**: Remove cars with confirmation prompt

### Additional Features
- 📁 **Persistent Storage**: Automatic file I/O using `cars_data.txt`
- 🔍 **Search Functionality**: Find cars by ID instantly
- ⚠️ **Error Handling**: Validates unique IDs and handles edge cases
- 🎯 **User-Friendly Interface**: Interactive menu-driven system
- 💾 **Data Validation**: Checks for duplicate IDs and invalid inputs
- 🔗 **Pointer Implementation**: Demonstrates proper pointer usage in C++

---

## 📁 Project Structure

```
car-management-system/
├── car_management_system.cpp    # Main source code (~350 lines)
├── cars_data.txt                # Data file (auto-generated)
└── README.md                    # This file
```

---

## 🔧 Requirements

- **C++ Compiler**: g++, Clang, or MSVC
- **C++11 Support**: Required for standard features
- **No External Dependencies**: Uses only standard C++ libraries

**Supported Platforms:**
- ✅ Windows (MinGW, MSVC)
- ✅ Linux (g++, Clang)
- ✅ macOS (Clang)

---

## 📥 Installation

### Clone the Repository
```bash
git clone https://github.com/yourusername/car-management-system.git
cd car-management-system
```

**Or** download the files manually.

---

## 🏗️ Compilation

### Option 1: Using g++ (Recommended)
```bash
g++ -Wall -std=c++11 -o car_management car_management_system.cpp
```

### Option 2: Using Microsoft Visual C++
```bash
cl car_management_system.cpp
```

### Option 3: Using Clang
```bash
clang++ -Wall -std=c++11 -o car_management car_management_system.cpp
```

### Compilation Flags
- `-Wall`: Enable all compiler warnings
- `-std=c++11`: Use C++11 standard
- `-o`: Output executable name

---

## 🎮 Usage

### Running the Program

**Windows:**
```bash
car_management.exe
```

**Linux/macOS:**
```bash
./car_management
```

### Menu Interface

```
========================================
   CAR MANAGEMENT SYSTEM
========================================
1. Add a new car
2. View all cars
3. Search for a car
4. Update car information
5. Delete a car
6. Save and Exit
========================================
Enter your choice (1-6): 
```

### Operation Examples

#### 1️⃣ **Add a Car**
```
Enter your choice: 1
--- ADD NEW CAR ---
Enter Car ID: 7
Enter Brand: Tesla
Enter Model: Model S
Enter Year: 2023
Enter Color: White
Enter Price: $85000
>> Car added successfully!
```

#### 2️⃣ **View All Cars**
```
Enter your choice: 2
--- ALL CARS ---
  ID: 1 | Brand: Toyota | Model: Camry | Year: 2021 | Color: Silver | Price: $28000
  ID: 2 | Brand: Honda | Model: Civic | Year: 2020 | Color: Blue | Price: $22000
  ID: 4 | Brand: BMW | Model: X5 | Year: 2021 | Color: Black | Price: $65000
Total Cars: 3
```

#### 3️⃣ **Search for a Car**
```
Enter your choice: 3
--- SEARCH CAR ---
Enter Car ID to search: 1
>> Car found!
  ID: 1 | Brand: Toyota | Model: Camry | Year: 2021 | Color: Silver | Price: $28000
```

#### 4️⃣ **Update Car Information**
```
Enter your choice: 4
--- UPDATE CAR ---
Enter Car ID to update: 4
>> Current car information:
  ID: 4 | Brand: BMW | Model: X5 | Year: 2021 | Color: Black | Price: $65000
Enter new Color (or press Enter to keep current): Red
>> Car updated successfully!
```

#### 5️⃣ **Delete a Car**
```
Enter your choice: 5
--- DELETE CAR ---
Enter Car ID to delete: 3
>> Car to be deleted:
  ID: 3 | Brand: Ford | Model: Mustang | Year: 2022 | Color: Red | Price: $45000
Are you sure you want to delete this car? (y/n): y
>> Car deleted successfully!
```

---

## 📊 Data Format

### Storage Format
Data is stored in `cars_data.txt` as pipe-delimited records:

```
ID|Brand|Model|Year|Color|Price
```

### Example Data File
```
1|Toyota|Camry|2021|Silver|28000
2|Honda|Civic|2020|Blue|22000
4|BMW|X5|2021|Black|65000
5|Audi|A4|2020|White|32000
6|Honda|City|2010|Grey|18000
```

### Auto-Save/Load
- Data automatically loads when program starts
- Data automatically saves on graceful exit (option 6)

---

## 💡 Programming Concepts

### 1. **Data Structures (struct)**
```cpp
struct Car {
    int id;
    char brand[50];
    char model[50];
    int year;
    char color[30];
    double price;
};
```
Encapsulates all car attributes in a single structure.

### 2. **Arrays (Static Memory)**
```cpp
Car cars[MAX_CARS];  // Array of Car structures (max 100)
```
Stores multiple car records in contiguous memory.

### 3. **Pointers & References**
```cpp
void displayCar(Car *c) {
    cout << c->id << " | " << c->brand;  // Arrow operator
}

Car *carPtr = &cars[index];  // Get memory address
displayCar(carPtr);          // Pass by reference
```
Demonstrates pointer usage for efficient memory handling.

### 4. **File I/O**
```cpp
ifstream file(DATA_FILE);    // Read from file
ofstream file(DATA_FILE);    // Write to file
```
Enables persistent data storage between program runs.

### 5. **String Manipulation (cstring)**
```cpp
strcpy(cars[index].brand, temp_brand);  // Copy strings
strlen(temp_brand);                      // Get string length
```
Handles C-style string operations.

### 6. **Modular Programming**
- `loadFromFile()` - Load data from disk
- `saveToFile()` - Persist data to disk
- `addCar()` - Create operation
- `viewAllCars()` - Read operation
- `searchCar()` - Search operation
- `updateCar()` - Update operation
- `deleteCar()` - Delete operation

---

## 📝 Code Structure

### Libraries Used
```cpp
#include <iostream>   // Input/Output
#include <fstream>    // File handling
#include <cstring>    // String functions
```

### Key Functions Overview

| Function | Purpose |
|----------|---------|
| `loadFromFile()` | Load car data from file at startup |
| `saveToFile()` | Persist data to file |
| `addCar()` | Add new car record (CREATE) |
| `viewAllCars()` | Display all cars (READ) |
| `searchCar()` | Find car by ID (READ) |
| `updateCar()` | Modify car details (UPDATE) |
| `deleteCar()` | Remove car record (DELETE) |
| `displayCar(Car *c)` | Print car details using pointer |
| `carExists(int id)` | Check if car ID exists |
| `findCarIndex(int id)` | Get array index of car |

---

## ⚙️ Configuration

### Modify Maximum Cars
Edit line 7 in `car_management_system.cpp`:
```cpp
const int MAX_CARS = 100;  // Change 100 to desired limit
```

### Change Data File Location
Edit line 8:
```cpp
const char DATA_FILE[] = "cars_data.txt";  // Change filename
```

---

## ⚠️ Limitations

1. **Maximum Capacity**: 100 cars per session (adjustable)
2. **Unique IDs**: Car IDs must be globally unique
3. **Plain Text Storage**: Data stored as plain text (not encrypted)
4. **Memory-Based**: Entire dataset loaded into RAM
5. **Single-User**: No concurrent access control
6. **Limited Validation**: Basic input validation only
7. **No Backup**: No automatic backup of previous data

---

## 🚀 Future Enhancements

- [ ] Database integration (SQLite/MySQL)
- [ ] Advanced search filters (by brand, year range, price range)
- [ ] Data export to CSV/JSON formats
- [ ] User authentication system
- [ ] GUI interface (Qt, GTK, or FLTK)
- [ ] Network capabilities for remote access
- [ ] Vehicle maintenance tracking
- [ ] Sales and rental history
- [ ] Fuel efficiency tracking
- [ ] Insurance information storage

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## ❓ FAQ

**Q: Can I run this on macOS?**  
A: Yes! Use `clang++ -Wall -std=c++11 -o car_management car_management_system.cpp`

**Q: How many cars can I store?**  
A: Maximum 100 per session. Modify `const int MAX_CARS = 100` to increase.

**Q: Is my data saved?**  
A: Yes, automatically when you select option 6 (Save and Exit).

**Q: Can I use duplicate car IDs?**  
A: No, the system prevents duplicate IDs.

**Q: What libraries are required?**  
A: Only standard C++ libraries: `<iostream>`, `<fstream>`, `<cstring>`

**Q: Can I edit the data file manually?**  
A: Yes! Follow the format: `ID|Brand|Model|Year|Color|Price` (one car per line)

**Q: Where is the data stored?**  
A: In `cars_data.txt` in the same directory as the executable.

---

## 📜 License

This project is open-source and available under the **MIT License**.

---

## 👨‍💻 About

This project was created to demonstrate fundamental C++ programming concepts including:
- CRUD operations
- File handling (I/O)
- Pointer usage
- Modular programming
- Data structure design
- Control flow and loops
- String manipulation

**Perfect for:**
- Students learning C++
- Interview preparation
- Portfolio projects
- Programming fundamentals practice

---

## 📞 Contact & Support

For issues, questions, or suggestions, please open an **Issue** on GitHub.

---

## ⭐ If you found this helpful, please give it a star!

**Happy Coding! 🎉**
