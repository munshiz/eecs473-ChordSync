#include "playerMode.hpp"
#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <iostream>

namespace py = pybind11;


auto midiParse(uint8_t song_id, uint8_t mode, uint8_t duration,
               uint8_t bpm) -> std::vector<std::vector<int>>{
    py::scoped_interpreter guard{};

    py::module sys = py::module::import("sys");
    sys.attr("path").attr("insert")(0, PY_VENV_PATH);
    sys.attr("path").attr("insert")(0, PY_MODULE_PATH);

    try {
        py::module pybind_module = py::module::import("basic_pitch");
        std::cout << "Module imported successfully!" << std::endl;
    } catch (py::error_already_set const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    auto get_record_convert_module = py::module_::import("record_convert");
    py::object get_record_convert = get_record_convert_module.attr("record_convert");



    std::string rec_mode = "-r";

    //mode 1 and 2 are record song and single 
    if(mode == 3){
        rec_mode = "-c";
    }

    auto numbers = get_record_convert(rec_mode, song_id, duration, bpm).cast<std::vector<std::vector<int>>>();

    return numbers;
               }
    
//add in cleanout function
playerMode::playerMode(uint8_t song_id, uint8_t mode, std::string const& note, std::string const& title, std::string const artist, uint8_t duration,
                       uint8_t bpm)
    : song{song_id, title, artist, std::chrono::seconds(duration), bpm}, mode(mode), note(note) {


    /*py::scoped_interpreter guard{};

    py::module sys = py::module::import("sys");
    sys.attr("path").attr("insert")(0, PY_VENV_PATH);
    sys.attr("path").attr("insert")(0, PY_MODULE_PATH);

    try {
        py::module pybind_module = py::module::import("basic_pitch");
        std::cout << "Module imported successfully!" << std::endl;
    } catch (py::error_already_set const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    auto get_record_convert_module = py::module_::import("record_convert");
    py::object get_record_convert = get_record_convert_module.attr("record_convert");*/

    //auto numbers = get_record_convert("-r", song_id, duration, bpm).cast<std::vector<std::vector<int>>>();

    auto numbers = midiParse(song_id, 1, duration, bpm);

    for (auto& number: numbers) {
        auto entry = new data::songs::Note;
        entry->midi_note = static_cast<uint8_t>(number[0]);
        entry->start_timestamp_ms = static_cast<uint8_t>(number[1]);
        entry->length_ms = static_cast<uint8_t>(number[2] - entry->start_timestamp_ms);
        (this->song.notes).push_back(*entry);
        delete entry;
    }
}

auto playerMode::dataParseRef(uint8_t song_id, uint8_t bpm) -> std::vector<std::vector<int>>{
    return midiParse(song_id, 3, 0, bpm);
}


auto playerMode::get_mode() const -> std::string {
    if (this->mode == 1) return "single note";
    return "pls wait";
}
auto playerMode::get_bpm() const -> uint8_t { return this->song.bpm; }

auto playerMode::get_resolution() const -> uint8_t { return 0; }


auto playerMode::analysis(std::vector<data::songs::Note>& ref) -> std::vector<bool> {
    std::vector<bool> s;
    s.push_back(false);
    return s;
}

auto playerMode::analysis(std::string const& note) -> bool {
    uint8_t refNote = this->noteToInt(note);
    std::unordered_map<uint8_t, uint8_t> freq;

    uint8_t maxNote = 0;

    uint8_t maxCount = 0;

    for (auto& note: this->song.notes) {
        freq[note.midi_note]++;
    }
    //iterate through and check max freqeucy, then output if it is correct or note.
    for (auto& it: freq) {
        if (it.second > maxCount) {
            maxCount = it.second;
            maxNote = it.first;
        }
    }
    return maxNote == refNote ? true : false;
}

playerMode::~playerMode() = default;


auto playerMode::noteToInt(std::string const& note) -> uint8_t {
    // Map of note names to semitone offsets
    // Extract the note name and octave from the input string
    std::string name = note.substr(0, note.size() - 1); // Extract the note name
    uint8_t octave = note.back() - '0';                 // Convert the last character to an integer

    // Calculate the MIDI note number
    return 12 + (12 * octave) + semitoneOffsets[name];
}

/*auto playerMode::analysis() -> void{
    py::scoped_interpreter guard{};

    py::module sys = py::module::import("sys");
    sys.attr("path").attr("insert")(0, PY_VENV_PATH);
    sys.attr("path").attr("insert")(0, PY_MODULE_PATH);

    try {
        py::module pybind_module = py::module::import("basic_pitch");
        std::cout << "Module imported successfully!" << std::endl;
    } catch (py::error_already_set const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    auto get_record_convert_module = py::module_::import("record_convert");
    py::object get_record_convert = get_record_convert_module.attr("record_convert");

    auto numbers = get_record_convert("c", this->song.id, this->song.length, this->song.bpm).cast<std::vector<std::vector<int>>>();

    
}*/