#include "door.h"
#include "drive.h"
#include "model_client/model_client.h"
#include <unistd.h>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

buttons button1;

model_client elevator3("127.0.0.1",33001);

door::door(){
}

door::act(int z)
{
string MTE = "MTE"+to_string(z); //assign the stings to the floors with a variable for the floor in order to keep the code flexible
string MTA = "MTA"+to_string(z);
string MTB = "MTB"+to_string(z);
string TTA = "TTA"+to_string(z);
string TTZ = "TTZ"+to_string(z);
string PS = "PS"+to_string(z);
string PA = "PA"+to_string(z);

    while (elevator3.read(TTA)==0) //as long as door isnt fully open
    {
        button1.act();
        elevator3.write(MTE,1); //activate door motors
        elevator3.write(MTA,1); //open door
    }
    elevator3.write(MTE,0); //deactivate door motors
    elevator3.write(MTA,0);
    std::this_thread::sleep_for(std::chrono::nanoseconds(2000000000));
    elevator3.write(PA,1);

    while (elevator3.read(TTZ)==0 )//&& elevator3.read(PS)==1) //as long as door not closed and nothing blocks the light barrier
    {
       //if(elevator3.read(PS)==0){
           //std::cout << "ahhhhh";
       //}
        button1.act();
        elevator3.write(MTE,1);
        elevator3.write(MTB,1); //close the door
    }

    if(elevator3.read(TTZ)==1)
    {
        elevator3.write(PA,0);
    }

    elevator3.write(MTE,0);
    elevator3.write(MTB,0);

    if(elevator3.read(TTZ)==0)
    {
        act(z);
    }
}

