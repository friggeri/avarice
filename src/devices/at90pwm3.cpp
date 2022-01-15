#include "../jtag.h"

namespace {

constexpr gdb_io_reg_def_type at90pwm3_io_registers[] = {
    {"PINB", 0x23, 0x00},       {"DDRB", 0x24, 0x00},
    {"PORTB", 0x25, 0x00},      {"PINC", 0x26, 0x00},
    {"DDRC", 0x27, 0x00},       {"PORTC", 0x28, 0x00},
    {"PIND", 0x29, 0x00},       {"DDRD", 0x2a, 0x00},
    {"PORTD", 0x2b, 0x00},      {"PINE", 0x2c, 0x00},
    {"DDRE", 0x2d, 0x00},       {"PORTE", 0x2e, 0x00},
    {"TIFR0", 0x35, 0x00},      {"TIFR1", 0x36, 0x00},
    {"GPIOR1", 0x39, 0x00},     {"GPIOR2", 0x3a, 0x00},
    {"GPIOR3", 0x3b, 0x00},     {"EIFR", 0x3c, 0x00},
    {"EIMSK", 0x3d, 0x00},      {"GPIOR0", 0x3e, 0x00},
    {"EECR", 0x3f, 0x00},       {"EEDR", 0x40, 0x00},
    {"EEARL", 0x41, 0x00},      {"EEARH", 0x42, 0x00},
    {"GTCCR", 0x43, 0x00},      {"TCCR0A", 0x44, 0x00},
    {"TCCR0B", 0x45, 0x00},     {"TCNT0", 0x46, 0x00},
    {"OCR0A", 0x47, 0x00},      {"OCR0B", 0x48, 0x00},
    {"PLLCSR", 0x49, 0x00},     {"SPCR", 0x4c, 0x00},
    {"SPSR", 0x4d, 0x00},       {"SPDR", 0x4e, 0x00},
    {"ACSR", 0x50, 0x00},       {"MONDR", 0x51, 0x00},
    {"MSMCR", 0x52, 0x00},      {"SMCR", 0x53, 0x00},
    {"MCUSR", 0x54, 0x00},      {"MCUCR", 0x55, 0x00},
    {"SPMCSR", 0x57, 0x00},     {"SPL", 0x5d, 0x00},
    {"SPH", 0x5e, 0x00},        {"SREG", 0x5f, 0x00},
    {"WDTCSR", 0x60, 0x00},     {"CLKPR", 0x61, 0x00},
    {"PRR", 0x64, 0x00},        {"OSCCAL", 0x66, 0x00},
    {"EICRA", 0x69, 0x00},      {"TIMSK0", 0x6e, 0x00},
    {"TIMSK1", 0x6f, 0x00},     {"AMP0CSR", 0x76, 0x00},
    {"AMP1CSR", 0x77, 0x00},    {"ADCL", 0x78, IO_REG_RSE},
    {"ADCH", 0x79, IO_REG_RSE}, {"ADCSRA", 0x7a, 0x00},
    {"ADCSRB", 0x7b, 0x00},     {"ADMUX", 0x7c, 0x00},
    {"DIDR0", 0x7e, 0x00},      {"DIDR1", 0x7f, 0x00},
    {"TCCR1A", 0x80, 0x00},     {"TCCR1B", 0x81, 0x00},
    {"TCCR1C", 0x82, 0x00},     {"TCNT1L", 0x84, 0x00},
    {"TCNT1H", 0x85, 0x00},     {"ICR1L", 0x86, 0x00},
    {"ICR1H", 0x87, 0x00},      {"OCR1AL", 0x88, 0x00},
    {"OCR1AH", 0x89, 0x00},     {"OCR1BL", 0x8a, 0x00},
    {"OCR1BH", 0x8b, 0x00},     {"PIFR0", 0xa0, 0x00},
    {"PIM0", 0xa1, 0x00},       {"PIFR1", 0xa2, 0x00},
    {"PIM1", 0xa3, 0x00},       {"PIFR2", 0xa4, 0x00},
    {"PIM2", 0xa5, 0x00},       {"DACON", 0xaa, 0x00},
    {"DACL", 0xab, 0x00},       {"DACH", 0xac, 0x00},
    {"AC0CON", 0xad, 0x00},     {"AC1CON", 0xae, 0x00},
    {"AC2CON", 0xaf, 0x00},     {"UCSRA", 0xc0, 0x00},
    {"UCSRB", 0xc1, 0x00},      {"UCSRC", 0xc2, 0x00},
    {"UBRRL", 0xc4, 0x00},      {"UBRRH", 0xc5, 0x00},
    {"UDR", 0xc6, IO_REG_RSE},  {"EUCSRA", 0xc8, 0x00},
    {"EUCSRB", 0xc9, 0x00},     {"EUCSRC", 0xca, 0x00},
    {"MUBRRL", 0xcc, 0x00},     {"MUBRRH", 0xcd, 0x00},
    {"EUDR", 0xce, 0x00},       {"PSOC0", 0xd0, 0x00},
    {"OCR0SAL", 0xd2, 0x00},    {"OCR0SAH", 0xd3, 0x00},
    {"OCR0RAL", 0xd4, 0x00},    {"OCR0RAH", 0xd5, 0x00},
    {"OCR0SBL", 0xd6, 0x00},    {"OCR0SBH", 0xd7, 0x00},
    {"OCR0RBL", 0xd8, 0x00},    {"OCR0RBH", 0xd9, 0x00},
    {"PCNF0", 0xda, 0x00},      {"PCTL0", 0xdb, 0x00},
    {"PFRC0A", 0xdc, 0x00},     {"PFRC0B", 0xdd, 0x00},
    {"PICR0L", 0xde, 0x00},     {"PICR0H", 0xdf, 0x00},
    {"PSOC1", 0xe0, 0x00},      {"OCR1SAL", 0xe2, 0x00},
    {"OCR1SAH", 0xe3, 0x00},    {"OCR1RAL", 0xe4, 0x00},
    {"OCR1RAH", 0xe5, 0x00},    {"OCR1SBL", 0xe6, 0x00},
    {"OCR1SBH", 0xe7, 0x00},    {"OCR1RBL", 0xe8, 0x00},
    {"OCR1RBH", 0xe9, 0x00},    {"PCNF1", 0xea, 0x00},
    {"PCTL1", 0xeb, 0x00},      {"PFRC1A", 0xec, 0x00},
    {"PFRC1B", 0xed, 0x00},     {"PICR1L", 0xee, 0x00},
    {"PICR1H", 0xef, 0x00},     {"PSOC2", 0xf0, 0x00},
    {"POM2", 0xf1, 0x00},       {"OCR2SAL", 0xf2, 0x00},
    {"OCR2SAH", 0xf3, 0x00},    {"OCR2RAL", 0xf4, 0x00},
    {"OCR2RAH", 0xf5, 0x00},    {"OCR2SBL", 0xf6, 0x00},
    {"OCR2SBH", 0xf7, 0x00},    {"OCR2RBL", 0xf8, 0x00},
    {"OCR2RBH", 0xf9, 0x00},    {"PCNF2", 0xfa, 0x00},
    {"PCTL2", 0xfb, 0x00},      {"PFRC2A", 0xfc, 0x00},
    {"PFRC2B", 0xfd, 0x00},     {"PICR2L", 0xfe, 0x00},
    {"PICR2H", 0xff, 0x00},     {nullptr, 0, 0}};

[[maybe_unused]] const jtag_device_def_type at90pwm3{
    "at90pwm3",
    0x9381,
    64,
    128, // 8192 bytes flash
    4,
    128,    // 512 bytes EEPROM
    32 * 2, // 32 interrupt vectors
    NO_TWEAKS,
    at90pwm3_io_registers,
    0x07,
    0x0000, // fuses
    0x66,   // osccal
    1,      // OCD revision
    nullptr,
    {
        CMND_SET_DEVICE_DESCRIPTOR,
        {0xF8, 0x7F, 0x60, 0xFE, 0xFF, 0x33, 0xBD, 0xE0}, // ucReadIO
        {0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00}, // ucReadIOShadow
        {0xF8, 0x7F, 0x40, 0xEE, 0xFF, 0x33, 0xBC, 0xE0}, // ucWriteIO
        {0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00}, // ucWriteIOShadow
        {0x53, 0xC2, 0xC0, 0xDF, 0xF7, 0x0F, 0x00, 0x00, 0x3F, 0xE4,
         0x00, 0x00, 0x36, 0x37, 0x01, 0xFC, 0x05, 0xFC, 0x07, 0xFC}, // ucReadExtIO
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ucReadIOExtShadow
        {0x11, 0xC2, 0xC0, 0xD8, 0xF7, 0x0F, 0x00, 0x00, 0x3F, 0xE4,
         0x00, 0x00, 0x36, 0x33, 0x01, 0xFC, 0x05, 0xFC, 0x07, 0xFC}, // ucWriteExtIO
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ucWriteIOExtShadow
        0x00,                                                         // ucIDRAddress
        0X00,                                                         // ucSPMCRAddress
        0,                                                            // ucRAMPZAddress
        fill_b2(64),                                                  // uiFlashPageSize
        4,                                                            // ucEepromPageSize
        fill_b4(0x0F80),                                              // ulBootAddress
        fill_b2(0xFF),                                                // uiUpperExtIOLoc
        fill_b4(8192),                                                // ulFlashSize
        {0xBD, 0xF2, 0xBD, 0xE1, 0xBB, 0xCF, 0xB4, 0x00, 0xBE, 0x01,
         0xB6, 0x01, 0xBC, 0x00, 0xBB, 0xBF, 0x99, 0xF9, 0xBB, 0xAF}, // ucEepromInst
        {0xB6, 0x01, 0x11},                                           // ucFlashInst
        0x3E,                                                         // ucSPHaddr
        0x3D,                                                         // ucSPLaddr
        fill_b2(8192 / 64),                                           // uiFlashpages
        0x31,                                                         // ucDWDRAddress
        0x00,                                                         // ucDWBasePC
        0x00,                                                         // ucAllowFullPageBitstream
        fill_b2(0xF80),  // uiStartSmallestBootLoaderSection
        1,               // EnablePageProgramming
        0,               // ucCacheType
        fill_b2(0x0100), // uiSramStartAddr
        0,               // ucResetType
        0,               // ucPCMaskExtended
        0,               // ucPCMaskHigh
        0,               // ucEindAddress
        fill_b2(0x1F),   // EECRAddress
    },
    nullptr
};

} // namespace
