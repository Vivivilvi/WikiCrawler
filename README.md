# WikiCrawler

A console C++ program that searches for a path from a given Wikipedia article to the article about Adolf Hitler by following the first links on each page.
The program checks up to 6 steps and shows the path if it’s found. Works without third-party libraries (libcurl is not used), downloads pages via the system `curl`.

## How it works
1. You input a Wikipedia article URL, like:  
   `https://de.wikipedia.org/wiki/Erich_Fromm`;
2. The program parses the HTML, finds all internal links;
3. It searches for the shortest path to `/wiki/Adolf_Hitler`.

## What not to use
- Avoid recursion (depth can be huge);
- No fancy frameworks(boost, Qt) or full HTML/CSS renderers;
- Do not process JavaScript — only raw HTML links matter;
- `libcurl`: uses system `curl` instead to avoid pulling dependencies;
- ready-made Wikipedia API - the program works through regular HTML pages from a browser.

## Requirements
- OS: Windows / Linux;
- Visual Studio (C++17);
- Compiler: MSVC, GCC, Clang;
- STL: vector, string, queue, unordered_set;
- Gumbo-parser (or custom HTML parser).

## To download pages:
- on Windows — `curl.exe` (built-in since Win10) or PowerShell;
- on Linux — regular `curl`.
  
## Why
The project was written as part of training skills:
- Working with HTTP and HTML in C++;
- Implementing BFS and parsing links;
- Designing an architecture with division by files.

## Possible improvements
- Switch to multithreading;
- Parallelized link crawling;
- Caching of already loaded pages;
- Support for selecting a target article (not only Hitler);
- Web interface or log to file.
