#ifndef DENSE_VECTOR_H
#define DENSE_VECTOR_H

template <typename Derived>
class DenseVector {
   protected:
    ~DenseVector() = default;

   public:
    Derived& derived() { return static_cast<Derived&>(*this); }
    const Derived& derived() const {
        return static_cast<const Derived&>(*this);
    }

    size_t size() const { return derived().size(); }

    // decltypeで囲むことで子クラスが返すものをそのまま返すことができる
    decltype(auto) operator[](size_t index) { return derived()[index]; }
    decltype(auto) operator[](size_t index) const { return derived()[index]; }

    decltype(auto) begin() { return derived().begin(); }
    decltype(auto) begin() const { return derived().begin(); }
    decltype(auto) end() { return derived().end(); }
    decltype(auto) end() const { return derived().end(); }
};

#endif

/*
Pros:
- derived()のstatic_castは最適化によってアセンブリ命令を一切生成せず、
  子クラスのオブジェクトを直に操作する
- コンパイラは先に基底クラスをインスタンス化する
- メンバ関数は実際にコールしたときに初めてインスタンス化される
    - これによって子クラスの関数をコールできる


Cons:
- 基底クラスがテンプレートなので、共通の基底クラスが存在しない
- 関連する処理が全てテンプレートになってしまい、ヘッダに実装を書かざるを得ない
*/