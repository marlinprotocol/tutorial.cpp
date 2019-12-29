#include <marlin/multicast/DefaultMulticastClient.hpp>


using namespace marlin::multicast;
using namespace marlin::net;

class MulticastDelegate {
public:
	void did_recv_message(
		DefaultMulticastClient<MulticastDelegate> &client,
		Buffer &&message,
		Buffer &&witness,
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
	uint8_t static_sk1[crypto_box_SECRETKEYBYTES];
	uint8_t static_pk1[crypto_box_PUBLICKEYBYTES];
	crypto_box_keypair(static_pk1, static_sk1);

	MulticastDelegate del;

	DefaultMulticastClientOptions clop1 {
		static_sk1,
		{"goldfish"},
		"127.0.0.1:9002"
	};

	DefaultMulticastClient<MulticastDelegate> cl1(clop1);
	cl1.delegate = &del;

	return DefaultMulticastClient<MulticastDelegate>::run_event_loop();
}
