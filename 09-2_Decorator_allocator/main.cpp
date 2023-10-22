#include <array>
#include <cstddef>
#include <cstdlib>
#include <memory_resource>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::array<std::byte, 1000> raw;

    // raw配列にメモリ領域を割り当てる
    std::pmr::monotonic_buffer_resource buffer{
        raw.data(), raw.size(), std::pmr::null_memory_resource()};

    // 動的にメモリを割り当てることもできる
    // std::pmr::monotonic_buffer_resource
    // buffer{std::pmr::new_delete_resource()};

    // bufferを指定してvectorを生成
    std::pmr::vector<std::pmr::string> strings{&buffer};

    // stringsがメモリを要求するとbufferから割り当てられる。
    strings.emplace_back("String longer than what SSO can handle");
    strings.emplace_back("Another long string that goes beyond SSO");
    strings.emplace_back("A third long string that cannot be handled by SSO");
    strings.emplace_back("A third long string that cannot be handled by SSO");
    strings.emplace_back("A third long string that cannot be handled by SSO");
    strings.emplace_back("A third long string that cannot be handled by SSO");
    strings.emplace_back("A third long string that cannot be handled by SSO");

    return 0;
}
