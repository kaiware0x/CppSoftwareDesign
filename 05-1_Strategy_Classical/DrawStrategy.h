#ifndef DRAW_STRATEGY_H
#define DRAW_STRATEGY_H

/// @brief アーキテクチャ上位：どのクラスにも依存しない
/// @tparam T
template <class T>
class DrawStrategy {
   public:
    virtual ~DrawStrategy() = default;
    virtual void draw(const T&) const = 0;
};

#endif
