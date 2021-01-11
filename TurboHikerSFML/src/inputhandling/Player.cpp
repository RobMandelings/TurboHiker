#include "Player.h"
#include "CommandQueue.h"
#include "World.h"

using namespace turboHiker;

struct HikerSpeed
{
        HikerSpeed(bool fast) : mFast(fast) {}

        void operator()(PlayerHiker& playerHiker, Updatable::seconds dt) const
        {
                if (mFast) {
                        if (!playerHiker.goingFast()) {
                                playerHiker.goFast();
                        }
                } else {
                        if (playerHiker.goingFast()) {
                                playerHiker.goSlow();
                        }
                }
        }

        bool mFast;
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

class StartHikeCommand
{

public:
        StartHikeCommand() = default;

        void operator()(turboHiker::World& world, Updatable::seconds dt) const { world.startHiking(); }
};

class ResetHikeCommand
{
public:
        ResetHikeCommand() = default;

        void operator()(turboHiker::World& world, Updatable::seconds dt) const { world.resetHike(); }
};

Player::Player()
{
        // Set initial key bindings
        mKeyBinding[sf::Keyboard::Left] = MoveLeft;
        mKeyBinding[sf::Keyboard::Right] = MoveRight;
        mKeyBinding[sf::Keyboard::Up] = MoveUp;
        mKeyBinding[sf::Keyboard::Down] = MoveDown;
        mKeyBinding[sf::Keyboard::Space] = YellAtHiker;
        mKeyBinding[sf::Keyboard::R] = ResetHike;
        mKeyBinding[sf::Keyboard::S] = StartHike;

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

        mActionBinding[MoveLeft].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[MoveRight].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[YellAtHiker].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[MoveUp].category = turboHiker::GameCategory::GamePlayerHiker;
        mActionBinding[MoveDown].category = turboHiker::GameCategory::GamePlayerHiker;
        mActionBinding[MoveLeft].whenToExecute = HikeStatus::WhilstHiking;
        mActionBinding[MoveRight].whenToExecute = HikeStatus::WhilstHiking;
        mActionBinding[YellAtHiker].whenToExecute = HikeStatus::WhilstHiking;
        mActionBinding[MoveUp].whenToExecute = HikeStatus::WhilstHiking;
        mActionBinding[MoveDown].whenToExecute = HikeStatus::WhilstHiking;

        mActionBinding[ResetHike].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[StartHike].category = turboHiker::GameCategory::GameWorld;
        mActionBinding[ResetHike].whenToExecute = HikeStatus::AfterHiking;
        mActionBinding[StartHike].whenToExecute = HikeStatus::BeforeHiking;

        mActionBinding[MoveLeft].action = derivedSceneNodeCommand<World>(LaneMover(false));
        mActionBinding[MoveRight].action = derivedSceneNodeCommand<World>(LaneMover(true));
        mActionBinding[MoveUp].action = derivedSceneNodeCommand<PlayerHiker>(HikerSpeed(true));
        mActionBinding[MoveDown].action = derivedSceneNodeCommand<PlayerHiker>(HikerSpeed(false));
        mActionBinding[YellAtHiker].action = derivedSceneNodeCommand<World>(YellAtHikerCommand(100));
        mActionBinding[ResetHike].action = derivedSceneNodeCommand<World>(ResetHikeCommand());
        mActionBinding[StartHike].action = derivedSceneNodeCommand<World>(StartHikeCommand());
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
