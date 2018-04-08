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

package modeling;

//
// Sample network, consisting of a source and a sink.
//
network SourceSink
{
    @display("bgb=700,456");
    submodules:
        source: Source {
            @display("p=170,68");
        }
        sink: Sink {
            @display("p=123,225");
        }
        sink1: Sink {
            @display("p=337,225");
        }
        sink2: Sink {
            @display("p=209,225");
        }
    connections:

        sink.out --> source.in;
        source.out --> sink.in;
        sink2.out --> source.in1;
        source.out1 --> sink2.in;
        source.out2 --> sink1.in;
        sink1.out --> source.in2;
}
