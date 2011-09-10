/*
 * Copyright (c) 2011, Peter Thorson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the WebSocket++ Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef ECHO_HANDLER_HPP
#define ECHO_HANDLER_HPP

#include "../../src/websocket_connection_handler.hpp"
#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>

namespace websocketecho {

class echo_handler : public websocketpp::connection_handler {
public:
	echo_handler() {}
	virtual ~echo_handler() {}
	
	// The echo server allows all domains is protocol free.
	void validate(websocketpp::session_ptr client);
	
	// an echo server is stateless. The handler has no need to keep track of connected
	// clients.
	void connect(websocketpp::session_ptr client) {}
	void disconnect(websocketpp::session_ptr client,const std::string &reason) {}
	
	// both text and binary messages are echoed back to the sending client.
	void message(websocketpp::session_ptr client,const std::string &msg);
	void message(websocketpp::session_ptr client,
		const std::vector<unsigned char> &data);
};

typedef boost::shared_ptr<echo_handler> echo_handler_ptr;

}

#endif // ECHO_HANDLER_HPP