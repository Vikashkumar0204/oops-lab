#include <iostream>

// ==========================================
// 1. COMMUNICATION MODULES (With Overlapping Names)
// ==========================================
namespace ModuleA {
    class Comm {
    public:
        void wap() { std::cout << "[Module A] Running WAP protocols...\n"; }
    };
}

namespace ModuleB {
    class Comm {
    public:
        void wap() { std::cout << "[Module B] Booting WAP operations...\n"; }
    };
}

// ==========================================
// 2. THE HARDWARE HUB
// ==========================================
class HardwareHub {
private:
    // Fully resolve the overlapping class types using namespaces
    ModuleA::Comm moduleA;
    ModuleB::Comm moduleB;

public:
    // The Hub controls both modules seamlessly
    void activateHub() {
        std::cout << "Hardware Hub: Activating sub-modules...\n";
        
        // Disambiguate identical calls using the instance names
        moduleA.wap();
        moduleB.wap();
        
        std::cout << "Hardware Hub: Both modules running.\n";
    }
};

// ==========================================
// 3. MAIN ENGINE RUNTIME
// ==========================================
int main() {
    std::cout << "Smart Home Engine: Booting system...\n\n";

    HardwareHub hub;
    hub.activateHub();

    std::cout << "\nSmart Home Engine: System online.\n";
    return 0;
}
