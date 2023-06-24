#include "./MatchingEngine.h"

#ifndef MESSAGE_H
#define MESSAGE_H

class MessageEncoder {
	public:
		void encode(char *, int, order_t&);
};

class MessageDecoder {
	public:
		void decode(char *, order_t*);
};

#endif // !MESSAGE_H
