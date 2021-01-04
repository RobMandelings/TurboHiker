#pragma once

#include "turboHiker/commands/Command.h"

#include <SFML/Window/Event.hpp>

#include <map>

namespace turboHiker {
class CommandQueue;
}

namespace turboHiker {
class Player
{
public:
        enum Action
        {
                MoveLeft,
                MoveRight,
                MoveUp,
                MoveDown,
                YellAtHiker,
                ActionCount
        };

public:
        Player();

        void handleEvent(const sf::Event& event, turboHiker::CommandQueue& commands);
        void handleRealtimeInput(turboHiker::CommandQueue& commands);

        void assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key getAssignedKey(Action action) const;

private:
        void initializeActions();
        static bool isRealtimeAction(Action action);

private:
        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        std::map<Action, turboHiker::Command> mActionBinding;
};
}
