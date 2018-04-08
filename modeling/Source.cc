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

#include "Source.h"

namespace modeling {

Define_Module(Source);

Source::Source()
{
  //  int i = 0;
    //  while(i < par("GatesNumber")){
    //  String GateName = "out" + i;
    //  this->addGate(GateName, output, true);
    //  GateName ="in" + i;
    //  this->addGate(GateName, input, true);
    //  i = i + 1;
    //}
}

Source::~Source()
{
}
cMessage *Source::createReady(){
    cMessage *ready = new cMessage("Ready");
    return ready;
}
void Source::initialize()
{
    send(createReady(), "out");

    EV<<"Ready"<<"\n";
}

void Source::handleMessage(cMessage *msg){

    if((strcmp(msg->getName(), "Empty")) == 0){
            if((strcmp(msg->getArrivalGate()->getName(), "in")) == 0){
                send(createReady(), "out1");
            }
            else if((strcmp(msg->getArrivalGate()->getName(), "in1")) == 0){
                            send(createReady(), "out2");
                        }
            else if((strcmp(msg->getArrivalGate()->getName(), "in2")) == 0){
                                        send(createReady(), "out");
                                    }
            else
                send(createReady(),"out");

    }

    else{
        if((strcmp(msg->getArrivalGate()->getName(), "in")) == 0){
                        send(createReady(), "out");
                    }
        else if((strcmp(msg->getArrivalGate()->getName(), "in1")) == 0){
                        send(createReady(), "out1");
        }

        else if((strcmp(msg->getArrivalGate()->getName(), "in2")) == 0){
                                        send(createReady(), "out2");
    }
        else
            send(createReady(),"out");

    }
}
} // namespace
