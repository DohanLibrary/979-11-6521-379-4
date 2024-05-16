// 1.3 std::array 설명

#include <array>  // std::array
#include <iostream>

/* 크기가 고정된 배열 내 모든 원소 출력 함수
void print(std::array<int, 5> arr) {
    // 함수에 전달된 객체는 새로운 std::array 객체로 깊은 복사가 동작함
    for (auto ele : arr) std::cout << ele << ", ";
}
*/

template <size_t N>
void print(const std::array<int, N>& arr) {
    // 함수 매개 변수로 Const 참조를 사용함 - 깊은 복사가 동작하지 않음
    for (auto ele : arr)
        std::cout << ele << ", ";  // 범위 기반 for문 with 반복자

    std::cout << std::endl;

    for (auto it = arr.begin(); it != arr.end(); it++) {
        // 위 문법과 동일하게 동작함
        auto ele = (*it);
        std::cout << ele << ", ";
    }

    std::cout << std::endl;
}

int main() {
    std::array<int, 10> arr1;

    arr1[0] = 1;
    std::cout << "arr1 배열의 첫 번째 원소: " << arr1[0] << std::endl;

    std::array<int, 4> arr2 = {1, 2, 3, 4};
    std::cout << "arr2 배열의 모든 원소: ";

    for (int i = 0; i < arr2.size(); i++) std::cout << arr2[i] << " ";
    std::cout << std::endl;

    try {
        std::cout << arr2.at(3) << std::endl;
        std::cout << arr2.at(4) << std::endl;
    } catch (const std::out_of_range& ex) {
        std::cerr << ex.what() << std::endl;
    }

    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    print(arr3);

    std::array<int, 10> arr4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr4);

    std::cout << arr4.front() << std::endl;
    std::cout << arr4.back() << std::endl;
    std::cout << *(arr4.data() + 1) << std::endl;

    return 0;
}