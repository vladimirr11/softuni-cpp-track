#include "Field.h"

void Field::populateField(const FieldData& fdata) {
    _field = fdata;
}

FieldData& Field::getFieldData() {
    return _field;
}
