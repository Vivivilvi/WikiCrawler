#pragma once
#include <string>
#include <vector>
#include <set>

class WikiCrawler {
public:
    WikiCrawler(const std::string& baseUrl, const std::string& targetPage, int maxDepth);

    bool searchPath(const std::string& startPage, std::vector<std::string>& path);

private:
    std::string baseUrl;
    std::string targetPage;
    int maxDepth;
    std::set<std::string> visited;
};
