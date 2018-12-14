#include "model_client.h"
#include "../include/buttons.h"
#include "drive.h"
#include "door.h"

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//model_client elevator("127.0.0.1",33001);//connect to the simulator


vector <int> fahrplan;
bool upwards = true;

vector<int>& getfahrplan(){
return fahrplan;
}

int main()
{
    
    std::cout << "startup\n";
    model_client elevator("129.217.219.104",33001);  //connect to the real elevator
    
    buttons button1(5);
    door door1;
    drive drive1;
/*
    while (true)
    {

        button1.act();
        sort(fahrplan.begin(), fahrplan.end()); //Vector sortieren
        if (fahrplan.size() > 0)
        {
            drive1.act(fahrplan, upwards);
        }
    }*/
    std::cout << "startdown\n";
    return 0;
}
