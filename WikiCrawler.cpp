#include "WikiCrawler.h"
#include "SystemDownloader.h"
#include "LinkParser.h"
#include <queue>
#include <iostream>

WikiCrawler::WikiCrawler(const std::string& baseUrl, const std::string& targetPage, int maxDepth)
    : baseUrl(baseUrl), targetPage(targetPage), maxDepth(maxDepth) {
}

bool WikiCrawler::searchPath(const std::string& startPage, std::vector<std::string>& path) {
    SystemDownloader downloader;
    LinkParser parser;

    std::queue<std::pair<std::string, std::vector<std::string>>> q;
    q.push({ startPage, {startPage} });
    visited.insert(startPage);

    int step = 0;

    while (!q.empty()) {
        auto front = q.front();
        std::string currentPage = front.first;
        std::vector<std::string> currentPath = front.second;
        q.pop();

        ++step;

        std::string fullUrl = currentPage;
        if (currentPage.rfind("http", 0) != 0) {
            fullUrl = baseUrl + currentPage;
        }

        std::cout << "Step " << step << ": visiting " << fullUrl << "\n";

        std::string filename = downloader.download(fullUrl);
        auto links = parser.extractWikiLinks(filename);

        std::cout << "Found " << links.size() << " links on this page.\n";

        for (const auto& link : links) {
            if (visited.count(link)) continue;
            visited.insert(link);

            auto newPath = currentPath;
            newPath.push_back(link);

            if (link == targetPage) {
                path = newPath;
                return true;
            }

            if (static_cast<int>(newPath.size()) <= maxDepth) {
                q.push({ link, newPath });
            }
        }

        if (step >= maxDepth) {
            break;
        }
    }
    return false;
}
