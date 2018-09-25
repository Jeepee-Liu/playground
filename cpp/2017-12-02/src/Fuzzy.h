#ifndef FUZZY_H
#define FUZZY_H

#include <iostream>
#include <utility>
#include <vector>

class Fuzzy {
    /* Friend function(s) */
    // friend std::ostream& operator<<(
    //     std::ostream& os, const Fuzzy& fz);

public:
    typedef double FuzzyValT;
    typedef uint32_t StateIdxT;
    typedef std::vector<FuzzyValT> StateMaxT;

    /* Constructors & destructors */
    Fuzzy();
    Fuzzy(FuzzyValT v);
    Fuzzy(const Fuzzy& fz);
    ~Fuzzy() = default;

    static StateMaxT stateMax;

    /* Methods: Fuzzy logic operations */
    Fuzzy fzAND(const Fuzzy& fz) const;
    Fuzzy fzOR(const Fuzzy& fz) const;
    Fuzzy fzNOT() const;
    Fuzzy fzXOR(const Fuzzy& fz) const;


    /* setter and getter */
    void setVal(FuzzyValT v);
    FuzzyValT getVal() const;
    StateIdxT getState() const;

    Fuzzy& validate();

private:

    FuzzyValT _val;
};


std::ostream& operator<<(std::ostream& os, const Fuzzy& fz);

#endif
