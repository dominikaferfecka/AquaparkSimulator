#include <iostream>
using namespace std;

class IEmployee
{
    public:
        virtual ~IEmployee() {}

        virtual string get_name() = 0;
        virtual int get_id() = 0;

        virtual void set_name(string new_name) = 0;
        virtual void set_id(int new_id) = 0;
};