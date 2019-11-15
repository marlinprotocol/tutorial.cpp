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
	) {
		SPDLOG_INFO(
			"Did recv message: {}",
			std::string(message.data(), message.data() + message.size())
		);
	}

	void did_subscribe(
		DefaultMulticastClient<MulticastDelegate> &client,
		std::string &channel
	) {
		client.ps.send_message_on_channel(channel, "Hello!", 6);
	}

	void did_unsubscribe(
		DefaultMulticastClient<MulticastDelegate> &client,
		std::string &channel
	) {}
};

int main() {
	MulticastDelegate del;

	DefaultMulticastClientOptions clop2 {
		{"goldfish"},
		"127.0.0.1:9002",
		"127.0.0.1:7002",
		"127.0.0.1:7000"
	};
	DefaultMulticastClient<MulticastDelegate> cl2(clop2);
	cl2.delegate = &del;

	DefaultMulticastClientOptions clop1 {
		{"goldfish"},
		"127.0.0.1:9002"
	};
	DefaultMulticastClient<MulticastDelegate> cl1(clop1);
	cl1.delegate = &del;

	return DefaultMulticastClient<MulticastDelegate>::run_event_loop();
}
