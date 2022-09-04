#include "Store.h"

void Store::addPs(int price, int quality, int generation) {
    _pSConsolesVec.emplace_back(price, quality, generation);

    std::cout << "Adding: PS with generation " << generation << ", price: " << price 
    << ", quality: " << quality << std::endl;
}

void Store::addXbox(int price, int quality) {
    _xBoxConsolesVec.emplace_back(price, quality);

    std::cout << "Adding: Xbox with price: " << price << ", quality: " << quality << std::endl;
}

void Store::remove(ConsoleType ctype) {
    if (ctype == ConsoleType::PS) {
        auto last = _pSConsolesVec.back();
        _pSConsolesVec.pop_back();
        
        std::cout << "Removing: PC with generation " << last.getGeneration() << ", price: " << 
        last.getPrice() << ", quality: " << last.getQuality() << std::endl;

    } else if (ctype == ConsoleType::XBOX) {
        auto last = _xBoxConsolesVec.back();
        _xBoxConsolesVec.pop_back();

        std::cout << "Removing: Xbox with price: " << last.getPrice() << ", quality: " 
        << last.getQuality() << std::endl;
    }
}

void Store::sortByPrice(ConsoleType ctype) {
    if (ctype == ConsoleType::PS) {
        std::cout << "Sorting all PS by price" << std::endl;
        std::sort(_pSConsolesVec.begin(), _pSConsolesVec.end(), [](const PS& c1, const PS& c2) { 
            return c1.getPrice() > c2.getPrice();
        });

    } else if (ctype == ConsoleType::XBOX) {
        std::cout << "Sorting all Xbox by price" << std::endl;
        std::sort(_xBoxConsolesVec.begin(), _xBoxConsolesVec.end(), [](const Xbox& c1, const Xbox& c2) { 
            return c1.getPrice() > c2.getPrice();
        });
    }
}

void Store::sortByQuality(ConsoleType ctype) {
    if (ctype == ConsoleType::PS) {
        std::cout << "Sorting all PS by quality" << std::endl;
        std::sort(_pSConsolesVec.begin(), _pSConsolesVec.end(), [](const PS& c1, const PS& c2) { 
            return c1.getQuality() > c2.getQuality();
        });

    } else if (ctype == ConsoleType::XBOX) {
        std::cout << "Sorting all Xbox by quality" << std::endl;
        std::sort(_xBoxConsolesVec.begin(), _xBoxConsolesVec.end(), [](const Xbox& c1, const Xbox& c2) { 
            return c1.getQuality() > c2.getQuality();
        });
    }
}

void Store::print(ConsoleType ctype) {
    if (ctype == ConsoleType::PS) {
        std::cout << "Printing all PS data" << std::endl;
        for (const auto& c : _pSConsolesVec) {
            std::cout << "PS with price: " << c.getPrice() << ", quality: " << c.getQuality() << std::endl;
        }
    } else if (ctype == ConsoleType::XBOX) {
        std::cout << "Printing all Xbox data" << std::endl;
        for (const auto& c : _xBoxConsolesVec) {
            std::cout << "Xbox with price: " << c.getPrice() << ", quality: " << c.getQuality() << std::endl;
        }
    }
}
