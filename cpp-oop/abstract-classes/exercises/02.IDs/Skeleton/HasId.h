#ifndef HASID_H
#define HASID_H

class HasId {
public:
    virtual int getId() const {
        return id;
    }
    
    virtual ~HasId() {}
    
protected:
    int id = 0;
};

#endif // !HASID_H
