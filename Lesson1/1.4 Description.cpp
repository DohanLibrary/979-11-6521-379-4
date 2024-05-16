#include <algorithm>
#include <iostream>

int main() {
    /*
    // 크기가 0인 벡터 선언
    std::vector<int> vec;

    // 지정한 초기값으로 이루어진 크기가 5인 벡터 선언
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 크기가 10인 벡터 선언
    std::vector<int> vec(10);

    // 크기가 10이고 모든 원소가 5로 초기화된 벡터 선언
    std::vector<int> vec(10, 5);
        */

    std::vector<int> vec;                            // {}
    vec.push_back(1);                                // {1}
    vec.push_back(2);                                // {1, 2}
    vec.insert(vec.begin(), 0);                      // {0, 1, 2}
    vec.insert(find(vec.begin(), vec.end(), 1), 4);  // {0, 4, 1, 2}

    vec.emplace_back(3);          // {0, 4, 1, 2, 3}
    vec.emplace(vec.begin(), 1);  // {1, 0, 4, 1, 2, 3}

    for (const auto &ele : vec) std::cout << ele << " ";
    std::cout << std::endl;

    vec.pop_back();                               // {1, 0, 4, 1, 2}
    vec.erase(vec.begin());                       // {0, 4, 1, 2}
    vec.erase(vec.begin() + 1, vec.begin() + 3);  // {0, 2}

    for (const auto &ele : vec) std::cout << ele << " ";
    std::cout << std::endl;

    vec.clear();                    // 벡터 내 모든 원소 제거
    vec.reserve(sizeof(int) * 15);  // 벡터 용량 지정
    vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec.shrink_to_fit();  // 여분 메모리 공간 해제 - 벡터 크기가 더 이상
                          // 변경되지 않을 때 사용

    for (const auto &ele : vec) std::cout << ele << " ";
    std::cout << std::endl;
}