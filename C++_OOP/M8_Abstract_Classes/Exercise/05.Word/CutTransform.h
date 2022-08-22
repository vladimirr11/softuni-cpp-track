#ifndef CUTTRANSFORM_H
#define CUTTRANSFORM_H

#include "TextTransform.h"

static std::string cuttedText;

class CutTransform : public TextTransform {
public:
    void invokeOn(std::string& text, int startIndex, int endIndex) override {
        if (startIndex != endIndex) {
            std::string textCopy = text;
            text.erase(startIndex, endIndex - startIndex);

            cuttedText = textCopy.substr(startIndex, endIndex - startIndex);
        } else {
            cuttedText.clear();
        }
    }
};

#endif // !CUTTRANSFORM_H
