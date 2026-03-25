#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_CARS = 100;
const char DATA_FILE[] = "cars_data.txt";

struct Car {
    int id;
    char brand[50];
    char model[50];
    int year;
    char color[30];
    double price;
};

Car cars[MAX_CARS];
int car_count = 0;

void loadFromFile();
void saveToFile();
void displayMenu();
void addCar();
void viewAllCars();
void searchCar();
void updateCar();
void deleteCar();
void displayCar(Car *c);
bool carExists(int id);
int findCarIndex(int id);

void loadFromFile() {
    ifstream file(DATA_FILE);
    
    if (file.is_open()) {
        car_count = 0;
        while (car_count < MAX_CARS && file >> cars[car_count].id) {
            file.ignore();
            file.getline(cars[car_count].brand, 50, '|');
            file.getline(cars[car_count].model, 50, '|');
            file >> cars[car_count].year;
            file.ignore();
            file.getline(cars[car_count].color, 30, '|');
            file >> cars[car_count].price;
            file.ignore();
            car_count++;
        }
        file.close();
    }
}

void saveToFile() {
    ofstream file(DATA_FILE);
    
    if (file.is_open()) {
        for (int i = 0; i < car_count; i++) {
            file << cars[i].id << "|"
                 << cars[i].brand << "|"
                 << cars[i].model << "|"
                 << cars[i].year << "|"
                 << cars[i].color << "|"
                 << cars[i].price << "\n";
        }
        file.close();
        cout << "\n>> Data saved successfully!\n";
    } else {
        cout << "\n>> Error: Could not open file for saving!\n";
    }
}

void displayMenu() {
    cout << "\n========================================\n";
    cout << "   CAR MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add a new car\n";
    cout << "2. View all cars\n";
    cout << "3. Search for a car\n";
    cout << "4. Update car information\n";
    cout << "5. Delete a car\n";
    cout << "6. Save and Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice (1-6): ";
}

void displayCar(Car *c) {
    cout << "\n  ID: " << c->id
         << " | Brand: " << c->brand
         << " | Model: " << c->model
         << " | Year: " << c->year
         << " | Color: " << c->color
         << " | Price: $" << c->price << "\n";
}

bool carExists(int id) {
    for (int i = 0; i < car_count; i++) {
        if (cars[i].id == id) {
            return true;
        }
    }
    return false;
}

int findCarIndex(int id) {
    for (int i = 0; i < car_count; i++) {
        if (cars[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addCar() {
    if (car_count >= MAX_CARS) {
        cout << "\n>> Error: Maximum cars limit reached!\n";
        return;
    }
    
    cout << "\n--- ADD NEW CAR ---\n";
    
    int id;
    cout << "Enter Car ID: ";
    cin >> id;
    
    if (carExists(id)) {
        cout << ">> Error: Car with this ID already exists!\n";
        return;
    }
    
    cars[car_count].id = id;
    
    cin.ignore();
    cout << "Enter Brand: ";
    cin.getline(cars[car_count].brand, 50);
    
    cout << "Enter Model: ";
    cin.getline(cars[car_count].model, 50);
    
    cout << "Enter Year: ";
    cin >> cars[car_count].year;
    
    cin.ignore();
    cout << "Enter Color: ";
    cin.getline(cars[car_count].color, 30);
    
    cout << "Enter Price: $";
    cin >> cars[car_count].price;
    
    car_count++;
    cout << "\n>> Car added successfully!\n";
}

void viewAllCars() {
    if (car_count == 0) {
        cout << "\n>> No cars in the system!\n";
        return;
    }
    
    cout << "\n--- ALL CARS ---\n";
    Car *ptr;
    for (int i = 0; i < car_count; i++) {
        ptr = &cars[i];
        displayCar(ptr);
    }
    cout << "\nTotal Cars: " << car_count << "\n";
}

void searchCar() {
    if (car_count == 0) {
        cout << "\n>> No cars in the system!\n";
        return;
    }
    
    cout << "\n--- SEARCH CAR ---\n";
    int id;
    cout << "Enter Car ID to search: ";
    cin >> id;
    
    int index = findCarIndex(id);
    
    if (index != -1) {
        cout << "\n>> Car found!\n";
        Car *carPtr = &cars[index];
        displayCar(carPtr);
    } else {
        cout << "\n>> Car with ID " << id << " not found!\n";
    }
}

void updateCar() {
    if (car_count == 0) {
        cout << "\n>> No cars in the system!\n";
        return;
    }
    
    cout << "\n--- UPDATE CAR ---\n";
    int id;
    cout << "Enter Car ID to update: ";
    cin >> id;
    
    int index = findCarIndex(id);
    
    if (index == -1) {
        cout << "\n>> Car with ID " << id << " not found!\n";
        return;
    }
    
    cout << "\n>> Current car information:\n";
    Car *carPtr = &cars[index];
    displayCar(carPtr);
    
    cin.ignore();
    cout << "\nEnter new Brand (or press Enter to keep current): ";
    char temp_brand[50];
    cin.getline(temp_brand, 50);
    if (strlen(temp_brand) > 0) {
        strcpy(cars[index].brand, temp_brand);
    }
    
    cout << "Enter new Model (or press Enter to keep current): ";
    char temp_model[50];
    cin.getline(temp_model, 50);
    if (strlen(temp_model) > 0) {
        strcpy(cars[index].model, temp_model);
    }
    
    cout << "Enter new Year (or 0 to keep current): ";
    int temp_year;
    cin >> temp_year;
    if (temp_year != 0) {
        cars[index].year = temp_year;
    }
    
    cin.ignore();
    cout << "Enter new Color (or press Enter to keep current): ";
    char temp_color[30];
    cin.getline(temp_color, 30);
    if (strlen(temp_color) > 0) {
        strcpy(cars[index].color, temp_color);
    }
    
    cout << "Enter new Price (or 0 to keep current): $";
    double temp_price;
    cin >> temp_price;
    if (temp_price != 0) {
        cars[index].price = temp_price;
    }
    
    cout << "\n>> Car updated successfully!\n";
    cout << ">> Updated car information:\n";
    carPtr = &cars[index];
    displayCar(carPtr);
}

void deleteCar() {
    if (car_count == 0) {
        cout << "\n>> No cars in the system!\n";
        return;
    }
    
    cout << "\n--- DELETE CAR ---\n";
    int id;
    cout << "Enter Car ID to delete: ";
    cin >> id;
    
    int index = findCarIndex(id);
    
    if (index == -1) {
        cout << "\n>> Car with ID " << id << " not found!\n";
        return;
    }
    
    cout << "\n>> Car to be deleted:\n";
    Car *carPtr = &cars[index];
    displayCar(carPtr);
    
    char confirm;
    cout << "\nAre you sure you want to delete this car? (y/n): ";
    cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        for (int i = index; i < car_count - 1; i++) {
            cars[i] = cars[i + 1];
        }
        car_count--;
        cout << "\n>> Car deleted successfully!\n";
    } else {
        cout << "\n>> Deletion cancelled!\n";
    }
}

int main() {
    int choice;
    
    loadFromFile();
    cout << "\n>> System initialized. " << car_count << " cars loaded from file.\n";
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                viewAllCars();
                break;
            case 3:
                searchCar();
                break;
            case 4:
                updateCar();
                break;
            case 5:
                deleteCar();
                break;
            case 6:
                saveToFile();
                cout << "\n>> Thank you for using Car Management System!\n\n";
                return 0;
            default:
                cout << "\n>> Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
