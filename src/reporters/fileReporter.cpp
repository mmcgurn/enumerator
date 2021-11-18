#include "fileReporter.hpp"

enumerator::reporters::FileReporter::FileReporter(std::filesystem::path outputPath) : StreamReporter(outputFileStream) { outputFileStream.open(outputPath, std::fstream::out); }
enumerator::reporters::FileReporter::~FileReporter() { outputFileStream.close(); }

#include "registrar.hpp"
REGISTER(enumerator::Reporter, enumerator::reporters::FileReporter, "Reports all cases to a simple ASCII file", ARG(std::filesystem::path, "path", "the path to the output file"));