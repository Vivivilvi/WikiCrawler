#include "WikiCrawler.h"
#include <iostream>

int main() {
    std::string startUrl;
    std::cout << "Enter the Wikipedia path (e.g. /wiki/C++): ";
    std::cin >> startUrl;

    WikiCrawler crawler("https://en.wikipedia.org", "/wiki/Adolf_Hitler", 6);

    std::vector<std::string> path;
    if (crawler.searchPath(startUrl, path)) {
        std::cout << "\nPath to Hitler found!\n";
        for (size_t i = 0; i < path.size(); ++i)
            std::cout << "Step " << i + 1 << ": " << path[i] << "\n";
        std::cout << "Step " << path.size() + 1 << ": /wiki/Adolf_Hitler\n";
    }
    else {
        std::cout << "\nHitler not found within 6 steps.\n";
        if (!path.empty()) {
            std::cout << "Partial path followed:\n";
            for (size_t i = 0; i < path.size(); ++i)
                std::cout << "Step " << i + 1 << ": " << path[i] << "\n";
        }
    }

    return 0;
}
