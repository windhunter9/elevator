#ifndef DRIVE_H
#define DRIVE_H
#include "model_client/model_client.h"
#include "door.h"
#include "buttons.h"
#include <vector>


using namespace std;


class drive
{
    public:

        drive();
        act(vector<int> &x, bool& drive);

        //virtual ~drive();

    protected:

    private:
};

#endif // DRIVE_H
