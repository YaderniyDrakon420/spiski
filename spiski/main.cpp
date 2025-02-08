#include <iostream>
#include "List.h"


int main() {
    List<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(0);

    std::cout << "Front: " << lst.front() << "\n"; 
    std::cout << "Back: " << lst.back() << "\n";   

    lst.pop_front();
    lst.pop_back();

    std::cout << "Front after pop_front: " << lst.front() << "\n"; 
    std::cout << "Back after pop_back: " << lst.back() << "\n";   

    lst.clear();
    std::cout << "List is empty: " << lst.empty() << "\n"; 

    return 0;
}


