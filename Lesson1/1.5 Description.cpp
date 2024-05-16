#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> fwd_list = {1, 2, 3};
    fwd_list.push_front(0);  // {0, 1, 2, 3}

    auto it = fwd_list.begin();
    fwd_list.insert_after(it, 5);  // {0, 5, 1, 2, 3}
    fwd_list.insert_after(it, 6);  // {0, 6, 5, 1, 2, 3}

    fwd_list.emplace_front(7);        // {7, 0, 6, 5, 1, 2, 3}
    fwd_list.emplace_after(++it, 8);  // {7, 0, 6, 8, 5, 1, 2, 3}

    for (const auto &ele : fwd_list) std::cout << ele << " ";
    std::cout << std::endl;

    fwd_list.sort();  // {0, 1, 2, 3, 5, 6, 7, 8}

    for (const auto &ele : fwd_list) std::cout << ele << " ";
    std::cout << std::endl;

    fwd_list.sort(std::greater<int>());  // {8, 7, 6, 5, 3, 2, 1, 0}

    for (const auto &ele : fwd_list) std::cout << ele << " ";
    std::cout << std::endl;

    fwd_list = {2, 53, 1, 0, 4, 10};
    fwd_list.reverse();  // {10, 4, 0, 1, 53, 2}

    for (const auto &ele : fwd_list) std::cout << ele << " ";
    std::cout << std::endl;

    fwd_list = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    fwd_list.unique();  // {0, 1, 0, 1, -1, 10, 5, 10, 0 }

    for (const auto &ele : fwd_list) std::cout << ele << " ";
    std::cout << std::endl;

    fwd_list = {0, 1, 0, 1, -1, 10, 5, 5, 10, 0};
    fwd_list.sort();
    fwd_list.unique();  // {-1, 0, 1, 5, 10}

    for (const auto &ele : fwd_list) std::cout << ele << " ";
    std::cout << std::endl;
}