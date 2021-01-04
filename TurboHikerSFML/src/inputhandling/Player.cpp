#include "Player.h"
#include "Entity.h"
#include "turboHiker/commands/CommandQueue.h"
#include "turboHiker/world/World.h"
#include "Hiker.h"

#include <algorithm>
#include <map>
#include <string>

using namespace turboHiker;
using namespace turboHiker;

struct HikerSpeed
{
        HikerSpeed(double velocity) : mVelocity(velocity) {}

        void operator()(turboHiker::Entity& movableEntity, Updatable::seconds dt) const
        {
                movableEntity.setVelocity(Vector2d(movableEntity.getVelocity().x, mVelocity));
        }

        double mVelocity;
};

class LaneMover
{

public:
        explicit LaneMover(bool moveRight) : mMoveRight(moveRight) {}

        void operator()(turboHiker::World& world, Updatable::seconds dt) const
        {
                int newLane = world.getPlayerHiker().getCurrentLane() + (mMoveRight ? 1 : -1);
                if (newLane >= 0 && newLane < world.getAmountOfLanes()) {
                        world.putHikerOnLane(world.getPlayerHiker(), newLane);
                }
        }

private:
        bool mMoveRight;
};

class YellAtHikerCommand
{

public:
        explicit YellAtHikerCommand(double distance) : mDistance(distance) {}

        void operator()(turboHiker::World& world, Updatable::seconds dt) const
        {
                world.hikerYelled(world.getPlayerHiker(), mDistance);
        }

private:

        double mDistance;

};

Player::Player()
{
        // Set initial key bindings
        mKeyBinding[sf::Keyboard::Left] = MoveLeft;
        mKeyBinding[sf::Keyboard::Right] = MoveRight;
        mKeyBinding[sf::Keyboard::Up] = MoveUp;
        mKeyBinding[sf::Keyboard::Down] = MoveDown;
        mKeyBinding[sf::Keyboard::Space] = YellAtHiker;

        // Set initial action bindings
        initializeActions();
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
        const float playerSpeed = 100.f;

        mActionBinding[MoveLeft].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[MoveRight].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[MoveUp].category = turboHiker::GameCategory::PlayerHiker;
        mActionBinding[MoveDown].category = turboHiker::GameCategory::PlayerHiker;
        mActionBinding[YellAtHiker].category = turboHiker::GameCategory::GameWorld;

        mActionBinding[MoveLeft].action = derivedSceneNodeCommand<World>(LaneMover(false));
        mActionBinding[MoveRight].action = derivedSceneNodeCommand<World>(LaneMover(true));
        mActionBinding[MoveUp].action = derivedSceneNodeCommand<Entity>(HikerSpeed(playerSpeed));
        mActionBinding[MoveDown].action = derivedSceneNodeCommand<Entity>(HikerSpeed(playerSpeed / 3));
        mActionBinding[YellAtHiker].action = derivedSceneNodeCommand<World>(YellAtHikerCommand(10));
}

bool Player::isRealtimeAction(Action action)
{
        switch (action) {
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
                return false;

        default:
                return false;
        }
}
