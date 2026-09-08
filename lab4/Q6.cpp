#include <iostream>
#include <string>
#include <utility> // Needed for std::move

class Laptop {
private:
    std::string brand;
    int* ram; // Using a pointer to demonstrate Deep Copy and Move semantics

public:
    // 1. DEFAULT CONSTRUCTOR
    // Runs when an object is created with no arguments.
    Laptop() {
        brand = "Unknown Brand";
        ram = new int(4); // Allocates memory for 4GB RAM
        std::cout << "[Default Constructor] Created a basic laptop.\n";
    }

    // 2. PARAMETERIZED CONSTRUCTOR
    // Runs when an object is created with specific starting values.
    Laptop(std::string b, int r) {
        brand = b;
        ram = new int(r); // Allocates memory for the specific RAM value
        std::cout << "[Parameterized Constructor] Created a " << brand << " laptop with " << *ram << "GB RAM.\n";
    }

    // 3. COPY CONSTRUCTOR (Deep Copy)
    // Runs when we create a new object as a duplicate of an existing one.
    Laptop(const Laptop& source) {
        brand = source.brand;
        // ram = source.ram; <-- BAD! That would copy the address (Shallow Copy)
        ram = new int(*source.ram); // Allocates new memory and copies the data (Deep Copy)
        std::cout << "[Copy Constructor] Copied " << brand << " laptop data to a new object.\n";
    }

    // 4. MOVE CONSTRUCTOR
    // Runs when we transfer ownership of resources from a temporary object.
    Laptop(Laptop&& source) noexcept {
        brand = source.brand;
        ram = source.ram; // Steal the data pointer directly from the source
        
        source.ram = nullptr; // Clean up the source object so it points to nothing
        source.brand = "Empty";
        std::cout << "[Move Constructor] Stole resources from temporary " << brand << " laptop.\n";
    }

    // Display function to print object data
    void display() const {
        if (ram != nullptr) {
            std::cout << "Laptop Details: Brand = " << brand << ", RAM = " << *ram << "GB\n\n";
        } else {
            std::cout << "Laptop Details: Empty/Broken Laptop (Resources moved)\n\n";
        }
    }

    // Destructor to free dynamically allocated memory
    ~Laptop() {
        delete ram;
    }
};

int main() {
    // ---- Using the Default Constructor ----
    Laptop standardLaptop; 
    standardLaptop.display();

    // ---- Using the Parameterized Constructor ----
    Laptop gamingLaptop("Asus ROG", 32); 
    gamingLaptop.display();

    // ---- Using the Copy Constructor ----
    Laptop backupLaptop = gamingLaptop; 
    backupLaptop.display();

    // ---- Using the Move Constructor ----
    // std::move turns 'backupLaptop' into a temporary resource that can be "stolen"
    Laptop officeLaptop(std::move(backupLaptop)); 
    
    std::cout << "--- Status after Move --- \n";
    std::cout << "Office Laptop (New Owner):\n";
    officeLaptop.display();
    
    std::cout << "Backup Laptop (Old Owner):\n";
    backupLaptop.display();

    return 0;
}
