#include "SystemDownloader.h"
#include <cstdlib>

std::string SystemDownloader::download(const std::string& url, const std::string& outputFilename) {
    std::string command = "curl -s \"" + url + "\" -o " + outputFilename;
    std::system(command.c_str());
    return outputFilename;
}
