#ifndef CUSTOM_ALLOCATOR_H
#define CUSTOM_ALLOCATOR_H

#include <cstdlib>
#include <memory_resource>

class CustomAllocator : public std::pmr::memory_resource {
   public:
    CustomAllocator(std::pmr::memory_resource* upstream)
        : m_upstream(upstream) {}

   private:
    /**
     * メモリを割り当てる
     */
    void* do_allocate(size_t bytes, size_t alignment) override;

    /**
     * メモリを解放する
     */
    void do_deallocate(void* ptr, [[maybe_unused]] size_t bytes,
                       [[maybe_unused]] size_t alignment) override;

    /**
     * 2つのアロケータが等価かを検査する
     */
    bool do_is_equal(
        const std::pmr::memory_resource& other) const noexcept override;

   private:
    std::pmr::memory_resource* m_upstream{};
};

#endif  // CUSTOM_ALLOCATOR_H