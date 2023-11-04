#include "../include/Server.h"
#include <ostream>

Server::Server(){
    this->file_logging = true;
    this->console_logging = false;
}

Server::Server(bool consoleLogging, bool fileLogging) {
    this->console_logging = consoleLogging;
    this->file_logging = fileLogging;
}

Server::Server(const Server &other) {
    this->file_logging = other.file_logging;
    this->console_logging = other.console_logging;
}

Server::~Server() = default;

void Server::set_console_log(bool state) {
    this->console_logging = state;
}


void Server::set_file_log(bool state) {
    this->file_logging = state;
}

Server &Server::operator=(const Server &other) = default;
