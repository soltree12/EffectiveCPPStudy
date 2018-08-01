/*
(Non-Excutable)
항목23) 멤버 함수보다는 비멤버 비프렌드 함수와 더 가까워지자
1. 멤버 함수보다는 비멤버 비프렌드 함수를 자주 쓰도록 합시다. 캡슐화 정도가 높아지고, 패키징 유연성도 커지며, 기능적인 확장성도 늘어납니다.
*/

class WebBrowser {
public:
	void clearCache();
	void clearHistory();
	void removeCookies();

	/* 
	캡슐화의 관점으로 보았을 때, 덜 좋은 코드 (어떤 데이터를 접근하는 함수가 많으면 그 데이터의 캡슐화 정도는 낮다.) 
	void clearBrowser(){
		clearCache();
		clearHistory();
		removeCookies();
	}
	*/
};

/* 캡슐화의 관점으로 보았을 때, 더 좋은 코드(비멤버 비프렌드 함수) */
void clearBrowser(WebBrowser& wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}

/* 
* 편의 함수를 작성 할 때는, 분류에 따라 헤더를 나누어 선언하면 편하다.(namespace는 동일하게)
( Webbrowser에 관련된 기능 -> Webbrowser.h 헤더 등) 
*/