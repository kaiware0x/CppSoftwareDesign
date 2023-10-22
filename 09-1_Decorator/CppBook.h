#ifndef CPP_BOOK_H
#define CPP_BOOK_H

#include <string>
#include <utility>

#include "Item.h"

class CppBook : public Item {
   public:
    CppBook(std::string title, Money price)
        : m_title(std::move(title)), m_price(price) {}

    const std::string& title() const { return m_title; }
    Money price() const override { return m_price; }

   private:
    std::string m_title{};
    Money m_price{};
};

#endif  // CPP_BOOK_H