#include "model_client/model_client.h"
#include "drive.h"
#include "door.h"
#include "buttons.h"
#include <iostream>
#include <windows.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <chrono>


using namespace std;

void whereami();
int lastfloor = 1;
int zwischenstop;
model_client elevator1("127.0.0.1",33001);

door door1;

drive::drive(){
}

drive::act(vector<int>&x, bool& upwards)
{
    //cout << "test";
    int i=0;
    int j=0;
    int target;
    boolean direction = false;
    whereami();

    if(upwards==true)
    {
        target=5;
            for(i : x) //For every element in vector x do the following:
            {
                if(i > lastfloor && i < target) //Element bigger than actual floor and smaller than target
                {
                    target = i; //then the element is the next target
                    j = i;
                    direction = true;
                }
            }
            if(direction == false) //Decision "change direction?"
            {
                upwards = false; //if yes, change bool upwards
                return 0;
            }

            elevator1.write("MKE",1);
            elevator1.write("MKB",1);

            if(lastfloor < target && upwards == true) //until the target floor is not reached, carry on driving
            {
                whereami();
                usleep(70000);
                buttons();
            }
            elevator1.write("MKE",0);
            elevator1.write("MKB",0);
                whereami();
    }
    if(upwards==false)
    {
        target=0;
            for(i : x)
            {
                if(i < lastfloor && i > target)
                {
                    target = i;
                    j = i;
                    direction = true;
                }
            }
            if(direction == false)
            {
                upwards = true;
                return 0;
            }

            elevator1.write("MKE",1);
            elevator1.write("MKA",1);

            if(lastfloor > target && upwards == false)
            {
                whereami();
                usleep(70000);
                buttons();
            }
            elevator1.write("MKE",0);
            elevator1.write("MKA",0);
            whereami();
        }
        if (lastfloor == target)
        {
            x.erase(remove(x.begin(), x.end(), j), x.end());
            cout << "I am at floor: " << j << endl;
            door1.act(lastfloor);
            elevator1.write("LP"+to_string(j),0);
        }
}

void whereami()
{usleep(5000000);
    if (elevator1.read("TPM1") == 1)
    {
        lastfloor = 1;
    }
    if (elevator1.read("TPM2") == 1)
    {
        lastfloor = 2;
    }
    if (elevator1.read("TPM3") == 1)
    {
        lastfloor = 3;
    }
    if (elevator1.read("TPM4") == 1)
    {
        lastfloor = 4;
    }
}



