#ifndef PASTETRANSFORM_H
#define PASTETRANSFORM_H

#include "TextTransform.h"
#include "CutTransform.h"


class PasteTransform : public CutTransform {
public:
    void invokeOn(std::string& text, int startIndex, int endIndex) override {
        text.replace(startIndex, endIndex - startIndex, cuttedText);
    }

};

#endif // !PASTETRANSFORM_H
