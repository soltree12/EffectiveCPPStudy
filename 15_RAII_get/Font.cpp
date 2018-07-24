#include <iostream>

enum class FontHandle {NANUM, GOTHIC, ARIAL};

FontHandle getFont()
{
	return FontHandle::GOTHIC;
}

void releaseFont(FontHandle fh)
{
}

class Font { // RAII Ŭ����
public:
	explicit Font(FontHandle fh) : f(fh) {}
	~Font() { releaseFont(f); }
	FontHandle get() const { return f; } // ����� ��ȯ �Լ�(Font ��ü�� FontHandle�� ��ȯ)
	operator FontHandle() const { return f; } // �Ͻ��� ��ȯ �Լ�(Font ��ü�� FontHandle�� ��ȯ)
		
private:
	FontHandle f; // ���� �ڿ�
};

void changeFontSize(FontHandle f, int newSize) // Font�� ����ϴ� �Լ�
{
	std::cout << static_cast<int>(f) << "/" << newSize << std::endl;
}

int main_2()
{
	Font f(getFont());
	int newFontSize = 5;
	changeFontSize(f.get(), newFontSize); // ����� ��ȯ
	changeFontSize(f, newFontSize); // �Ͻ��� ��ȯ
	return 0;
}