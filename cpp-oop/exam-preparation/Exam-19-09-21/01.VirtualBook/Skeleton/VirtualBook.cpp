#include "VirtualBook.h"

void VirtualBook::addPage(const VirtualPage& vPage) {
    _vBookVec.push_back(vPage);
}

void VirtualBook::printContent() {
    for (const auto& p: _vBookVec) {
        p.printContent();
    }
}

void VirtualBook::removeLastPage() {
    _vBookVec.pop_back();
}

void VirtualBook::removeAllPages() {
    _vBookVec.clear();
}
