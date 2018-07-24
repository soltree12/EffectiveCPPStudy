#include <iostream>

enum class FontHandle {NANUM, GOTHIC, ARIAL};

FontHandle getFont()
{
	return FontHandle::GOTHIC;
}

void releaseFont(FontHandle fh)
{
}

class Font { // RAII 클래스
public:
	explicit Font(FontHandle fh) : f(fh) {}
	~Font() { releaseFont(f); }
	FontHandle get() const { return f; } // 명시적 변환 함수(Font 객체를 FontHandle로 변환)
	operator FontHandle() const { return f; } // 암시적 변환 함수(Font 객체를 FontHandle로 변환)
		
private:
	FontHandle f; // 실제 자원
};

void changeFontSize(FontHandle f, int newSize) // Font를 사용하는 함수
{
	std::cout << static_cast<int>(f) << "/" << newSize << std::endl;
}

int main_2()
{
	Font f(getFont());
	int newFontSize = 5;
	changeFontSize(f.get(), newFontSize); // 명시적 변환
	changeFontSize(f, newFontSize); // 암시적 변환
	return 0;
}