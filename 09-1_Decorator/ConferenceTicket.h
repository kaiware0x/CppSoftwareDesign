#ifndef CONFERENCE_TICKET_H
#define CONFERENCE_TICKET_H

#include <string>
#include <utility>

#include "Item.h"

class ConferenceTicket : public Item {
   public:
    ConferenceTicket(std::string name, Money price)
        : m_name(std::move(name)), m_price(price) {}

    const std::string& name() const { return m_name; }
    Money price() const override { return m_price; }

   private:
    std::string m_name{};
    Money m_price{};
};

#endif  // CONFERENCE_TICKET_H