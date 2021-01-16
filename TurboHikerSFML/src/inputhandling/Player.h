#pragma once

#include "turboHiker/commands/Command.h"

#include <SFML/Window/Event.hpp>

#include <map>

namespace turboHiker {
class CommandQueue;
}

namespace turboHiker {

/**
 * The Player handles all input and creates command on the fly when a certain input is detected
 */
class Player
{
public:
        /**
         * Actions are linked to specific commands so they can be easily created. Keys are also dynamically binded to
         * actions, although this is done in the specific implementation of the Player class.
         */
        enum Action
        {
                MoveLeft,
                MoveRight,
                MoveUp,
                MoveDown,
                YellAtHiker,
                ResetHike,
                StartHike,
                ActionCount
        };

public:
        /**
         * Simple constructor
         */
        Player();

        /**
         * Handles a specific event and adds commands accordingly
         * @param event: the event that took place
         * @param commands: the current commandQueue of the world
         */
        void handleEvent(const sf::Event& event, CommandQueue& commands);

        /**
         * Handles realtime input (querying if specific keys are pressed for example) and adds commands accordingly
         * @param commands: the current commandQueue of the world
         */
        void handleRealtimeInput(CommandQueue& commands);

        /**
         * Assign a key to a specific action so the new key now executes the action instead of the previous key
         * @param action: the action to bind with the key
         * @param key: the new key
         */
        void assignKey(Action action, sf::Keyboard::Key key);

        /**
         * @param action
         * @return the specific key binded to an action
         */
        sf::Keyboard::Key getAssignedKey(Action action) const;

private:
        /**
         * Initialize actions with their corresponding commands
         */
        void initializeActions();

        /**
         * Checks whether or not an action is realtime or is executed whenever an event occurs
         * @param action: the action to check for
         * @return true if this is the case, false if not
         */
        static bool isRealtimeAction(Action action);

private:
        /**
         * The key binded to the action
         */
        std::map<sf::Keyboard::Key, Action> mKeyBinding;

        /**
         * The action binded to the command
         */
        std::map<Action, turboHiker::Command> mActionBinding;
};
} // namespace turboHiker
