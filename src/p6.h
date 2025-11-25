#ifndef p6_h
#define p6_h

#include <iostream>

namespace p6
{
    // TODO: Move implementation to .cpp file.
    class CControlCode
    {
        public:
            /// Arduino does not support va_args, so we just define multiple constructors as needed.
            //@{
            CControlCode(char a, char b)
            {
                p_controlCode = new char[2];
                p_controlCode[0] = a;
                p_controlCode[1] = b;
                u_length = 2;
            }
            CControlCode(char a, char b, char c)
            {
                p_controlCode = new char[3];
                p_controlCode[0] = a;
                p_controlCode[1] = b;
                p_controlCode[2] = c;
                u_length = 3;
            }
            CControlCode(char a, char b, char c, char d, char e)
            {
                p_controlCode = new char[5];
                p_controlCode[0] = a;
                p_controlCode[1] = b;
                p_controlCode[2] = c;
                p_controlCode[3] = d;
                p_controlCode[4] = e;
                u_length = 5;
            }
            //@}
    
            virtual ~CControlCode() { delete p_controlCode; }

            friend std::ostream& operator<<(std::ostream& os, const CControlCode& code)
            {
                for (unsigned i = 0; i < code.u_length; ++i)
                {
                    os << code.p_controlCode[i];
                }
                return os;
            }
    
        protected:
            char *p_controlCode;
            unsigned u_length;
    
            // non-copyable
            CControlCode(const CControlCode&) = delete;
            CControlCode& operator=(const CControlCode&) = delete;    
    };

    // Define NEC PinWriter P6+ control codes here.

    // Paper feed commands. TBD.

    // Carriage commands. TBD.

    // Typeface commands.
    const CControlCode draft(27, 120, 0); // ESC x 0
    const CControlCode letter(27, 120, 1); // ESC x 1
    const CControlCode lq(27, 120, 1); // ESC x 1 -- alias
    const CControlCode cpi15(27, 103); // ESC g
    const CControlCode cpi12(27, 77); // ESC M
    const CControlCode cpi10(27, 80); // ESC P
    const CControlCode draft12(27, 77, 28, 83, 0); // ESC M FS S 0 -- According to the documentation, this draft mode can only be set after selecting 12 CPI.
    const CControlCode highspeed12(27, 77, 28, 83, 1); // ESC M FS S 1 -- According to the documentation, this high-speed mode can only be set after selecting 12 CPI.
    const CControlCode cpi20(27, 33, 1|4); // ESC ! 5 -- 20 CPI is achieved by setting both the 12 CPI and marrow bits.
    const CControlCode proportional(27, 112, 1); // ESC p 1
    const CControlCode fixed(27, 112, 0); // ESC p 0
    const CControlCode wide(27, 87, 1); // ESC W 1
    const CControlCode unwide(27, 87, 0); // ESC W 0
    const CControlCode doublewide(27, 69, 1); // ESC E 1 -- How does this differ from wide?
    const CControlCode tripplewide(27, 69, 2); // ESC E 2
    const CControlCode normalwidth(27, 69, 0); // ESC E 0
    const CControlCode doublehigh(27, 86, 1); // ESC V 1
    const CControlCode normalheight(27, 86, 0); // ESC V 0
    const CControlCode narrow(27, 15); // ESC SI
    const CControlCode shadow(27, 69); // ESC E
    const CControlCode unshadow(27, 70); // ESC F
    const CControlCode bold(27, 71); // ESC G
    const CControlCode unbold(27, 72); // ESC H
    const CControlCode italic(27, 52); // ESC 4
    const CControlCode unitalic(27, 53); // ESC 5
    const CControlCode underline(27, 45, 1); // ESC - 1
    const CControlCode ununderline(27, 45, 0); // ESC - 0
    const CControlCode superscript(27, 83, 0); // ESC S 0
    const CControlCode subscript(27, 83, 1); // ESC S 1
    const CControlCode normalscript(27, 84); // ESC T
    const CControlCode courier10(27, 107, 0); // ESC k 0
    const CControlCode itcsouvenier10(27, 107, 15); // ESC k 15
    const CControlCode helvette10(27, 107, 16); // ESC k 16
    const CControlCode times10(27, 107, 18); // ESC k 18
    const CControlCode newprestigeelite12(27, 107, 19); // ESC k 19
    const CControlCode fullspeed(27, 115, 0); // ESC s 0
    const CControlCode halfspeed(27, 115, 1); // ESC s 1
    const CControlCode reset(27, 64); // ESC @

}

#endif // p6_h