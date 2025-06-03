#include <vector>
#include <mdspan>
#include <iostream>
#include <numeric>

int main() {
    // 原始数据 (12 个元素，RGBRGBRGB...)
    std::vector<int> nums(12);
    std::iota(nums.begin(), nums.end(), 1);

    // 1. 定义 2D mdspan 的映射 (2行 x 2列)
    using Mapping = std::layout_stride::mapping<std::extents<size_t, 2, 2>>;

    // 2. 自定义步长：
    //   - 行步长 (row stride) = 6 (跳过 2 个 RGB 像素: 0→6)
    //   - 列步长 (col stride) = 3 (跳过 1 个 RGB 像素: 0→3)
    Mapping mapping(std::extents<size_t, 2, 2>{}, std::array<size_t, 2>{6,3});

    // 3. 创建 R/G/B 通道的 mdspan
    auto r_span = std::mdspan(nums.data() + 0, mapping); // R: 0,3,6,9
    auto g_span = std::mdspan(nums.data() + 1, mapping); // G: 1,4,7,10
    auto b_span = std::mdspan(nums.data() + 2, mapping); // B: 2,5,8,11

    // 4. 打印 R 通道
    std::cout << "R channel:\n";
    for (int i = 0; i < r_span.extent(0); ++i) {
        for (int j = 0; j < r_span.extent(1); ++j) {
            std::cout << r_span[i, j] << " ";
        }
        std::cout << "\n";
    }

    // 打印 G 通道
    std::cout << "\nG channel:\n";
    for (int i = 0; i < g_span.extent(0); ++i) {
        for (int j = 0; j < g_span.extent(1); ++j) {
            std::cout << g_span[i, j] << " ";
        }
        std::cout << "\n";
    }

    // 打印 B 通道
    std::cout << "\nB channel:\n";
    for (int i = 0; i < b_span.extent(0); ++i) {
        for (int j = 0; j < b_span.extent(1); ++j) {
            std::cout << b_span[i, j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
