#ifndef FIXEDBLOCKPOOL_H
#define FIXEDBLOCKPOOL_H

#include <cstddef>

namespace ks::core::memory {

class FixedBlockPool {

struct Block {
    Block* next;
};

struct FreeNode {
    FreeNode* next;
};

void allocate_block() {

}

public:
    explicit FixedBlockPool(std::size_t chunk_size = 64, std::size_t chunks_per_block = 128)
        : chunk_size(chunk_size),
          chunks_per_block(chunks_per_block)
    {

    }

    ~FixedBlockPool() {
        Block* cur = blocks;
        while (cur) {
            Block* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    template <typename T>
    T allocate(std::size_t size) {

    }

private:
    Block* blocks = nullptr;
    FreeNode* free_list = nullptr;
    std::size_t chunk_size;
    std::size_t chunks_per_block;
};

}


#endif //FIXEDBLOCKPOOL_H
