#pragma once

#include <cstdint>
#include <vector>

#include "hardware.hpp"

static const unsigned char font1[] = {
    	0x00, 0x00, 0x00, 0x00, 0x00,
    	0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
    	0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
    	0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
    	0x18, 0x3C, 0x7E, 0x3C, 0x18,
    	0x1C, 0x57, 0x7D, 0x57, 0x1C,
    	0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
    	0x00, 0x18, 0x3C, 0x18, 0x00,
    	0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
    	0x00, 0x18, 0x24, 0x18, 0x00,
    	0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
    	0x30, 0x48, 0x3A, 0x06, 0x0E,
    	0x26, 0x29, 0x79, 0x29, 0x26,
    	0x40, 0x7F, 0x05, 0x05, 0x07,
    	0x40, 0x7F, 0x05, 0x25, 0x3F,
    	0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
    	0x7F, 0x3E, 0x1C, 0x1C, 0x08,
    	0x08, 0x1C, 0x1C, 0x3E, 0x7F,
    	0x14, 0x22, 0x7F, 0x22, 0x14,
    	0x5F, 0x5F, 0x00, 0x5F, 0x5F,
    	0x06, 0x09, 0x7F, 0x01, 0x7F,
    	0x00, 0x66, 0x89, 0x95, 0x6A,
    	0x60, 0x60, 0x60, 0x60, 0x60,
    	0x94, 0xA2, 0xFF, 0xA2, 0x94,
    	0x08, 0x04, 0x7E, 0x04, 0x08,
    	0x10, 0x20, 0x7E, 0x20, 0x10,
    	0x08, 0x08, 0x2A, 0x1C, 0x08,
    	0x08, 0x1C, 0x2A, 0x08, 0x08,
    	0x1E, 0x10, 0x10, 0x10, 0x10,
    	0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
    	0x30, 0x38, 0x3E, 0x38, 0x30,
    	0x06, 0x0E, 0x3E, 0x0E, 0x06,
    	0x00, 0x00, 0x00, 0x00, 0x00,
    	0x00, 0x00, 0x5F, 0x00, 0x00,
    	0x00, 0x07, 0x00, 0x07, 0x00,
    	0x14, 0x7F, 0x14, 0x7F, 0x14,
    	0x24, 0x2A, 0x7F, 0x2A, 0x12,
    	0x23, 0x13, 0x08, 0x64, 0x62,
    	0x36, 0x49, 0x56, 0x20, 0x50,
    	0x00, 0x08, 0x07, 0x03, 0x00,
    	0x00, 0x1C, 0x22, 0x41, 0x00,
    	0x00, 0x41, 0x22, 0x1C, 0x00,
    	0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
    	0x08, 0x08, 0x3E, 0x08, 0x08,
    	0x00, 0x80, 0x70, 0x30, 0x00,
    	0x08, 0x08, 0x08, 0x08, 0x08,
    	0x00, 0x00, 0x60, 0x60, 0x00,
    	0x20, 0x10, 0x08, 0x04, 0x02,
    	0x3E, 0x51, 0x49, 0x45, 0x3E,
    	0x00, 0x42, 0x7F, 0x40, 0x00,
    	0x72, 0x49, 0x49, 0x49, 0x46,
    	0x21, 0x41, 0x49, 0x4D, 0x33,
    	0x18, 0x14, 0x12, 0x7F, 0x10,
    	0x27, 0x45, 0x45, 0x45, 0x39,
    	0x3C, 0x4A, 0x49, 0x49, 0x31,
    	0x41, 0x21, 0x11, 0x09, 0x07,
    	0x36, 0x49, 0x49, 0x49, 0x36,
    	0x46, 0x49, 0x49, 0x29, 0x1E,
    	0x00, 0x00, 0x14, 0x00, 0x00,
    	0x00, 0x40, 0x34, 0x00, 0x00,
    	0x00, 0x08, 0x14, 0x22, 0x41,
    	0x14, 0x14, 0x14, 0x14, 0x14,
    	0x00, 0x41, 0x22, 0x14, 0x08,
    	0x02, 0x01, 0x59, 0x09, 0x06,
    	0x3E, 0x41, 0x5D, 0x59, 0x4E,
    	0x7C, 0x12, 0x11, 0x12, 0x7C,
    	0x7F, 0x49, 0x49, 0x49, 0x36,
    	0x3E, 0x41, 0x41, 0x41, 0x22,
    	0x7F, 0x41, 0x41, 0x41, 0x3E,
    	0x7F, 0x49, 0x49, 0x49, 0x41,
    	0x7F, 0x09, 0x09, 0x09, 0x01,
    	0x3E, 0x41, 0x41, 0x51, 0x73,
    	0x7F, 0x08, 0x08, 0x08, 0x7F,
    	0x00, 0x41, 0x7F, 0x41, 0x00,
    	0x20, 0x40, 0x41, 0x3F, 0x01,
    	0x7F, 0x08, 0x14, 0x22, 0x41,
    	0x7F, 0x40, 0x40, 0x40, 0x40,
    	0x7F, 0x02, 0x1C, 0x02, 0x7F,
    	0x7F, 0x04, 0x08, 0x10, 0x7F,
    	0x3E, 0x41, 0x41, 0x41, 0x3E,
    	0x7F, 0x09, 0x09, 0x09, 0x06,
    	0x3E, 0x41, 0x51, 0x21, 0x5E,
    	0x7F, 0x09, 0x19, 0x29, 0x46,
    	0x26, 0x49, 0x49, 0x49, 0x32,
    	0x03, 0x01, 0x7F, 0x01, 0x03,
    	0x3F, 0x40, 0x40, 0x40, 0x3F,
    	0x1F, 0x20, 0x40, 0x20, 0x1F,
    	0x3F, 0x40, 0x38, 0x40, 0x3F,
    	0x63, 0x14, 0x08, 0x14, 0x63,
    	0x03, 0x04, 0x78, 0x04, 0x03,
    	0x61, 0x59, 0x49, 0x4D, 0x43,
    	0x00, 0x7F, 0x41, 0x41, 0x41,
    	0x02, 0x04, 0x08, 0x10, 0x20,
    	0x00, 0x41, 0x41, 0x41, 0x7F,
    	0x04, 0x02, 0x01, 0x02, 0x04,
    	0x40, 0x40, 0x40, 0x40, 0x40,
    	0x00, 0x03, 0x07, 0x08, 0x00,
    	0x20, 0x54, 0x54, 0x78, 0x40,
    	0x7F, 0x28, 0x44, 0x44, 0x38,
    	0x38, 0x44, 0x44, 0x44, 0x28,
    	0x38, 0x44, 0x44, 0x28, 0x7F,
    	0x38, 0x54, 0x54, 0x54, 0x18,
    	0x00, 0x08, 0x7E, 0x09, 0x02,
    	0x18, 0xA4, 0xA4, 0x9C, 0x78,
    	0x7F, 0x08, 0x04, 0x04, 0x78,
    	0x00, 0x44, 0x7D, 0x40, 0x00,
    	0x20, 0x40, 0x40, 0x3D, 0x00,
    	0x7F, 0x10, 0x28, 0x44, 0x00,
    	0x00, 0x41, 0x7F, 0x40, 0x00,
    	0x7C, 0x04, 0x78, 0x04, 0x78,
    	0x7C, 0x08, 0x04, 0x04, 0x78,
    	0x38, 0x44, 0x44, 0x44, 0x38,
    	0xFC, 0x18, 0x24, 0x24, 0x18,
    	0x18, 0x24, 0x24, 0x18, 0xFC,
    	0x7C, 0x08, 0x04, 0x04, 0x08,
    	0x48, 0x54, 0x54, 0x54, 0x24,
    	0x04, 0x04, 0x3F, 0x44, 0x24,
    	0x3C, 0x40, 0x40, 0x20, 0x7C,
    	0x1C, 0x20, 0x40, 0x20, 0x1C,
    	0x3C, 0x40, 0x30, 0x40, 0x3C,
    	0x44, 0x28, 0x10, 0x28, 0x44,
    	0x4C, 0x90, 0x90, 0x90, 0x7C,
    	0x44, 0x64, 0x54, 0x4C, 0x44,
    	0x00, 0x08, 0x36, 0x41, 0x00,
    	0x00, 0x00, 0x77, 0x00, 0x00,
    	0x00, 0x41, 0x36, 0x08, 0x00,
    	0x02, 0x01, 0x02, 0x04, 0x02,
    	0x3C, 0x26, 0x23, 0x26, 0x3C,
    	0x1E, 0xA1, 0xA1, 0x61, 0x12,
    	0x3A, 0x40, 0x40, 0x20, 0x7A,
    	0x38, 0x54, 0x54, 0x55, 0x59,
    	0x21, 0x55, 0x55, 0x79, 0x41,
    	0x22, 0x54, 0x54, 0x78, 0x42,
    	0x21, 0x55, 0x54, 0x78, 0x40,
    	0x20, 0x54, 0x55, 0x79, 0x40,
    	0x0C, 0x1E, 0x52, 0x72, 0x12,
    	0x39, 0x55, 0x55, 0x55, 0x59,
    	0x39, 0x54, 0x54, 0x54, 0x59,
    	0x39, 0x55, 0x54, 0x54, 0x58,
    	0x00, 0x00, 0x45, 0x7C, 0x41,
    	0x00, 0x02, 0x45, 0x7D, 0x42,
    	0x00, 0x01, 0x45, 0x7C, 0x40,
    	0x7D, 0x12, 0x11, 0x12, 0x7D,
    	0xF0, 0x28, 0x25, 0x28, 0xF0,
    	0x7C, 0x54, 0x55, 0x45, 0x00,
    	0x20, 0x54, 0x54, 0x7C, 0x54,
    	0x7C, 0x0A, 0x09, 0x7F, 0x49,
    	0x32, 0x49, 0x49, 0x49, 0x32,
    	0x3A, 0x44, 0x44, 0x44, 0x3A,
    	0x32, 0x4A, 0x48, 0x48, 0x30,
    	0x3A, 0x41, 0x41, 0x21, 0x7A,
    	0x3A, 0x42, 0x40, 0x20, 0x78,
    	0x00, 0x9D, 0xA0, 0xA0, 0x7D,
    	0x3D, 0x42, 0x42, 0x42, 0x3D,
    	0x3D, 0x40, 0x40, 0x40, 0x3D,
    	0x3C, 0x24, 0xFF, 0x24, 0x24,
    	0x48, 0x7E, 0x49, 0x43, 0x66,
    	0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
    	0xFF, 0x09, 0x29, 0xF6, 0x20,
    	0xC0, 0x88, 0x7E, 0x09, 0x03,
    	0x20, 0x54, 0x54, 0x79, 0x41,
    	0x00, 0x00, 0x44, 0x7D, 0x41,
    	0x30, 0x48, 0x48, 0x4A, 0x32,
    	0x38, 0x40, 0x40, 0x22, 0x7A,
    	0x00, 0x7A, 0x0A, 0x0A, 0x72,
    	0x7D, 0x0D, 0x19, 0x31, 0x7D,
    	0x26, 0x29, 0x29, 0x2F, 0x28,
    	0x26, 0x29, 0x29, 0x29, 0x26,
    	0x30, 0x48, 0x4D, 0x40, 0x20,
    	0x38, 0x08, 0x08, 0x08, 0x08,
    	0x08, 0x08, 0x08, 0x08, 0x38,
    	0x2F, 0x10, 0xC8, 0xAC, 0xBA,
    	0x2F, 0x10, 0x28, 0x34, 0xFA,
    	0x00, 0x00, 0x7B, 0x00, 0x00,
    	0x08, 0x14, 0x2A, 0x14, 0x22,
    	0x22, 0x14, 0x2A, 0x14, 0x08,
    	0x55, 0x00, 0x55, 0x00, 0x55,
    	0xAA, 0x55, 0xAA, 0x55, 0xAA,
    	0xFF, 0x55, 0xFF, 0x55, 0xFF,
    	0x00, 0x00, 0x00, 0xFF, 0x00,
    	0x10, 0x10, 0x10, 0xFF, 0x00,
    	0x14, 0x14, 0x14, 0xFF, 0x00,
    	0x10, 0x10, 0xFF, 0x00, 0xFF,
    	0x10, 0x10, 0xF0, 0x10, 0xF0,
    	0x14, 0x14, 0x14, 0xFC, 0x00,
    	0x14, 0x14, 0xF7, 0x00, 0xFF,
    	0x00, 0x00, 0xFF, 0x00, 0xFF,
    	0x14, 0x14, 0xF4, 0x04, 0xFC,
    	0x14, 0x14, 0x17, 0x10, 0x1F,
    	0x10, 0x10, 0x1F, 0x10, 0x1F,
    	0x14, 0x14, 0x14, 0x1F, 0x00,
    	0x10, 0x10, 0x10, 0xF0, 0x00,
    	0x00, 0x00, 0x00, 0x1F, 0x10,
    	0x10, 0x10, 0x10, 0x1F, 0x10,
    	0x10, 0x10, 0x10, 0xF0, 0x10,
    	0x00, 0x00, 0x00, 0xFF, 0x10,
    	0x10, 0x10, 0x10, 0x10, 0x10,
    	0x10, 0x10, 0x10, 0xFF, 0x10,
    	0x00, 0x00, 0x00, 0xFF, 0x14,
    	0x00, 0x00, 0xFF, 0x00, 0xFF,
    	0x00, 0x00, 0x1F, 0x10, 0x17,
    	0x00, 0x00, 0xFC, 0x04, 0xF4,
    	0x14, 0x14, 0x17, 0x10, 0x17,
    	0x14, 0x14, 0xF4, 0x04, 0xF4,
    	0x00, 0x00, 0xFF, 0x00, 0xF7,
    	0x14, 0x14, 0x14, 0x14, 0x14,
    	0x14, 0x14, 0xF7, 0x00, 0xF7,
    	0x14, 0x14, 0x14, 0x17, 0x14,
    	0x10, 0x10, 0x1F, 0x10, 0x1F,
    	0x14, 0x14, 0x14, 0xF4, 0x14,
    	0x10, 0x10, 0xF0, 0x10, 0xF0,
    	0x00, 0x00, 0x1F, 0x10, 0x1F,
    	0x00, 0x00, 0x00, 0x1F, 0x14,
    	0x00, 0x00, 0x00, 0xFC, 0x14,
    	0x00, 0x00, 0xF0, 0x10, 0xF0,
    	0x10, 0x10, 0xFF, 0x10, 0xFF,
    	0x14, 0x14, 0x14, 0xFF, 0x14,
    	0x10, 0x10, 0x10, 0x1F, 0x00,
    	0x00, 0x00, 0x00, 0xF0, 0x10,
    	0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    	0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    	0xFF, 0xFF, 0xFF, 0x00, 0x00,
    	0x00, 0x00, 0x00, 0xFF, 0xFF,
    	0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
    	0x38, 0x44, 0x44, 0x38, 0x44,
    	0xFC, 0x4A, 0x4A, 0x4A, 0x34,
    	0x7E, 0x02, 0x02, 0x06, 0x06,
    	0x02, 0x7E, 0x02, 0x7E, 0x02,
    	0x63, 0x55, 0x49, 0x41, 0x63,
    	0x38, 0x44, 0x44, 0x3C, 0x04,
    	0x40, 0x7E, 0x20, 0x1E, 0x20,
    	0x06, 0x02, 0x7E, 0x02, 0x02,
    	0x99, 0xA5, 0xE7, 0xA5, 0x99,
    	0x1C, 0x2A, 0x49, 0x2A, 0x1C,
    	0x4C, 0x72, 0x01, 0x72, 0x4C,
    	0x30, 0x4A, 0x4D, 0x4D, 0x30,
    	0x30, 0x48, 0x78, 0x48, 0x30,
    	0xBC, 0x62, 0x5A, 0x46, 0x3D,
    	0x3E, 0x49, 0x49, 0x49, 0x00,
    	0x7E, 0x01, 0x01, 0x01, 0x7E,
    	0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
    	0x44, 0x44, 0x5F, 0x44, 0x44,
    	0x40, 0x51, 0x4A, 0x44, 0x40,
    	0x40, 0x44, 0x4A, 0x51, 0x40,
    	0x00, 0x00, 0xFF, 0x01, 0x03,
    	0xE0, 0x80, 0xFF, 0x00, 0x00,
    	0x08, 0x08, 0x6B, 0x6B, 0x08,
    	0x36, 0x12, 0x36, 0x24, 0x36,
    	0x06, 0x0F, 0x09, 0x0F, 0x06,
    	0x00, 0x00, 0x18, 0x18, 0x00,
    	0x00, 0x00, 0x10, 0x10, 0x00,
    	0x30, 0x40, 0xFF, 0x01, 0x01,
		0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    	0x00, 0x19, 0x1D, 0x17, 0x12,
    	0x00, 0x3C, 0x3C, 0x3C, 0x3C,
    	0x00, 0x00, 0x00, 0x00, 0x00
    };

/*---------------Various other control signals---------------------*/
#define ILI9486_SLPOUT 0x11 // Sleep mode off
#define ILI9486_DISPON 0x29 // Turn display on
#define ILI9486_CASET 0x2A  // Coloumn Address Set
#define ILI9486_PASET 0x2B  //
#define ILI9486_RAMWR 0x2C

#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define min(a,b) (((a)<(b))?(a):(b))

/*------------------LCD Screen pixel dimensions--------------------*/
#define ILI9486_TFTWIDTH  320
#define ILI9486_TFTHEIGHT 480

/*----------------------Color Definitions--------------------------*/
// 16 Bits for Color
constexpr uint16_t WHITE = 0xFFFF;
constexpr uint16_t BLACK = 0x0000;
constexpr uint16_t RED = 0xF800;
constexpr uint16_t GREEN = 0x07E0;
constexpr uint16_t BLUE = 0x001F;
constexpr uint16_t YELLOW = 0xFFE0;

/**
 * Coordinates of pixels on LCD array
 */
struct pixel_location_t {
    uint16_t x;
    uint16_t y;
};

/**
 * Interface for the ILI9486 LCD controller
 */
class LCD {
public:
	LCD() = default;

    LCD(SPI const &spi, Pin const &reg_sel, Pin const &reset)
        : m_spi(spi), m_reg_sel(reg_sel), m_reset(reset) {}

    auto init() const -> void;

    auto reset_lcd() const -> void;

    /**
     * @brief Draws a single pixel
     * @param pos position of pixel
     * @param color pixel color
     */
    auto draw_pixel(pixel_location_t pos, uint16_t color) const -> void;

    /**
     * @brief Fills the entire screen with a color
     * @param color fill color of screen
     */
    auto fill_screen(uint16_t color) const -> void;

    /**
     * @brief Clears the screen to be all white
     */
    auto clear_screen() const -> void;

    /**
     * @brief Draws a vertical line
     * @param pos starting position of line (top)
     * @param h height of the line in pixels
     * @param color fill color of rectangle
     */
    auto draw_vertical_line(pixel_location_t pos, uint16_t h, uint16_t color) const -> void;

    /**
     * @brief Draws a horizontal line that spans across the full width of the screen
     * @param pos starting position of line (left)
     * @param h height of the line in pixels
     * @param color fill color of rectangle
     */
    auto draw_horizontal_line(pixel_location_t pos, uint16_t h, uint16_t color) const -> void;

    /**
     * @brief Draws a filled color rectangle
     * @param pos top left position of rectangle
     * @param w horizontal width of rectangle in pixels
     * @param h vertical height of rectangle in pixels
     * @param color fill color of rectangle
     */
    auto draw_rectangle(pixel_location_t pos, uint16_t w, uint16_t h, uint16_t color) const -> void;

    /**
     * @brief Draws a filled color rectangle
     * @param pos top left position of bitmap
     * @param w horizontal width of bitmap in pixels
     * @param h vertical height of bitmap in pixels
     */
    auto draw_bitmap(pixel_location_t pos, uint16_t w, uint16_t h, const std::vector<uint8_t> &bitmap) const -> void;

    void drawCharTest(pixel_location_t pos, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);

    void drawPixel(pixel_location_t pos, uint16_t color);

    void drawPixelSize(pixel_location_t pos, uint16_t color, uint16_t size);


    /*------------BACKDOOR FUNCTIONS---------------*/
    auto send_command(uint8_t command) const -> void;
    auto send_data(uint8_t data) const -> void;
    auto send_data_long(uint8_t const *data, std::size_t size) const -> void;
    // set_addr_window requires that no other non image SPI data is sent after this, until transaction is over
    // Bounds of coloumn and row are inclusive
    auto set_addr_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) const -> void;

    auto start_reset() const -> void;
    auto end_reset() const -> void;
    auto set_command() const -> void;
    auto set_data() const -> void;
    auto noop() const -> void;

	auto busyWaitMs(uint32_t delay_ms) const -> void;


private:
    SPI m_spi{};
    Pin m_reg_sel{}; // LCD register select (command/data)
    Pin m_reset{};   // LCD reset
    static constexpr uint16_t width = ILI9486_TFTHEIGHT;  // width in pixels of LCD screen
    static constexpr uint16_t height = ILI9486_TFTWIDTH; // height in pixels of LCD screen

};
