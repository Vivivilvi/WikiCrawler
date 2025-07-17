#pragma once
#include <string>

class SystemDownloader {
public:
    std::string download(const std::string& url, const std::string& outputFilename = "page.html");
};
