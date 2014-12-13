#include "JoinRoom.hpp"

namespace Packet {
  uint16_t JoinRoom::headerNumber = 4;

  JoinRoom::JoinRoom()
  : APacket(PacketType::JOINROOM), _idRoom(0)
  {

  }

  JoinRoom::JoinRoom(uint16_t idRoom)
  : APacket(PacketType::JOINROOM), _idRoom(idRoom)
  {

  }

  std::string JoinRoom::to_bytes_body() const
  {
    std::string ret = "";
    fill_bytes(ret, _idRoom);
    return ret;
  }

  void JoinRoom::from_bytes_body(const std::string &bytes)
  {
    std::size_t pos = 1;
    get_bytes(bytes, pos, _idRoom);
  }

  uint16_t JoinRoom::getRoomId() const
  {
    return _idRoom;
  }

};