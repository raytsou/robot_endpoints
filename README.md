# robot_endpoints

Transport-agnostic C++ interfaces for ROS 2-style robot communication
primitives.

The generally agreed-upon wisdom in ROS is to “write thin nodes.” `robot_endpoints` takes that to its logical conclusion: application logic is entirely abstracted from ROS, while nodes assemble runtime configuration by constructing trivial adapters and passing them in.

The core package is header-only and provides interfaces modeled after ROS 2-style interactions with topics, services, actions, etc., without pulling ROS 2 in its build environment. It is not opinionated about how the lower-level transport is configured.

Implementations live in separate repos.
