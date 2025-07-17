#include "LinkParser.h"
#include <fstream>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> LinkParser::extractWikiLinks(const std::string& filename) {
    std::ifstream file(filename);
    std::string html((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::vector<std::string> links;
    std::regex link_regex("<a\\s+href=\"(/wiki/[^\"#:]*)\"");
    auto begin = std::sregex_iterator(html.begin(), html.end(), link_regex);
    auto end = std::sregex_iterator();

    for (auto it = begin; it != end; ++it)
        links.push_back((*it)[1]);

    return links;
}
