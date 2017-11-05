
#ifndef TELLER_H
#define TELLER_H

class Teller {
public:
    Teller(int _desk);
    Teller(const Teller& orig);
    virtual ~Teller();

    int getDesk();
    bool isActive();
    void setActive();
    void setInactive();
    
private:
    int desk; // only a desk id or station id where the teller is working
    bool active;

};

#endif /* TELLER_H */

