#include <iostream>
using namespace std;

class IAttraction
{
public:
    virtual ~IAttraction() {}

    virtual void setName(string nNa) = 0;
    virtual void setTicketPrice(double cm) = 0;
    virtual void setTimeUnits(int nTU) = 0;
    virtual void setForKids(bool nfK) = 0;

    virtual string getName() = 0;
    virtual double getTicketPrice() = 0;
    virtual int getTimeUnits() = 0;
    virtual bool ifForKids() = 0;
};