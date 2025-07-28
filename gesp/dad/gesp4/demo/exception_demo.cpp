#include <iostream>
#include <stdexcept>

class Resource {
public:
    Resource() { std::cout << "Resource acquired" << std::endl; }
    ~Resource() { std::cout << "Resource released" << std::endl; }
};

void riskyOperation() {
    Resource res; // RAII 对象
    std::cout << "Inside riskyOperation" << std::endl;
    throw std::runtime_error("Something went wrong");
}

int main() {
    try {
        riskyOperation();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}