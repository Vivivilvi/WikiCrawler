#pragma once
#include <string>
#include <vector>

class LinkParser {
public:
    std::vector<std::string> extractWikiLinks(const std::string& filename);
};
