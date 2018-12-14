#ifndef INCLUDE_MODEL_CLIENT_H
#define INCLUDE_MODEL_CLIENT_H

#include <string>
#include <map>
#include <cstdint>
namespace tacopie{
 class tcp_client;
}
class model_client
{
    public:
        model_client(std::string ip_adress,std::uint32_t port){};
    //    ~model_client();
        /**
        *\brief read from model
        *\param name of pin to read
        *\returns value of pin
        **/
        bool read(std::string pin_name);
        /**
        *\brief write to model
        *\param name of pin to write to
        *\param value value to write
        **/
        void write(std::string pin_name,bool value);
    private:
        long long message_counter = 1;
        tacopie::tcp_client* client_;
        std::map<std::string,bool> pin_data_valid;
        std::map<std::string,bool> pin_data_value;

};

#endif
