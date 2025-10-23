#ifndef LEFT_PTR_MACRO_H
#define LEFT_PTR_MACRO_H

#define LEFT_PTR_MACRO_C(NAME, FUN)         \
    friend NAME& operator-(NAME& self) {    \
        return self;                        \
    }

#endif //LEFT_PTR_MACRO_H
