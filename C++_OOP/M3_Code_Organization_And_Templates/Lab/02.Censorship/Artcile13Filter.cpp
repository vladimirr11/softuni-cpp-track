#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) : copyrighted(copyrighted) {}

bool Article13Filter::blockIfCopyrighted(std::string s) {
    if (isCopyrighted(s)) {
        blocked.push_back(s);
        return true;
    }
    return false;
}

bool Article13Filter::isCopyrighted(std::string s) {
    if (copyrighted.find(s) != copyrighted.end()) { 
        return true;
    }
    return false;
}

std::vector<std::string> Article13Filter::getBlocked() {
    return blocked;
}
