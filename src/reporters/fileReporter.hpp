#ifndef ENUMERATOR_FILEREPORTER_HPP
#define ENUMERATOR_FILEREPORTER_HPP

#include "streamReporter.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
namespace enumerator::reporters {

class FileReporter: public StreamReporter {
   private:
    std::fstream outputFileStream;

   public:
    explicit FileReporter(std::filesystem::path outputPath);
    ~FileReporter() override;
};

}
#endif  // ENUMERATOR_FILEREPORTER_HPP
