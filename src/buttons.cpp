#include "buttons.h"
#include "drive.h"
#include "model_client/model_client.h"
#include <vector>
#include <algorithm>

using namespace std;

model_client elevator2("127.0.0.1",33001);

vector<int>&getfahrplan();

buttons::buttons()
{

}

buttons::act()
{
    if (elevator2.read("TRA1")==1){getfahrplan().push_back(1); elevator2.write("LP1",1);} //Speichern in Vector
    if (elevator2.read("TRA2")==1){getfahrplan().push_back(2); elevator2.write("LP2",1);}
    if (elevator2.read("TRA3")==1){getfahrplan().push_back(3); elevator2.write("LP3",1);}
    if (elevator2.read("TRA4")==1){getfahrplan().push_back(4); elevator2.write("LP4",1);}
    sort(getfahrplan().begin(), getfahrplan().end());
}

