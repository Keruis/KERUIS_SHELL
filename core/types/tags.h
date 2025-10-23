#ifndef TAGS_H
#define TAGS_H

namespace ks::core::types::tags {

struct Int final {};
struct Float final {};
struct Double final {};
struct String final {};
struct Bool final {};

inline Int toInt;
inline Float toFloat;
inline Double toDouble;
inline String toString;
inline Bool toBool;

}

#endif //TAGS_H
