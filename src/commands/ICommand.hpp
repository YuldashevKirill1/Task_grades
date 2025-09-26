#pragma once

namespace Command {

    class ICommand {
    public:
        virtual int exec() = 0;
        virtual ~ICommand() = default;
    };

}