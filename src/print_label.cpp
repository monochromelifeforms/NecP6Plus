#include <vector>
#include <iostream>
#include <string>

// Can't use enum class because we need to do bitwise operations.
typedef enum {
    CPI10 = 0,
    CPI12 = 1,
    Proportional = 2,
    Narrow = 4,
    Shadow = 8,
    Bold = 16,
    Wide = 32,
    Italic = 64,
    Underline = 128
} TypeFace_t;

class CControlCode 
{
    public:
        CControlCode() {}
        virtual ~CControlCode() {}

        virtual void Serialize(std::vector<char>& bitstream) const =0;
};

class CCcTypeFace : public CControlCode
{
    public:
        CCcTypeFace() 
        {
            s_code[0] = 27;
            s_code[1] = 33;;
            s_code[2] = 0;
        }
        CCcTypeFace(char bitPattern)
            : CCcTypeFace()
        {
            s_code[2] = bitPattern;
        }

        void Serialize(std::vector<char>& bitstream) const override
        {
            bitstream.insert(bitstream.end(), s_code, s_code + 3);
        }

    protected:
        char s_code[3];
};

int main(int argc, char* argv[])
{
    try
    {
        std::string text{"Hello, World!"};
        CCcTypeFace typeFace(CPI10 | Bold | Underline);
        std::vector<char> bitstream;
        typeFace.Serialize(bitstream);
        bitstream.insert(bitstream.end(), text.begin(), text.end());

        for (char c : bitstream)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown exception occurred" << std::endl;
        return 1;
    }
    return 0;
}