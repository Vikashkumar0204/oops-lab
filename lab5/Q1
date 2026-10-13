#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>

// Base class managing core data and shared formatting routines
class CatalogItem {
protected:
    std::string title;
    std::string author;
    std::string isbn;
    double price;

public:
    CatalogItem(std::string t, std::string a, std::string i, double p)
        : title(move(t)), author(move(a)), isbn(i), price(p) {}

    virtual ~CatalogItem() = default;

    // Core formatting routine reused by all derived classes
    void printCoreDetails() const {
        std::cout << std::left << std::setw(25) << title 
                  << std::setw(20) << author 
                  << std::setw(15) << isbn 
                  << "$" << std::fixed << std::setprecision(2) << price;
    }

    // Pure virtual function to force media-specific details
    virtual void displayListing() const = 0;
};

// Derived class for Physical Books
class PhysicalBook : public CatalogItem {
private:
    int pageCount;
    double weightKg;

public:
    PhysicalBook(std::string t, std::string a, std::string i, double p, int pages, double weight)
        : CatalogItem(move(t)), move(a)), i, p), pageCount(pages), weightKg(weight) {}

    void displayListing() const override {
        // Reuse core formatting
        printCoreDetails();
        // Append physical-specific formatting
        std::cout << " | Type: Physical | Pages: " << pageCount 
                  << " | Weight: " << weightKg << "kg\n";
    }
};

// Derived class for Digital EBooks
class EBook : public CatalogItem {
private:
    std::string fileFormat;
    double fileSizeMB;

public:
    EBook(std::string t, std::string a, std::string i, double p, std::string format, double size)
        : CatalogItem(move(t)), move(a)), i, p), fileFormat(move(format)), fileSizeMB(size) {}

    void displayListing() const override {
        // Reuse core formatting
        printCoreDetails();
        // Append digital-specific formatting
        std::cout << " | Type: Digital   | Format: " << fileFormat 
                  << " | Size: " << fileSizeMB << "MB\n";
    }
};

int main() {
    // Vector handling heterogeneous catalog items via base class pointers
    std::vector<std::unique_ptr<CatalogItem>> catalog;

    // Populating catalog
    catalog.push_back(std::make_unique<PhysicalBook>(
        "The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842", 62.99, 1360, 1.8
    ));
    
    catalog.push_back(std::make_unique<EBook>(
        "Effective Modern C++", "Scott Meyers", "978-1491903995", 45.50, "EPUB", 4.2
    ));

    // Print headers
    std::cout << std::left << std::setw(25) << "TITLE" 
              << std::setw(20) << "AUTHOR" 
              << std::setw(15) << "ISBN" 
              << "PRICE   | METADATA\n";
    std::cout << std::string(100, '-') << "\n";

    // Process and display all listings polymorphically
    for (const auto& item : catalog) {
        item->displayListing();
    }

    return 0;
}
