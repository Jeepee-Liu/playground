#include "Fuzzy.h"
#ifdef FUZZY_H
Fuzzy::StateMaxT Fuzzy::stateMax{1./3,2./3,1.0};


/* Constructors & destructors */

Fuzzy::Fuzzy() : _val(0.5) {}

Fuzzy::Fuzzy(FuzzyValT v) : _val(v) {
    validate();
}

Fuzzy::Fuzzy(const Fuzzy& fz) : _val(fz._val) {}


/* Methods: Logical operations */

Fuzzy Fuzzy::fzAND(const Fuzzy& fz) const {
    // Fuzzy tempFz(std::min(fz._val, _val));
    // std::cout << "In function: " << tempFz << '\t'
    // << &tempFz << std::endl;
    return std::move(Fuzzy(std::min(fz._val, _val)));
}

Fuzzy Fuzzy::fzOR(const Fuzzy& fz) const {
    return std::move(Fuzzy(std::max(fz._val, _val)));
}

Fuzzy Fuzzy::fzNOT() const {
    return std::move(Fuzzy(1 - _val));
}

Fuzzy Fuzzy::fzXOR(const Fuzzy& fz) const {
    /** a XOR b
     *
     * b
     * ^
     * |
     * |  1-a
     * |b     1-b
     * |   a
     * +-----------> a
     *
     **/

    // val = std::max(std::min(a, 1 - b), std::min(1 - a, b))
    if ( _val > fz._val && fz._val < 1 - _val ) {
        return std::move(Fuzzy(_val));
    } else if ( _val > fz._val && fz._val >= 1 - _val ) {
        return std::move(Fuzzy(1 - fz._val));
    } else if ( fz._val < 1 - _val ) {
        return std::move(Fuzzy(fz._val));
    } else {
        return std::move(Fuzzy(1 - _val));
    }
}

Fuzzy& Fuzzy::validate() {
    _val = std::min(std::max(_val, 0.0), 1.0);
    return *this;
}

/* Setter and getter */

void Fuzzy::setVal(FuzzyValT v) {
    _val = v;
    validate();
}

Fuzzy::FuzzyValT Fuzzy::getVal() const {
    return _val;
}

Fuzzy::StateIdxT Fuzzy::getState() const {
    StateIdxT s = 0;
    for(const auto& maxVal: stateMax) {
        if(_val > maxVal) {
            s++;
        } else {
            break;
        }
    }
    return s;
}



std::ostream& operator<<(std::ostream& os, const Fuzzy& fz) {
    os << fz.getVal();
    return os;
}

#endif
