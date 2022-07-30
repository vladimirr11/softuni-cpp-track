#ifndef SOLFEGENOTENAMING_H
#define SOLFEGENOTENAMING_H

#include "NoteName.h"

class SolfegeNoteNaming {
public:
    SolfegeNoteNaming() = default;

    NoteName operator()(const std::string& note) const {
        return _translate(note);
    }

private:
    NoteName _translate(const std::string& note) const {
        if (note == "Do") {
            return 'C';
        } else if (note == "Re") {
            return 'D';
        } else if (note == "Mi") {
            return 'E';
        } else if (note == "Fa") {
            return 'F';
        } else if (note == "Sol") {
            return 'G';
        } else if (note == "La") {
            return 'A';
        } else if (note == "Si") {
            return 'B';
        }

        return '?';
    }
};

#endif // !SOLFEGENOTENAMING_H
