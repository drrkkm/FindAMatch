//
// Created by sibenshtern on 08.11.22.
//

#ifndef GRAPHICS_SCHEME_H
#define GRAPHICS_SCHEME_H

#include <vector>

namespace Login {
    class Operation {};
    class Element {
    public:
        operator bool() const {return out;};
        void set_callback(callback f) {cp = f};
        void add_output(*Operation op) {outputs.push_back(op);};
    protected:
        Element(bool val, OutType type = OutType::NotInverted): out{val}, is_inverted{type} {};
        void set(bool);
    private:
        bool out;
        OutType is_inverted;
        std::vector<*Operation> outputs;
        callback cb;

        friend Element &operator >> (Element &lhs, Operation &rhs);
        friend Element &operator >> (Element &lhs, Connection rhs);
        friend void check_loop(const Element &loop, const Element &elem);
    };
}

#endif //GRAPHICS_SCHEME_H
