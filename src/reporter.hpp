#ifndef ENUMERATOR_REPORTER_HPP
#define ENUMERATOR_REPORTER_HPP
namespace enumerator {
class Reporter{
   public:
    virtual ~Reporter() = default;
    virtual void Report(const std::string& caseName, const std::map<std::string, std::string>& values) = 0;
};
}
#endif  // ENUMERATOR_REPORTER_HPP
