
#ifndef TELLER_H
#define TELLER_H

#include "Transaction.h"

class Teller {
public:
    Teller(int _desk);
    Teller(const Teller& orig);
    virtual ~Teller();

    int getDesk();
    bool isBusy();
    void startService(Transaction* t);
    void endService();
    
private:
    int desk; // only a desk id or station id where the teller is working
    bool busy;
    Transaction* transaction;
    
};

#endif /* TELLER_H */

