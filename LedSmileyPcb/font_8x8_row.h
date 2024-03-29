/** 
 * 8x8 monochrome bitmap fonts for rendering
 * 
 **/

// Constant: font8x8_basic
// Contains an 8x8 font map for unicode points U+0000 - U+007F (basic latin)
const char font_8x8_row[128][8] PROGMEM = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0000 (nul)
    { 0x7E, 0x81, 0xA9, 0x8D, 0x8D, 0xA9, 0x81, 0x7E },   // U+0001
    { 0x7E, 0xFF, 0xD7, 0xF3, 0xF3, 0xD7, 0xFF, 0x7E },   // U+0002
    { 0x70, 0xF8, 0xFC, 0x7E, 0xFC, 0xF8, 0x70, 0x00 },   // U+0003
    { 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00 },   // U+0004
    { 0x18, 0x5D, 0xFF, 0xFF, 0xFF, 0x5D, 0x18, 0x00 },   // U+0005
    { 0x08, 0x1D, 0x3F, 0xFF, 0x3F, 0x1D, 0x08, 0x00 },   // U+0006
    { 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00 },   // U+0007
    { 0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF },   // U+0008
    { 0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00 },   // U+0009
    { 0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF },   // U+000A
    { 0x0E, 0x1F, 0x11, 0x11, 0xBF, 0xFE, 0xE0, 0xF0 },   // U+000B
    { 0x00, 0x72, 0xFA, 0x8F, 0x8F, 0xFA, 0x72, 0x00 },   // U+000C
    { 0x03, 0x07, 0xFF, 0xFE, 0xA0, 0xA0, 0xE0, 0xE0 },   // U+000D
    { 0x03, 0xFF, 0xFE, 0xA0, 0xA0, 0xA6, 0xFE, 0xFC },   // U+000E
    { 0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99 },   // U+000F
    { 0xFE, 0x7C, 0x7C, 0x38, 0x38, 0x10, 0x10, 0x00 },   // U+0010
    { 0x10, 0x10, 0x38, 0x38, 0x7C, 0x7C, 0xFE, 0x00 },   // U+0011
    { 0x00, 0x24, 0x66, 0xFF, 0xFF, 0x66, 0x24, 0x00 },   // U+0012
    { 0x00, 0xFA, 0xFA, 0x00, 0xFA, 0xFA, 0x00, 0x00 },   // U+0013
    { 0x60, 0xF0, 0x90, 0xFE, 0xFE, 0x80, 0xFE, 0xFE },   // U+0014
    { 0x02, 0x5B, 0xFD, 0xA5, 0xBF, 0x9A, 0xC0, 0x40 },   // U+0015
    { 0x00, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x00 },   // U+0016
    { 0x01, 0x29, 0x6D, 0xFF, 0xFF, 0x6D, 0x29, 0x01 },   // U+0017
    { 0x00, 0x20, 0x60, 0xFE, 0xFE, 0x60, 0x20, 0x00 },   // U+0018
    { 0x00, 0x08, 0x0C, 0xFE, 0xFE, 0x0C, 0x08, 0x00 },   // U+0019
    { 0x10, 0x10, 0x10, 0x54, 0x7C, 0x38, 0x10, 0x00 },   // U+001A
    { 0x10, 0x38, 0x7C, 0x54, 0x10, 0x10, 0x10, 0x00 },   // U+001B
    { 0x3C, 0x3C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00 },   // U+001C
    { 0x10, 0x38, 0x7C, 0x10, 0x10, 0x7C, 0x38, 0x10 },   // U+001D
    { 0x08, 0x18, 0x38, 0x78, 0x78, 0x38, 0x18, 0x08 },   // U+001E
    { 0x40, 0x60, 0x70, 0x78, 0x78, 0x70, 0x60, 0x40 },   // U+001F
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0020 (space)
    { 0x00, 0x60, 0xFA, 0xFA, 0x60, 0x00, 0x00, 0x00 },   // U+0021 (!)
    { 0x00, 0xE0, 0xE0, 0x00, 0xE0, 0xE0, 0x00, 0x00 },   // U+0022 (")
    { 0x28, 0xFE, 0xFE, 0x28, 0xFE, 0xFE, 0x28, 0x00 },   // U+0023 (#)
    { 0x24, 0x74, 0xD6, 0xD6, 0x5C, 0x48, 0x00, 0x00 },   // U+0024 ($)
    { 0x62, 0x66, 0x0C, 0x18, 0x30, 0x66, 0x46, 0x00 },   // U+0025 (%)
    { 0x0C, 0x5E, 0xF2, 0xBA, 0xEC, 0x5E, 0x12, 0x00 },   // U+0026 (&)
    { 0x20, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00 },   // U+0027 (')
    { 0x00, 0x38, 0x7C, 0xC6, 0x82, 0x00, 0x00, 0x00 },   // U+0028 (()
    { 0x00, 0x81, 0xC3, 0x7E, 0x3C, 0x00, 0x00, 0x00 },   // U+0029 ())
    { 0x10, 0x54, 0x7C, 0x38, 0x38, 0x7C, 0x54, 0x10 },   // U+002A (*)
    { 0x10, 0x10, 0x7C, 0x7C, 0x10, 0x10, 0x00, 0x00 },   // U+002B (+)
    { 0x00, 0x01, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00 },   // U+002C (,)
    { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00 },   // U+002D (-)
    { 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00 },   // U+002E (.)
    { 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00 },   // U+002F (/)
    { 0x7C, 0xFE, 0x8E, 0x9A, 0xB2, 0xFE, 0x7C, 0x00 },   // U+0030 (0)
    { 0x02, 0x42, 0xFE, 0xFE, 0x02, 0x02, 0x00, 0x00 },   // U+0031 (1)
    { 0x46, 0xCE, 0x9A, 0x92, 0xF6, 0x66, 0x00, 0x00 },   // U+0032 (2)
    { 0x44, 0xC6, 0x92, 0x92, 0xFE, 0x6C, 0x00, 0x00 },   // U+0033 (3)
    { 0x18, 0x38, 0x68, 0xCA, 0xFE, 0xFE, 0x0A, 0x00 },   // U+0034 (4)
    { 0xE4, 0xE6, 0xA2, 0xA2, 0xBE, 0x9C, 0x00, 0x00 },   // U+0035 (5)
    { 0x3C, 0x7E, 0xD2, 0x92, 0x9E, 0x0C, 0x00, 0x00 },   // U+0036 (6)
    { 0xC0, 0xC0, 0x8E, 0x9E, 0xF0, 0xE0, 0x00, 0x00 },   // U+0037 (7)
    { 0x6C, 0xFE, 0x92, 0x92, 0xFE, 0x6C, 0x00, 0x00 },   // U+0038 (8)
    { 0x60, 0xF2, 0x92, 0x96, 0xFC, 0x78, 0x00, 0x00 },   // U+0039 (9)
    { 0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00 },   // U+003A (:)
    { 0x00, 0x01, 0x67, 0x66, 0x00, 0x00, 0x00, 0x00 },   // U+003B (;)
    { 0x10, 0x38, 0x6C, 0xC6, 0x82, 0x00, 0x00, 0x00 },   // U+003C (<)
    { 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00 },   // U+003D (=)
    { 0x00, 0x82, 0xC6, 0x6C, 0x38, 0x10, 0x00, 0x00 },   // U+003E (>)
    { 0x40, 0xC0, 0x8A, 0x9A, 0xF0, 0x60, 0x00, 0x00 },   // U+003F (?)
    { 0x7C, 0xFE, 0x82, 0xBA, 0xBA, 0xF8, 0x78, 0x00 },   // U+0040 (@)
    { 0x3E, 0x7E, 0xC8, 0xC8, 0xC8, 0x7E, 0x3E, 0x00 },   // U+0041 (A)
    { 0x82, 0xFE, 0xFE, 0x92, 0x92, 0xFE, 0x6C, 0x00 },   // U+0042 (B)
    { 0x38, 0x7C, 0xC6, 0x82, 0x82, 0xC6, 0x44, 0x00 },   // U+0043 (C)
    { 0x82, 0xFE, 0xFE, 0x82, 0xC6, 0x7C, 0x38, 0x00 },   // U+0044 (D)
    { 0x82, 0xFE, 0xFE, 0x92, 0xBA, 0x82, 0xC6, 0x00 },   // U+0045 (E)
    { 0x82, 0xFE, 0xFE, 0x92, 0xB8, 0x80, 0xC0, 0x00 },   // U+0046 (F)
    { 0x38, 0x7C, 0xC6, 0x82, 0x8A, 0xCE, 0x4E, 0x00 },   // U+0047 (G)
    { 0xFE, 0xFE, 0x10, 0x10, 0xFE, 0xFE, 0x00, 0x00 },   // U+0048 (H)
    { 0x00, 0x82, 0xFE, 0xFE, 0x82, 0x00, 0x00, 0x00 },   // U+0049 (I)
    { 0x0C, 0x0E, 0x02, 0x82, 0xFE, 0xFC, 0x80, 0x00 },   // U+004A (J)
    { 0x82, 0xFE, 0xFE, 0x10, 0x38, 0xEE, 0xC6, 0x00 },   // U+004B (K)
    { 0x82, 0xFE, 0xFE, 0x82, 0x02, 0x06, 0x0E, 0x00 },   // U+004C (L)
    { 0xFE, 0xFE, 0x70, 0x38, 0x70, 0xFE, 0xFE, 0x00 },   // U+004D (M)
    { 0xFE, 0xFE, 0x60, 0x30, 0x18, 0xFE, 0xFE, 0x00 },   // U+004E (N)
    { 0x38, 0x7C, 0xC6, 0x82, 0xC6, 0x7C, 0x38, 0x00 },   // U+004F (O)
    { 0x82, 0xFE, 0xFE, 0x92, 0x90, 0xF0, 0x60, 0x00 },   // U+0050 (P)
    { 0x78, 0xFC, 0x84, 0x8E, 0xFE, 0x7A, 0x00, 0x00 },   // U+0051 (Q)
    { 0x82, 0xFE, 0xFE, 0x90, 0x98, 0xFE, 0x66, 0x00 },   // U+0052 (R)
    { 0x64, 0xF6, 0xB2, 0x9A, 0xCE, 0x4C, 0x00, 0x00 },   // U+0053 (S)
    { 0xC0, 0x82, 0xFE, 0xFE, 0x82, 0xC0, 0x00, 0x00 },   // U+0054 (T)
    { 0xFE, 0xFE, 0x02, 0x02, 0xFE, 0xFE, 0x00, 0x00 },   // U+0055 (U)
    { 0xF8, 0xFC, 0x06, 0x06, 0xFC, 0xF8, 0x00, 0x00 },   // U+0056 (V)
    { 0xFE, 0xFE, 0x0C, 0x18, 0x0C, 0xFE, 0xFE, 0x00 },   // U+0057 (W)
    { 0xC2, 0xE6, 0x3C, 0x18, 0x3C, 0xE6, 0xC2, 0x00 },   // U+0058 (X)
    { 0xE0, 0xF2, 0x1E, 0x1E, 0xF2, 0xE0, 0x00, 0x00 },   // U+0059 (Y)
    { 0xE2, 0xC6, 0x8E, 0x9A, 0xB2, 0xE6, 0xCE, 0x00 },   // U+005A (Z)
    { 0x00, 0xFE, 0xFE, 0x82, 0x82, 0x00, 0x00, 0x00 },   // U+005B ([)
    { 0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x00 },   // U+005C (\)
    { 0x00, 0x82, 0x82, 0xFE, 0xFE, 0x00, 0x00, 0x00 },   // U+005D (])
    { 0x10, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x10, 0x00 },   // U+005E (^)
    { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 },   // U+005F (_)
    { 0x00, 0x00, 0xC0, 0xE0, 0x20, 0x00, 0x00, 0x00 },   // U+0060 (`)
    { 0x04, 0x2E, 0x2A, 0x2A, 0x3C, 0x1E, 0x02, 0x00 },   // U+0061 (a)
    { 0x82, 0xFE, 0xFC, 0x12, 0x12, 0x1E, 0x0C, 0x00 },   // U+0062 (b)
    { 0x1C, 0x3E, 0x22, 0x22, 0x36, 0x14, 0x00, 0x00 },   // U+0063 (c)
    { 0x0C, 0x1E, 0x12, 0x92, 0xFC, 0xFE, 0x02, 0x00 },   // U+0064 (d)
    { 0x1C, 0x3E, 0x2A, 0x2A, 0x3A, 0x18, 0x00, 0x00 },   // U+0065 (e)
    { 0x12, 0x7E, 0xFE, 0x92, 0xC0, 0x40, 0x00, 0x00 },   // U+0066 (f)
    { 0x19, 0x3D, 0x25, 0x25, 0x1F, 0x3E, 0x20, 0x00 },   // U+0067 (g)
    { 0x82, 0xFE, 0xFE, 0x10, 0x20, 0x3E, 0x1E, 0x00 },   // U+0068 (h)
    { 0x00, 0x22, 0xBE, 0xBE, 0x02, 0x00, 0x00, 0x00 },   // U+0069 (i)
    { 0x06, 0x07, 0x01, 0x01, 0xBF, 0xBE, 0x00, 0x00 },   // U+006A (j)
    { 0x82, 0xFE, 0xFE, 0x08, 0x1C, 0x36, 0x22, 0x00 },   // U+006B (k)
    { 0x00, 0x82, 0xFE, 0xFE, 0x02, 0x00, 0x00, 0x00 },   // U+006C (l)
    { 0x3E, 0x3E, 0x10, 0x18, 0x30, 0x3E, 0x1E, 0x00 },   // U+006D (m)
    { 0x3E, 0x3E, 0x20, 0x20, 0x3E, 0x1E, 0x00, 0x00 },   // U+006E (n)
    { 0x1C, 0x3E, 0x22, 0x22, 0x3E, 0x1C, 0x00, 0x00 },   // U+006F (o)
    { 0x21, 0x3F, 0x1F, 0x25, 0x24, 0x3C, 0x18, 0x00 },   // U+0070 (p)
    { 0x18, 0x3C, 0x24, 0x25, 0x1F, 0x3F, 0x21, 0x00 },   // U+0071 (q)
    { 0x22, 0x3E, 0x1E, 0x32, 0x20, 0x38, 0x18, 0x00 },   // U+0072 (r)
    { 0x12, 0x3A, 0x2A, 0x2A, 0x2E, 0x24, 0x00, 0x00 },   // U+0073 (s)
    { 0x00, 0x20, 0x7C, 0xFE, 0x22, 0x24, 0x00, 0x00 },   // U+0074 (t)
    { 0x3C, 0x3E, 0x02, 0x02, 0x3C, 0x3E, 0x02, 0x00 },   // U+0075 (u)
    { 0x38, 0x3C, 0x06, 0x06, 0x3C, 0x38, 0x00, 0x00 },   // U+0076 (v)
    { 0x3C, 0x3E, 0x0E, 0x1C, 0x0E, 0x3E, 0x3C, 0x00 },   // U+0077 (w)
    { 0x22, 0x36, 0x1C, 0x08, 0x1C, 0x36, 0x22, 0x00 },   // U+0078 (x)
    { 0x39, 0x3D, 0x05, 0x05, 0x3F, 0x3E, 0x00, 0x00 },   // U+0079 (y)
    { 0x32, 0x26, 0x2E, 0x3A, 0x32, 0x26, 0x00, 0x00 },   // U+007A (z)
    { 0x10, 0x10, 0x7C, 0xEE, 0x82, 0x82, 0x00, 0x00 },   // U+007B ({)
    { 0x00, 0x00, 0x00, 0xEE, 0xEE, 0x00, 0x00, 0x00 },   // U+007C (|)
    { 0x82, 0x82, 0xEE, 0x7C, 0x10, 0x10, 0x00, 0x00 },   // U+007D (})
    { 0x40, 0xC0, 0x80, 0xC0, 0x40, 0xC0, 0x80, 0x00 },   // U+007E (~)
    { 0x0E, 0x1E, 0x32, 0x62, 0x32, 0x1E, 0x0E, 0x00 }    // U+007F
};
