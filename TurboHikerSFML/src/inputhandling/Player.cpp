#include "Player.h"
#include "CommandQueue.h"
#include "Entity.h"

#include <algorithm>
#include <map>
#include <string>

using namespace turboHiker;
using namespace turboHikerSFML;

struct MovableEntityMover
{
        MovableEntityMover(float vx, float vy) : velocity(vx, vy) {}

        void operator()(turboHiker::Entity& movableEntity, Updatable::seconds) const {
                movableEntity.accelerate(velocity); }

        turboHiker::Vector2d velocity;
};

Player::Player()
{
        // Set initial key bindings
        mKeyBinding[sf::Keyboard::Left] = MoveLeft;
        mKeyBinding[sf::Keyboard::Right] = MoveRight;
        mKeyBinding[sf::Keyboard::Up] = MoveUp;
        mKeyBinding[sf::Keyboard::Down] = MoveDown;

        // Set initial action bindings
        initializeActions();

        for (auto& pair : mActionBinding) {
                // Make sure that all commands (from the action binding) are destined for the player. Other categories
                // should not receive this command.
                pair.second.category = turboHiker::Category::PlayerHiker;
        }
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
        if (event.type == sf::Event::KeyPressed) {
                // Check if pressed key appears in key binding, trigger command if so
                auto found = mKeyBinding.find(event.key.code);
                if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
                        commands.push(mActionBinding[found->second]);
        }
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
        // Traverse all assigned keys and check if they are pressed
        for (auto pair : mKeyBinding) {
                // If key is pressed, lookup action and trigger corresponding command
                if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
                        commands.push(mActionBinding[pair.second]);
        }
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
        // Remove all keys that already map to action
        for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end();) {
                if (itr->second == action)
                        mKeyBinding.erase(itr++);
                else
                        ++itr;
        }

        // Insert new binding
        mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{

        for (auto pair : mKeyBinding) {
                if (pair.second == action)
                        return pair.first;
        }

        return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
        const float playerSpeed = 20.f;

        mActionBinding[MoveLeft].action = derivedAction<Entity>(MovableEntityMover(-playerSpeed, 0.f));
        mActionBinding[MoveRight].action = derivedAction<Entity>(MovableEntityMover(+playerSpeed, 0.f));
        mActionBinding[MoveUp].action = derivedAction<Entity>(MovableEntityMover(0.f, -playerSpeed));
        mActionBinding[MoveDown].action = derivedAction<Entity>(MovableEntityMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Action action)
{
        switch (action) {
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
                return true;

        default:
                return false;
        }
}
