#ifndef ENUMERATOR_FILEREPORTER_HPP
#define ENUMERATOR_FILEREPORTER_HPP

#include <filesystem>
#include <fstream>
#include <iostream>
#include "streamReporter.hpp"
namespace enumerator::reporters {

class FileReporter : public StreamReporter {
   private:
    std::fstream outputFileStream;

   public:
    explicit FileReporter(std::filesystem::path outputPath);
    ~FileReporter() override;
};

}  // namespace enumerator::reporters
#endif  // ENUMERATOR_FILEREPORTER_HPP
