#include <iostream>

int main() {
    int a[4] = {1,0};
    const int* p1 = a;
    int* const p2 = a + 1;
    std::cout << p1 << ' ' << ++(*p1) << std::endl
              << p2 << ' ' << ++p2 << std::endl;  
    return 0;
}