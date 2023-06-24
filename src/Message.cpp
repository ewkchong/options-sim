#include "MatchingEngine.h"
#include <string>

// Currently, these classes just use the in-memory representation of an order struct
// These can be modified to do more sophisticated encoding/decoding methods such as
// JSON, XML, Protocol Buffers, etc.
class MessageEncoder {
	void encode(char* buf, int buf_len, order_t &order) {
		if (buf_len != sizeof(order_t)) return;
		memcpy(buf, &order, buf_len);
	}
};

class MessageDecoder {
	void decode(char *buf, order_t *order) {
		memcpy(order, buf, sizeof(order_t));
	}
};
