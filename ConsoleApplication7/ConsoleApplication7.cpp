#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>

void task1() {
    std::vector<int> v = { 1, 2, 3, 4, 5 }; 
    std::for_each(v.begin(), v.end(), [](int& n) { n *= 2; }); 

    for (const auto& n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void task2() {
    std::vector<int> v = { -1, 2, 3, -4, 5, -6, 7, 8, -9, 10 }; 
    int count = 0;

    std::for_each(v.begin(), v.end(), [&count](int n) {
        if (n > 0) count++;
        });

    std::cout << "Количество положительных чисел: " << count << '\n';
}

void task3() {
    std::vector<int> source = { 1, 2, 3 }; 
    std::vector<int> destination(20, 0); 

    std::copy(source.begin(), source.end(), destination.begin() + 0); 
    std::copy(source.begin(), source.end(), destination.begin() + 5); 
    std::copy(source.begin(), source.end(), destination.begin() + 10); 

    for (const auto& n : destination) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void task4() {
    std::vector<int> source = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    std::vector<int> destination(10, 0); 

    std::copy(source.rbegin() + 4, source.rbegin() + 8, destination.begin()); 

    for (const auto& n : destination) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void task5() {
    std::vector<int> v = { 1, 2, 3, 10, 5, 6, 333, 8, 9, 44 }; 
    std::vector<int> numbers_to_find = { 10, 333, 44 };

    for (int number : numbers_to_find) {
        if (std::find(v.begin(), v.end(), number) != v.end()) {
            std::cout << "Число " << number << " найдено в векторе.\n";
        }
        else {
            std::cout << "Число " << number << " не найдено в векторе.\n";
        }
    }
}

void task6() {
    std::vector<int> v = { 10, 15, 20, 25, 30, 35, 40, 45, 50, 55 }; 

    v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x > 10 && x < 100 && x % 2 != 0; }), v.end());

    for (const auto& n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

void task7() {
    std::ifstream file("war_and_peace.ru.txt"); 
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл." << std::endl;
        return; 
    }

    std::string line;
    std::unordered_map<std::string, int> word_count;

    // Читаем файл построчно
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
           
            word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
                return std::ispunct(c); 
                }), word.end());
      
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!word.empty()) { 
                ++word_count[word]; 
            }
        }
    }

   
    std::vector<std::pair<std::string, int>> sorted_word_count(word_count.begin(), word_count.end());
    std::sort(sorted_word_count.begin(), sorted_word_count.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    int ten_percent = sorted_word_count.size() / 10; 
    for (int i = 0; i < ten_percent; ++i) {
        word_count.erase(sorted_word_count[i].first); 
        word_count.erase(sorted_word_count[sorted_word_count.size() - 1 - i].first); 
    }

    std::cout << "Количество уникальных слов: " << word_count.size() << '\n'; 
}

int main() {
    setlocale(LC_ALL,"RUS");
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    return 0;
}