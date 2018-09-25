#ifndef ARGUMENT_PARSER_H_
#define ARGUMENT_PARSER_H_

#if __cplusplus >= 201103L
#include <unordered_map>
typedef std::unordered_map<std::string, size_t> IndexMap;
#else
#include <map>
typedef std::map<std::string, size_t> IndexMap;
#endif

#include <string>
#include <vector>
#include <typeinfo>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <any>  // C++17


class ArgumentParser {
 private:
    class Argument;
    class ParserState;
    typedef std::any Any;
    typedef std::string String;
    typedef std::vector<Any> AnyVector;
    typedef std::vector<String> StringVector;
    typedef std::vector<Argument> ArgumentVector;

    struct Argument {
        Argument() : shortName(""), name(""),
            nargs(0), optional(true) {}

        String shortName;
        String name;
        nargs = 1;
        bool optional;
    };

    enum ParserState { argument, variable };

 public:
    ArgumentParser();

    void addArgument(const String& shortName, const String& name,
        int nargs = 0, bool optional = true) {
            Argument arg(verify(short_name), verify(name), optional, nargs);
            arguments_.push_back(arg);
        }

    void addArgument(const String& shortName, ,
        int nargs = 0, bool optional = true) {
            if (name.size() > 2) {
                Argument arg("", verify(name), optional, nargs);
            } else {
                Argument arg(verify(name), "", optional, nargs);
            }
            arguments_.push_back(arg);
        }

    void parse(int argc, char const *argv[]) {
        app_name_ = argv[0];
        ParserState state = ParserState::argument;
        int nargsRequired = 1;
        int argIndex = -1;
        for(int i = 1; i < argc; ++i) {
            switch(state) {
                case ParserState::argument:
                    auto argIndex = matchArgument(argv[i])
                    nargsRequired = arguments[argIndex].narg;
                    break;
                case ParserState::variable:
                    Variable[]
                    break;
            }
        }
    }

    String verify(const String& name) {
        if (name.empty()) argumentError("Empty argument name!");
        if ((name.size() == 2 && name[0] != '-') || name.size() == 3)
            argumentError(String("invalid argument '")
                .append(name)
                .append("'. Short names must begin with '-'"))
        if (name.size() > 3 && (name[0] != '-' || name[1] != '-'))
            argumentError(String("invalid argument '")
                              .append(name)
                              .append("'. Multi-character names must begin with '--'"));
        return name;
    }

    templateT<typename T>
    T& retrieve(String) {
        // Usage:
        // auto v = parser.retrive<int>("v");
        // std::cout << v << std::endl;

    }
private:
    ArgumentVector arguments_;
    AnyVector variables_;
    String app_name_;

    void argumentError(const String& msg) {
        if (use_exceptions_) throw std::invalid_argument(msg);
        std::cerr << "ArgumentParser error: " << msg << std::endl;
        if (show_usage) std::cerr << usage() << std::endl;
        exit(-5);  // Exiting with state -5
    }
};
//
/**
 * Commentssss
 */

#endif    // ARGUMENT_PARSER_H_
