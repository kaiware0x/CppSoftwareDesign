#ifndef TAXED_H
#define TAXED_H

#include <cmath>

#include "DecoratedItem.h"

class Taxed : public DecoratedItem {
   public:
    Taxed(double tax_rate, std::unique_ptr<Item> item)
        : DecoratedItem(std::move(item)), m_factor(1.0 + tax_rate) {
        if (!std::isfinite(tax_rate) || tax_rate < 0.0) {
            throw std::invalid_argument("Invalid tax rate");
        }
    }

    Money price() const override { return item().price() * m_factor; }

   private:
    double m_factor;
};

#endif  // TAXED_H