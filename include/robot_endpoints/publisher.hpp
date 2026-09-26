#pragma once

namespace robot_endpoints
{

template <typename MessageT>
class Publisher
{
public:
  virtual ~Publisher() = default;

  virtual void publish(const MessageT & message) = 0;
};

}  // namespace robot_endpoints
