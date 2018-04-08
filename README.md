# Star-Network
A simulation network of client nodes and 1 central station.
1. The central station will send a poll message to each node to notify that
it is ready to receive messages from them.
2. Each node will send a message to the center station in reply to the
poll.
3. After the center station receives a message from a station it will send a
poll message again so that the station sends any remaining messages
