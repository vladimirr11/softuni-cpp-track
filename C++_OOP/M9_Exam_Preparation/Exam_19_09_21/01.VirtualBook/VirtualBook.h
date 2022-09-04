#ifndef VITUALBOOK_H
#define VITUALBOOK_H

#include "VirtualPage.h"
#include <vector>
#include <string>

class VirtualBook {
public:
    void addPage(const VirtualPage& vPage);

    void printContent();

    void removeLastPage();

    void removeAllPages();

private:
    std::vector<VirtualPage> _vBookVec;
};

#endif // !VITUALBOOK_H
