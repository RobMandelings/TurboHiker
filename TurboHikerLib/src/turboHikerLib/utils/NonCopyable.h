//
// Created by RobMa on 19/12/2020.
//

#ifndef TURBOHIKER_NONCOPYABLE_H
#define TURBOHIKER_NONCOPYABLE_H

namespace turboHiker {
struct NonCopyable
{
        NonCopyable& operator=(const NonCopyable&) = delete;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable() = default;
};
} // namespace turboHiker

#endif // TURBOHIKER_NONCOPYABLE_H
