//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Sink.h"

namespace modeling {

Define_Module(Sink);

void Sink::initialize()
{
}

void Sink::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(), "Ready") == 0){
        int r = (rand() %10 +1);
        EV<< "random number is: " << r <<"\n";
        if( r <= 5){
            cMessage *empty = new cMessage("Empty");
            send(empty, "out");
        }
        else{
            cMessage *data = new cMessage("Data");
            send(data, "out");
        }
    }
    EV << "Received " << msg->getName() << "\n";
    delete msg;

}

void Sink::finish()
{

}

}; // namespace
