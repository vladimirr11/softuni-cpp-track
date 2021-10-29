#ifndef FIELD_H
#define FIELD_H

#include "Defines.h"

class Field {
public:
    void populateField(const FieldData& fdata);

    FieldData& getFieldData();

private:
    FieldData _field;

};

#endif // !FIELD_H
