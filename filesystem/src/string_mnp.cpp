
#include <numeric>
#include <algorithm>
#include <ranges>

#include "common.h"

namespace rng = std::ranges;

// Возвращает размер вектора строк
int totalSize(std::vector<std::string> const& inputs)
{
    return std::accumulate(begin(inputs), end(inputs), 0,
           [](int currentSize, std::string const& input)
           {
               return currentSize + input.size();
           });
}

// Разбивает строку по разделителю - sep
std::vector<std::string> splitStringBySepar(const std::string &string, const char * sep) {
    std::vector<std::string> list;
    std::string::size_type start {0};
    std::string::size_type end;

    while ((end = string.find(sep, start)) != std::string::npos) {
        if (start != end)
            list.push_back(string.substr(start, end - start));
        start = end + 1;
    }

    if (start != string.size())
        list.push_back(string.substr(start));

    return list;
}

// Объеденяет вектор строк в одну строку. Между строками из вектора
// вставляет разделитель - delimiter
std::string joinString(const char * delimiter, std::vector<std::string> const& inputs)
{
    auto result = std::string{};
    result.reserve(totalSize(inputs));

    if (inputs.empty()) return "";
    
    result.insert(end(result), begin(inputs.front()), end(inputs.front()));

    for (auto input = std::next(begin(inputs)); input != end(inputs); ++input)
    {
        result.push_back(*delimiter);
        result.insert(end(result), begin(*input), end(*input));
    }

    return result;
}

// removePunctuationByRanges()
std::string removePunctuation(const std::string& str) {
    string result;

    rng::copy_if(str, std::back_inserter(result),          
                 [](auto& symbol) -> bool {return static_cast<bool>((std::isalpha(symbol) || std::isspace(symbol)));});

    return result;
}

// removePunctuationByIterator()
std::string removePunctuationByIterator(const std::string& str) {
    string result;

    std::copy_if(str.begin(), str.end(),            
                 std::back_inserter(result),          
                 [](auto& symbol) -> bool {return static_cast<bool>((std::isalpha(symbol) || std::isspace(symbol)));});

    return result;
}

// removePunctuationByLoop()
std::string removePunctuationByLoop(const std::string& str) {
    std::string result {str};
    
    for (auto sym = result.begin(); sym != result.end();)  {
        if (!(std::isalpha(*sym) || std::isspace(*sym))) {
            sym = result.erase(sym);
        } else {
            ++sym;
        }
    }

    return result;
}
