#include "../jtag.h"

namespace {

constexpr gdb_io_reg_def_type attiny48_io_registers[] = {{"PINB", 0x23, 0x00},
                                                     {"DDRB", 0x24, 0x00},
                                                     {"PORTB", 0x25, 0x00},
                                                     {"PINC", 0x26, 0x00},
                                                     {"DDRC", 0x27, 0x00},
                                                     {"PORTC", 0x28, 0x00},
                                                     {"PIND", 0x29, 0x00},
                                                     {"DDRD", 0x2a, 0x00},
                                                     {"PORTD", 0x2b, 0x00},
                                                     {"PINA", 0x2c, 0x00},
                                                     {"DDRA", 0x2d, 0x00},
                                                     {"PORTA", 0x2e, 0x00},
                                                     {"PORTCR", 0x32, 0x00},
                                                     {"TIFR0", 0x35, 0x00},
                                                     {"TIFR1", 0x36, 0x00},
                                                     {"PCIFR", 0x3b, 0x00},
                                                     {"EIFR", 0x3c, 0x00},
                                                     {"EIMSK", 0x3d, 0x00},
                                                     {"GPIOR0", 0x3e, 0x00},
                                                     {"EECR", 0x3f, 0x00},
                                                     {"EEDR", 0x40, 0x00},
                                                     {"EEARL", 0x41, 0x00},
                                                     {"GTCCR", 0x43, 0x00},
                                                     {"TCCR0A", 0x45, 0x00},
                                                     {"TCNT0", 0x46, 0x00},
                                                     {"OCR0A", 0x47, 0x00},
                                                     {"OCR0B", 0x48, 0x00},
                                                     {"GPIOR1", 0x4a, 0x00},
                                                     {"GPIOR2", 0x4b, 0x00},
                                                     {"SPCR", 0x4c, 0x00},
                                                     {"SPSR", 0x4d, 0x00},
                                                     {"SPDR", 0x4e, 0x00},
                                                     {"ACSR", 0x50, 0x00},
                                                     {"SMCR", 0x53, 0x00},
                                                     {"MCUSR", 0x54, 0x00},
                                                     {"MCUCR", 0x55, 0x00},
                                                     {"SPMCSR", 0x57, 0x00},
                                                     {"SPL", 0x5d, 0x00},
                                                     {"SPH", 0x5e, 0x00},
                                                     {"SREG", 0x5f, 0x00},
                                                     {"WDTCSR", 0x60, 0x00},
                                                     {"CLKPR", 0x61, 0x00},
                                                     {"PRR", 0x64, 0x00},
                                                     {"OSCCAL", 0x66, 0x00},
                                                     {"PCICR", 0x68, 0x00},
                                                     {"EICRA", 0x69, 0x00},
                                                     {"PCMSK3", 0x6a, 0x00},
                                                     {"PCMSK0", 0x6b, 0x00},
                                                     {"PCMSK1", 0x6c, 0x00},
                                                     {"PCMSK2", 0x6d, 0x00},
                                                     {"TIMSK0", 0x6e, 0x00},
                                                     {"TIMSK1", 0x6f, 0x00},
                                                     {"ADCL", 0x78, IO_REG_RSE},
                                                     {"ADCH", 0x79, IO_REG_RSE},
                                                     {"ADCSRA", 0x7a, 0x00},
                                                     {"ADCSRB", 0x7b, 0x00},
                                                     {"ADMUX", 0x7c, 0x00},
                                                     {"DIDR0", 0x7e, 0x00},
                                                     {"DIDR1", 0x7f, 0x00},
                                                     {"TCCR1A", 0x80, 0x00},
                                                     {"TCCR1B", 0x81, 0x00},
                                                     {"TCCR1C", 0x82, 0x00},
                                                     {"TCNT1L", 0x84, 0x00},
                                                     {"TCNT1H", 0x85, 0x00},
                                                     {"ICR1L", 0x86, 0x00},
                                                     {"ICR1H", 0x87, 0x00},
                                                     {"OCR1AL", 0x88, 0x00},
                                                     {"OCR1AH", 0x89, 0x00},
                                                     {"OCR1BL", 0x8a, 0x00},
                                                     {"OCR1BH", 0x8b, 0x00},
                                                     {"TWBR", 0xb8, 0x00},
                                                     {"TWSR", 0xb9, 0x00},
                                                     {"TWAR", 0xba, 0x00},
                                                     {"TWDR", 0xbb, 0x00},
                                                     {"TWCR", 0xbc, 0x00},
                                                     {"TWAMR", 0xbd, 0x00},
                                                     {"TWIHSR -- TWHSR", 0xbe, 0x00},
                                                     {nullptr, 0, 0}};

[[maybe_unused]] const jtag_device_def_type device{
    "attiny48",
    0x9209,
    64,
    64, // 4096 bytes flash
    4,
    16,     // 64 bytes EEPROM
    20 * 2, // 20 interrupt vectors
    NO_TWEAKS,
    attiny48_io_registers,
    0x07,
    0x0000, // fuses
    0x66,   // osccal
    1,      // OCD revision
    nullptr,
    {
        CMND_SET_DEVICE_DESCRIPTOR,
        {0xF8, 0x7F, 0x64, 0xF8, 0xEB, 0x3D, 0xB9, 0xA0}, // ucReadIO
        {0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00}, // ucReadIOShadow
        {0xB0, 0x0D, 0x00, 0xE0, 0xFB, 0x1D, 0xB8, 0xA0}, // ucWriteIO
        {0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00}, // ucWriteIOShadow
        {0x53, 0xFF, 0x00, 0xDF, 0xF7, 0x0F, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ucReadExtIO
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ucReadIOExtShadow
        {0x00, 0xFF, 0x00, 0xDC, 0xF7, 0x0F, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ucWriteExtIO
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ucWriteIOExtShadow
        0x00,                                                         // ucIDRAddress
        0X00,                                                         // ucSPMCRAddress
        0,                                                            // ucRAMPZAddress
        fill_b2(64),                                                  // uiFlashPageSize
        4,                                                            // ucEepromPageSize
        fill_b4(0x0000),                                              // ulBootAddress
        fill_b2(0xBD),                                                // uiUpperExtIOLoc
        fill_b4(4096),                                                // ulFlashSize
        {0xBD, 0xF2, 0xBD, 0xE1, 0xBB, 0xCF, 0xB4, 0x00, 0xBE, 0x01,
         0xB6, 0x01, 0xBC, 0x00, 0xBB, 0xBF, 0x99, 0xF9, 0xBB, 0xAF}, // ucEepromInst
        {0xB6, 0x01, 0x11},                                           // ucFlashInst
        0x3E,                                                         // ucSPHaddr
        0x3D,                                                         // ucSPLaddr
        fill_b2(4096 / 64),                                           // uiFlashpages
        0x31,                                                         // ucDWDRAddress
        0x00,                                                         // ucDWBasePC
        0x00,                                                         // ucAllowFullPageBitstream
        fill_b2(0x00),  // uiStartSmallestBootLoaderSection
        1,              // EnablePageProgramming
        0,              // ucCacheType
        fill_b2(0x100), // uiSramStartAddr
        0,              // ucResetType
        0,              // ucPCMaskExtended
        0,              // ucPCMaskHigh
        0,              // ucEindAddress
        fill_b2(0x1F),  // EECRAddress
    },
    nullptr
};

} // namespace
