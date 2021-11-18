#include "streamReporter.hpp"
enumerator::reporters::StreamReporter::StreamReporter(std::ostream& outputStream): outputStream(outputStream) {}

void enumerator::reporters::StreamReporter::Report(const std::string& caseName, const std::map<std::string, std::string>& values) {
    outputStream << caseName << std::endl;
    for(const auto& value: values){
        outputStream << '\t' << value.first << ": " << value.second << std::endl;
    }
}

#include "registrar.hpp"
REGISTERDEFAULT_WITHOUT_ARGUMENTS(enumerator::Reporter, enumerator::reporters::StreamReporter, "Reports all cases to the standard out");