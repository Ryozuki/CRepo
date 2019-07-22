#ifndef COLOR_H
#define COLOR_H

#define COLOR_MODE(x) "\x1b[" #x "m"
#define COLOR_RESET() COLOR_MODE(0)
#define COLOR_BOLD() COLOR_MODE(1)
#define COLOR_FAINT() COLOR_MODE(2)
#define COLOR_ITALIC() COLOR_MODE(3)
#define COLOR_BOLD_ITALIC() COLOR_BOLD() COLOR_ITALIC()
#define COLOR_UNDERLINE() COLOR_MODE(4)
#define COLOR_REVERSE() COLOR_MODE(7)
#define COLOR_CROSSED_OUT() COLOR_MODE(9)
#define COLOR_UNDERLINE_OFF() COLOR_MODE(24)
#define COLOR_FRAMED() COLOR_MODE(51)
#define COLOR_ENCIRCLED() COLOR_MODE(52)
#define COLOR_OVERLINED() COLOR_MODE(53)

#define COLOR_BASE(x) "\x1b[38;5;" #x "m"
#define COLOR_BASE_BG(x) "\x1b[48;5;" #x "m"
#define COLOR_RGB(r, g, b) "\x1b[38;2;" #r ";" #g ";" #b "m"
#define COLOR_RGB_BG(r, g, b) "\x1b[48;2;" #r ";" #g ";" #b "m"

#define COLOR_BLACK COLOR_BASE(0)
#define COLOR_RED COLOR_BASE(1)
#define COLOR_GREEN COLOR_BASE(2)
#define COLOR_YELLOW COLOR_BASE(3)
#define COLOR_BLUE COLOR_BASE(4)
#define COLOR_MAGENTA COLOR_BASE(5)
#define COLOR_CYAN COLOR_BASE(6)
#define COLOR_WHITE COLOR_BASE(7)

#define COLOR_BLACK_BG COLOR_BASE_BG(0)
#define COLOR_RED_BG COLOR_BASE_BG(1)
#define COLOR_GREEN_BG COLOR_BASE_BG(2)
#define COLOR_YELLOW_BG COLOR_BASE_BG(3)
#define COLOR_BLUE_BG COLOR_BASE_BG(4)
#define COLOR_MAGENTA_BG COLOR_BASE_BG(5)
#define COLOR_CYAN_BG COLOR_BASE_BG(6)
#define COLOR_WHITE_BG COLOR_BASE_BG(7)

#endif // COLOR_H
