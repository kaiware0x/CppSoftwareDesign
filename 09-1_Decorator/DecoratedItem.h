#ifndef DECORATED_ITEM_H
#define DECORATED_ITEM_H

#include <memory>
#include <stdexcept>
#include <utility>

#include "Item.h"

class DecoratedItem : public Item {
   public:
    explicit DecoratedItem(std::unique_ptr<Item> item)
        : m_item(std::move(item)) {
        if (!m_item) {
            throw std::invalid_argument("Invalid item");
        }
    }

   protected:
    Item& item() { return *m_item; }
    const Item& item() const { return *m_item; }

   private:
    std::unique_ptr<Item> m_item;
};

#endif  // DECORATED_ITEM_H