#ifndef HASID_H
#define HASID_H

class HasId {
public:
    virtual int getId() const = 0;

    virtual ~HasId() {}
};

#endif // !HASID_H
