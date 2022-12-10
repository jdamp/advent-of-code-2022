#pragma once

#include <iostream>
#include <set>
#include <string>
#include <vector>

namespace AOCTools {
    std::vector<std::string> parseFile(std::string const& path);

    std::vector<std::string> splitString(std::string const& str, std::string const& delimiter);

    template <typename T> 
    std::set<T> setUnion(std::set<T> firstSet, std::set<T> otherSet) {
        std::set<T> outSet;
        for (auto element: firstSet) {
            if (otherSet.count(element) > 0) {
                outSet.insert(element);
            }
        }
        return outSet;
    }
    template <typename T>
    void printSet(std::set<T> theSet) {
        std::cout << "{";
        for(T const& item: theSet) {
            std::cout << item << ", ";
        }
        std::cout << "}\n";
    }

}