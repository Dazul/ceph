#pragma once

#include "common/admin_socket_client.h"
#include <string>
#include <map>
#include <vector>

#include <string>
#include <map>
#include <vector>
#include <boost/asio.hpp>

class DaemonMetricCollector {
 public:
  int i;
  void main();
  std::string get_metrics();

private:
  // TODO: add clients
  //       check removed sockets
  //       list dir of sockets
  std::map<std::string, AdminSocketClient> clients;
  std::string metrics;
  int stats_period; // time to wait before sending requests again
  void update_sockets();
  void request_loop(boost::asio::deadline_timer &timer);
  void send_requests();
  void start_mgr_connection();
};

DaemonMetricCollector& collector_instance();