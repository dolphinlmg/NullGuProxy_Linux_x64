#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Class/n_Pcap/n_pcap_data.h"
#include "Class/Packet/n_tcp.h"
#include "Class/n_Pcap/n_pcap.h"
#include "Class/Packet/n_packet.h"

using namespace std;

namespace MAIN {

    static n_Pcap_Data* file;
    static vector<uint16_t> ports;
    static const char* portFileName = "ports.ng";

    bool readPortsFromFile() {
        try {
            ifstream is(portFileName, ios::in);
            if (!is.is_open())
                return false;
            uint16_t tmp;
            while (!is.eof()){
                is >> tmp;
                if (is.good())
                    ports.push_back(tmp);
            }
            is.close();
        } catch (exception& ex) {
            cerr << ex.what() << endl;
            return false;
        }
        return true;
    }
}

using namespace MAIN;

#endif // MAIN_H
