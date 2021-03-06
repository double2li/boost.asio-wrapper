/* boost.asio-wrapper, A C++ library, wrapping boost.asio, to be used for client or server applications
   Copyright (C) 2014 firecoders

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
   OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef EXECUTION_NODE_H_
#define EXECUTION_NODE_H_

#include <memory>

#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

#include "wrapper/commands/interfaces/Command.h"

namespace wrapper
{
    namespace commands
    {
        enum class EXECUTION_TYPE
        {
                ASYNCHRONOUS,
                SYNCHRONOUS,
                UNIQUE
        };

        class Execution_node : public Command
        {
            public:

                Execution_node(std::shared_ptr<Command> command, EXECUTION_TYPE type);
                ~Execution_node() noexcept {};

                void execute(Command_params& params);
                bool match(Command_params& params);

                void set_command(std::shared_ptr<Command> command);
                void set_execution_type(EXECUTION_TYPE type);

            private:

                void start_execute(Command_params& params);

                boost::shared_mutex unique_mutex;

                std::shared_ptr<Command> command;
                EXECUTION_TYPE type;
        };
    }
}



#endif /* EXECUTION_NODE_H_ */
