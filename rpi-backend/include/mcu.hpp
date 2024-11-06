#pragma once

#include <cstdint>
#include <mutex>

namespace mcu {
    enum class song_status_e {
        UNKNOWN,
        LOADING,
        STOPPED,
        PLAYING,
    };

    using song_id_t = std::uint8_t;

    auto update_loaded_song_id() -> bool;

    auto get_current_song_id() -> song_id_t;

    extern std::mutex song_mut;
    extern song_id_t current_song_id;
    extern song_status_e current_song_status;
} // namespace mcu
