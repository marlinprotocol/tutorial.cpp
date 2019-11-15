#include <marlin/multicast/DefaultMulticastClient.hpp>


using namespace marlin::multicast;
using namespace marlin::net;

class MulticastDelegate {
public:
	void did_recv_message(
		DefaultMulticastClient<MulticastDelegate> &client,
		Buffer &&message,
		std::string &channel,
		uint64_t message_id
	) {}

	void did_subscribe(
		DefaultMulticastClient<MulticastDelegate> &client,
		std::string &channel
	) {}

	void did_unsubscribe(
		DefaultMulticastClient<MulticastDelegate> &client,
		std::string &channel
	) {}
};

int main() {
	MulticastDelegate del;

	DefaultMulticastClientOptions clop1 {
		{"goldfish"},
		"127.0.0.1:9002"
	};

	DefaultMulticastClient<MulticastDelegate> cl1(clop1);
	cl1.delegate = &del;

	return DefaultMulticastClient<MulticastDelegate>::run_event_loop();
}
